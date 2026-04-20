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
