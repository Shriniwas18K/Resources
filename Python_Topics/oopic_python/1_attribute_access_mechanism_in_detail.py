"""
Attribute access mechanism in detail:

Whenever we call attribute on any object using obj.attr
syntax then following mechanism triggers in the
CPython code at https://github.com/python/cpython/blob/ccf94a6289c722f56000ffed5dd416371127c759/Objects/object.c#L1242

Its actual code from Objects.c from CPython is for
understanding is written here where in // are 
comments written by us for understanding. 

The equivalent Python/PSEUDO code for easier
understanding is written first for smooth
understanding of the descriptors concept.
"""

"""
class object:

    def __getattribute__(self,attr):
    
        if attr has __get__(),__set__()
        and __delete__() then its data
        descriptor:
            return attr.__get__()
            # @property,ORM fields come here
        else:
        
            if attr in self.__dict__.keys():
                # attr is instance member then 
                # return its value
                return self.__dict__[attr]
                # thus instance attributes
                # and instance methods are here
                
            else:
            
                if attr in __dict__ of the
                class or classes in __mro__:
        
                    # attr is something class level
                    
                    if attr has only __get__()
                    and not __set__()/__delete__():
        
                        # its non data descriptor
                        return attr.__get__()
                        # static and class 
                        # methods come here
                        
                    else:
                        # its not descriptor
                        # its plain class attribute
                        return self.__class__.__dict__[attr]
                        
                else:
                    return self.__getattr__(attr)
"""


