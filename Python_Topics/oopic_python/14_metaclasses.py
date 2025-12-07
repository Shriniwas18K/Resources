"""
classes are blueprint for instances and metaclasses
are blueprint for classes

type is magical thing in python, it is
1) used to create new types
2) itself a type
3) inspect type of object

we will use metaclasses to intercept class lifecycle
similar to how we use class to intercept the instance
lifecycle using methods like __new__,__init__,__call__,__getattr__,__setattr__

this way we can set structure how classes will be, how many
methods will they have,how many attributes they have etc
"""
class Happy:...
print(type(Happy))
print(type(Happy()))

from datetime import datetime

class CustomMeta(type):

    def __new__(mclass,name,bases,mapping):
        #intercept new class creation
        # name = classname
        # bases= the inheritance hierarchy of the class
        mapping['created']=datetime.now()
        print(f'new class is created with name = {name}')
        return type.__new__(mclass,name,bases,mapping)

    def __init__(cls,name,bases,mapping):
        #instance creation
        print(mapping)
        print(f'new instance created for {name}')
        return type.__init__(cls,name,bases,mapping)

    def __call__(cls,*args,**kwargs):
        print(f'creating instance of {cls.__name__}')
        return type.__call__(cls,*args,**kwargs)

class Robot(metaclass=CustomMeta):
    attribute='value'
    # def __new__(cls,*args,**kwargs):
    #     print("Robot instance creation")
    #     return cls(*args,**kwargs)
    def __init__(self,*args,**kwargs):
        print("Robot instance init")
    def __call__(self,*args,**kwargs):
        print("Robot invoked")
    def move(self):
        print('reached at correct destination')

walle=Robot()
walle.move()
print()
print()
print(type(Robot))
print(type(walle))

print(Robot.__mro__)