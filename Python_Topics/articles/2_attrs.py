# Some people have habit of declaring instance
# members in the class body rather than __init__()
# because its common practice in other OOPic 
# languages like Cpp, Java wherein we declare
# members in body of class and initialise them
# inside constructors, hence be aware of cavaet
# given below. This is the mechanism behind dataclasses.

class Rocket1:
    fuel: int = 10
    engine: str = "PSLV"
    # due to value assignment the class __dict__
    # gets them as class attributes/members
    
class Rocket2:
    fuel: int
    engine: str
    # as value isnt assigned above are treated
    # as annotations or declarations by static
    # type checkers which are to be initialized
    # in __init__(), hence they become instance
    # members in the instance __dict__
    def __init__(self):
        self.fuel = 18
        self.engine = "PSLV"
        
from pprint import pprint    
r1 = Rocket1()
pprint(Rocket1.__dict__) # gets fuel and engine
pprint(r1.__dict__)# empty 
r2 = Rocket2()
pprint(Rocket2.__dict__) # doesnt have fuel engine
pprint(r2.__dict__) # has fuel and engine

"""
mappingproxy({'__annotations__': {'engine': <class 'str'>,
                                  'fuel': <class 'int'>},
              '__dict__': <attribute '__dict__' of 'Rocket1' objects>,
              '__doc__': None,
              '__module__': '__main__',
              '__weakref__': <attribute '__weakref__' of 'Rocket1' objects>,
              'engine': 'PSLV',
              'fuel': 10})
{}
mappingproxy({'__annotations__': {'engine': <class 'str'>,
                                  'fuel': <class 'int'>},
              '__dict__': <attribute '__dict__' of 'Rocket2' objects>,
              '__doc__': None,
              '__init__': <function Rocket2.__init__ at 0x7eae64cf4220>,
              '__module__': '__main__',
              '__weakref__': <attribute '__weakref__' of 'Rocket2' objects>})
{'engine': 'PSLV', 'fuel': 18}
"""

# The declaring of instance members in class body can
# be acheived using attrs library which is written below.

# attrs is builtin library that allows class declaration
# similar to Java CPP style in class body
# @define: creates __init__,__repr__,__eq__
# field(): used to set defaults,factories,validators
# validators can be lambdas or functions, raise exceptions if not valid
# type hints are enforced at runtime only if we use validators, else only static type checkers will catch type voilations
# @frozen: for declaring immutable instances
# Great for clean maintainable APIs


from attrs import define,field,validators
from typing import List

@define
class Person:
    # Attributes declared in class body
    name: str = field(validator = lambda self,_,value: (isinstance(value,str) or ( _ for _ in () ).throw(ValueError("name must be a string")
                                                                                                         ))
                      )
    # Above is naive way of declaring validator
    # we can use the validators library for same
    full_name: str = field(validator=validators.instance_of(str))

    age: int = field(default = 0,
                validator = [
                    validators.instance_of(int),
                    validators.ge(0) # age >= 0
                         ])
    hobbies: List[str] = field(factory = list)

p = Person(name = "Ram", age = 30, hobbies = ["reading","cycling"])

print(f"{p=}")

