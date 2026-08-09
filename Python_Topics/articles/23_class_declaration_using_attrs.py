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
