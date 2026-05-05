"""
Everything is object in Python. Metaclasses are used to
create classes in Python.

type is magical thing in python, it is
1) used to create new types
2) itself a type
3) inspect type of object

we will use metaclasses to intercept class creation
similar to how we use class to intercept the instance creation.

this way we can set structure how classes will be, how many
methods will they have,how many attributes they have etc

See from object perspective:
1) __new__ runs code before memory allocation of object i.e. object creation
2) object creation is memory allocation, in other languages members are attached at this time because they are statically typed, whereas Python is dynamically typed fully object oriented hence monkey patching is possible hence as convention members are initialized in __init__, but before it methods and class members are attached to the instance.
3) __init__ runs codes after object creation to initialize object i.e. constructor. This provides thus help to declare instance members in __init__.

object class is implicitely added in mro of every instance of the classes, but not added in classes themselves created by using custom metaclasses.
"""
class Happy:...
print(type(Happy))
print(type(Happy()))

from datetime import datetime

class CustomMeta(type):

    def __new__(mclass,name,bases,mapping):
        # intercept new class creation
        # mclass = CustomMeta
        # name = classname for creation of new class
        # bases= the inheritance hierarchy of the new class
        print(f"new class is creation started with name = {name}")
        return type.__new__(mclass,name,bases,mapping)

    def __init__(cls,name,bases,mapping):
        # intercepting new class initialization
        # linking of attributes and methods to it
        print(f"new class {name} created, initializing")
        return type.__init__(cls,name,bases,mapping)

class Robot(metaclass=CustomMeta):
    attribute='value'
    def __new__(cls,*args,**kwargs):
        # intercepting instance creation
        print("Robot instance creation started")
        return super().__new__(cls)
    def __init__(self,*args,**kwargs):
        # intercepting instance initialization
        print("Robot instance created,initializing it")

walle=Robot()
print()
print()
print(type(Robot)) # <class 'CustomMeta'>
print(type(walle)) # <class 'Robot'>
print(Robot.__mro__) # <class 'Robot' , class 'object'>
