"""
In big organisations usually custom internal libs
exist with custom datatypes and operations based on need

In python we can create types other that builtin types
For this we have many abstract mixin classes in collections
Inheriting these gives us mixin methods like __len__
and also makes to enfore behavior of certain kind by abstract methods

Core: Iterable,Hashable,Container,Callable,Sized,

Collection made by inheriting Container,Iterable,Sized

Sequence made by inheriting Collection,Reversible

MutableSequence made by inheriting Sequence

If we want to print the binary of some object then use dis module

Sometimes you want custom logic to be implemented when
some key is not found in dictionary, in that case
subclass the dict, and implement __missing__
"""
class AdditionOperator:
    def __call__(self,a,b):
        print(a+b)

add=AdditionOperator()
add(9,9)

from dis import dis
print(dis(AdditionOperator))

class CustomDict(dict):
    def __init__(self,*args,**kw):
        super().__init__(*args,**kw)
    def __missing__(self,key):
        print("handling missing key case")

d=CustomDict()
print(d['missing_key'])