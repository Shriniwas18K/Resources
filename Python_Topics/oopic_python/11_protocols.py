# Duck typing for dynamic polymorphism if something 
# walks like duck quacks like a duck then it must 
# be a duck. Any type object can be used in a
# context as long as it behaves as the way context
# expects i.e. it has all the data members and 
# methods used on it inside that context. Though
# we can enforce type checking here using Protocols
# and type checkers like MyPy. Any object can be
# used in a context if it obeys Protocol defined,
# when passed as arguement then it should have
# all methods supported by type or that parameter
# which can be a Protocol. Protocols dont account
# for members, but account for only methods. More 
# clearly, these are a way of making interfaces
# in Python. We can enforce runtime checking but 
# it checks only if method names are same in Protocol
# and the passed object as arguement. But works well
# checking method return types,method param types
# with static type checkers. For perfect static 
# and runtime type checking we should prefer using
# abstract base classes rather than Protocols.
# More discussion later in the interfaces article.

# Python typing system is built on Protocols,
# each protocol has dunder methods. Complying
# protocols, our objects can interact with 
# builtins of Python.

from typing import Protocol,Any,runtime_checkable

@runtime_checkable
class Drivable(Protocol):
    def drive(self)->Any:...

class Bike:
    def drive(self)->Any:
        print("Driving on a bike.")
class Car:
    def drive(self)->Any:
        print('Driving in a car.')

def drive(drivable: Drivable)->None:
    drivable.drive()
    
drive(Car())
drive(Bike())
