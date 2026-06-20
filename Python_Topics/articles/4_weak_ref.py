# weakref module is available with standard library.
"""
weakref is used for automated cleaning caches.

By default we have every variable pointing to
any object is strong ref hence it increments
reference count of the object. The object can
be reclaimed from memory if its reference
count reaches zero.

If we want to access an object if its available
though not prevent it from being garbage collected 
which is perfect for caches then we use weakref.
It allow to reference any object without preventing
it from garbage collection, this is perfectly useful 
when caching or braeking circular references.

slotted classes need to exclusively have __weakref__
for using weakref else its disabled.

weakref can be only made to custom types, not builtin
types like list, tuple, dict, set.

weakref provides proxy which raises ReferenceError if
underlying object doesnt exist.

We also have specialized containers like WeakKeyDictionary,
WeakValueDictionary, WeakSet which automatically remove
entries when the referenced keys/values are garbage collected.

we can run custom cleanup method on object during its
finalization i.e before garbage collection using weakref.
It is not registered on the class rather its on instance.

It is pythonic way of memory management and smart pointers like cpp.
"""

import weakref
import gc

class MyClass:
    __slots__=('data','__weakref__')
    def __init__(self):
        self.data=18
    def cleanup(self):
        print("cleaned")

obj = MyClass()

weak_ref = weakref.ref(obj)
finalizer = weakref.finalize(obj,obj.cleanup)

print(weak_ref())

del obj
gc.collect()

print(weak_ref()) # needs to be called

obj = MyClass()
proxy_ref = weakref.proxy(obj)
print(proxy_ref.data))

del obj
gc.collect()

try:
    print(proxy_ref.data) # proxy doesnt need to be called
except ReferenceError as e:
    print(str(e))

from weakref import WeakValueDictionary

weak_value_dict: dict[str, weakref.ReferenceType] = WeakValueDictionary()
obj = MyClass()
weak_value_dict["key"] = obj # weakref.ref(obj) called inside
print("before GC", *weak_value_dict.items()) # above entry
del obj
gc.collect()
print("after GC", weak_value_dict) # empty