"""
PyObject *
_PyObject_GenericGetAttrWithDict(PyObject *obj, PyObject *name,
                                 PyObject *dict, int suppress)
{
    /* Make sure the logic of _PyObject_GetMethod is in sync with
       this method.

       When suppress=1, this function suppresses AttributeError.
    */
    
    // obj.attr syntax gets converted from python
    // to C here where they come as PyObjects
    //      obj is obj
    //      attr is name
    //      __dict__ of obj is dict which if
    //              not given as arg then 
    //              initialized later if needed

    // get the class of the obj of which it 
    // is the instance of, as the descriptors
    // live on class level
    PyTypeObject *tp = Py_TYPE(obj);
    
    PyObject *descr = NULL;
    PyObject *res = NULL;
    descrgetfunc f;

    // check if characters in the attr in Python 
    // i.e. name here are of unicode string in UTF8

    if (!PyUnicode_Check(name)){
        PyErr_Format(PyExc_TypeError,
                     "attribute name must be string, not '%.200s'",
                     Py_TYPE(name)->tp_name);
        return NULL;
    }
    
    // increase reference count of attr as it is 
    // accessed from someone
    Py_INCREF(name);

    // if the obj is instance of NoneType i.e. 
    // None then below if loop triggers
    if (tp->tp_dict == NULL) {
        if (PyType_Ready(tp) < 0)
            goto done;
    }
    
    descr = _PyType_Lookup(tp, name);
    // This looks up any attribute in class/MRO, 
    // not just descriptors descr can be:
    //      data descriptor
    //      non-data descriptor
    //      normal class attribute
    //      or NULL (not found)
    // If its descriptor is checked below
    
    f = NULL;
    if (descr != NULL) { 
        
        // things exist at class level hence here

        Py_INCREF(descr);
        f = Py_TYPE(descr)->tp_descr_get;
        // check if attr is data descriptor and
        // has __get__() defined onto it
        
        if (f != NULL && PyDescr_IsData(descr)) {
        
            // yes attr is data descriptor means 
            // its has __set__(),__delete__(),
            // __get__() as f is not null
            // so below line invokes the
            // __get__() method and stores result
            // in the res variable, which is
            // returned from this function at the
            // done label at end of this function.
            
            res = f(descr, obj, (PyObject *)Py_TYPE(obj));
            
            if (res == NULL && suppress &&
                    PyErr_ExceptionMatches(PyExc_AttributeError)) {
                PyErr_Clear();
            }
            goto done;
        }
    }
    // if attr is not data descriptor rather
    // its rather non data descriptor or class 
    // level attributes in mro or class itself
    // hence still we need its __get__() method 
    // which gets stored in above f variable
    
    // data descriptors lookup occured above 
    // before the __dict__ lookups below hence
    // they override the instance members of
    // same name.
    
    // below if loops simply checks if attr is in
    // the instance i.e. obj's __dict__
    
    if (dict == NULL) {
        
        // if __dict__ of the obj was not given 
        // as arg to this function then here
        
        if ((tp->tp_flags & Py_TPFLAGS_MANAGED_DICT)) {
            
            // the control reaches here in case
            // of slotted classes for whom the 
            // __dict__ is created internally
            // and that too lazily (when required)
            // and not exposed to user hence
            // the above flag comes MANAGED_DICT
            
            PyDictOrValues* dorv_ptr = _PyObject_DictOrValuesPointer(obj);
            if (_PyDictOrValues_IsValues(*dorv_ptr)) {
                
                // if the __dict__ of the slotted
                // class doesnt exist hence 
                // control reaches here
                
                PyDictValues *values = _PyDictOrValues_GetValues(*dorv_ptr);
                // get values from __slot__ of obj
                
                // as __slots__ contain strs
                // so check if attr/name is utf
                if (PyUnicode_CheckExact(name)) {
                
                    // as its slotted attribute
                    // hence get its value as 
                    // instance attribute
                    res = _PyObject_GetInstanceAttribute(obj, values, name);
                    if (res != NULL) {
                    
                        // if value found then 
                        // return it from this 
                        // function
                        
                        goto done;
                    }
                }
                else {
                
                    // this makes the __dict__
                    // when the class of the 
                    // obj's type is slotted
                    
                    dict = _PyObject_MakeDictFromInstanceAttributes(obj, values);
                    if (dict == NULL) {
                        res = NULL;
                        goto done;
                    }
                    dorv_ptr->dict = dict;
                }
            }
            else {
                // the __dict__ of the slotted
                // class already exists and was
                // made during previous lookups
                // thus use it as it is 
                
                dict = _PyDictOrValues_GetDict(*dorv_ptr);
            }
        }
        else {
            PyObject **dictptr = _PyObject_ComputedDictPointer(obj);
            if (dictptr) {
                dict = *dictptr;
            }
        }
        
    }
    
    if (dict != NULL) {
    
        // from above lazily created __dict__ 
        // of the obj check if attr is in it
        
        Py_INCREF(dict);
        
        res = PyDict_GetItemWithError(dict, name);
        if (res != NULL) {
            
            // yes attr is in __dict__ of obj 
            // hence return the value in res
            
            Py_INCREF(res);
            Py_DECREF(dict);
            goto done;
        }
        else {
            Py_DECREF(dict);
            if (PyErr_Occurred()) {
                if (suppress && PyErr_ExceptionMatches(PyExc_AttributeError)) {
                    PyErr_Clear();
                }
                else {
                    goto done;
                }
            }
        }
    }
    
    // instance __dict__ lookup i.e obj __dict__
    // lookup completed above, next is for 
    // non-data descriptors 
    
    if (f != NULL) {
    
        // even if attr is non data descriptor then
        // too invoke __get__()
    
        res = f(descr, obj, (PyObject *)Py_TYPE(obj));
        if (res == NULL && suppress &&
                PyErr_ExceptionMatches(PyExc_AttributeError)) {
            PyErr_Clear();
        }
        goto done;
    }

    if (descr != NULL) {
        // if attr is plain class member and
        // __get__ is not defined then return 
        // attr i.e. its not descriptor still
        // the descr variable stores it hence
        // return it using res
        res = descr;
        descr = NULL;
        goto done;
    }

    if (!suppress) {
        PyErr_Format(PyExc_AttributeError,
                     "'%.50s' object has no attribute '%U'",
                     tp->tp_name, name);
    }
    
  done:
    Py_XDECREF(descr);
    Py_DECREF(name);
    return res;
}

__getattr__ call is handled outside this method
"""
