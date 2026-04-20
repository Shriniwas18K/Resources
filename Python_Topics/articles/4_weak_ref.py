# weakref module is available with standard library.
"""
They allow to reference any object without preventing
it from garbage collection, this is perfectly useful 
when caching or braeking circular references.

slotted classes need to exclusively have __weakref__
for using weakref else its disabled.

We also have specialized containers like WeakKeyDictionary,
WeakValueDictionary, WeakSet which automatically remove
entries when the referenced objects are garbage collected.

we can run custom cleanup method on object during its
finalization i.e before garbage collection using weakref.

It is pythonic way of memory management and smart pointers like cpp.
"""

import weakref

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

print(weak_ref())
