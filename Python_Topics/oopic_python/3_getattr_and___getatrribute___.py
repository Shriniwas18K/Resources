"""
The dunder __getattr__ method is called whenever . operator is used
to access the attribute. If the attribute is property 

The dunder __getattribute__ method bypasses whole
attribute finding mechanism and is invoked when attribute 
is accessed using . operator, causes infinite recursion too
so use with caution

for overridding these methods the signature should remain same as in object class
"""
from typing import Any

class A:
    def __getattribute__(self, __name: str) -> Any:
        print("dunder __getattribute__ bypassed whole mechanism")
        # return self.__dict__[__name] will cause infinite recursion as it contains . operator to access __dict__
    
    @property
    def description(self):
        return "Hello world"
    
    def __getattr__(self,attr):
        print("dunder __getattr__ invoked")
        return self.__dict__[attr]

print(A().description) # getter not invoked due to dunder __getattribute__ which has to invoke that getter