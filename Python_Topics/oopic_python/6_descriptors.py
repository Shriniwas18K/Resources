"""
descriptors live on class level, they are tricky 
to work with and pydantic etc libs use for validation

They are most under utilized feature of Python and can
customize attribute access.

descriptors having __set__,__delete__ defined are data 
descriptors, and they are usually @property,ORM fields.

descriptors not having __set__,__delete__ are non-data 
descriptors, and they are usually methods of any kind.

_storage is used to prevent infinite recursion in 
getattr() and object.__setattr__() methods

How descriptor works by standard conventions:

When class having descriptor attribute is defined
1] __init__ of descriptor invokes
2] __set_name__ of descriptor invokes passing 
   the class and attribute name as parameter.
which stores the attribute name in self._name of descriptor.
They even handle public,__private,_protected,__builtin__ 
attributes as name mangling(for __private) happens before 
passing attribute name as parameter for private attributes. 
The descriptor itself stores the underlying attribute on the 
instance as protected member of that instance to prevent 
unauthorized access of that attribute on the instance.

When attribute having descriptor
1) is accessed at class level then it should return the
   descriptor itself, hence no class level attribute value
   is stored, attribute values are only instance level.
2) is accessed at instance level then it should return the
   value if attribute is initialized, else default value.
to handle normal & slotted instances(dont have __dict__)
we use getattr()

When setting attribute we need to use object.__setattr__(), 
which is actually method used by = operator internally. We
can set attribute values only at instance level, not class level.

When deleting attribute we need to use object.__delattr__(),
which is used by del statement internally.
"""
from typing import Any

class LoggedAttribute:

    def __init__(self, default: Any|None = None):
        self._name = ""
        self._storage = ""
        self._default = default

    def __set_name__(self, owner: Any,
            name: str) -> None:
        print(f"class {owner} is defining attribute \
                {name} using descriptor")
        self._name = name
        self._storage = f"_{name}"

    def __get__(self, inst: Any|None = None, 
            owner: Any|None = None) -> Any:
        if inst is None:
            print(f"class level attribute access of \
                    {self._name} on {owner}")
            return self
        print(f"instance level attribute access of \
                {self._name} on {inst}")
        # any access control logic goes here
        return getattr(inst, self._storage, self._default)

    def __set__(self,inst: Any, value: Any) -> None:
        print(f"setting attribute {self._name} value\
                to {value} on {inst}")
        # any access control and validation logic goes here
        object.__setattr__(inst, self._storage, value)

class A:
    __demo = LoggedAttribute() # private attribute 
    # name mangled _classname prefixed

a = A()
a._A__demo = "hello"
print(a._A__demo)
print(A._A__demo)