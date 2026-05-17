# Python has newer support of static type checkers
# hence we can use TypedDict as the best way of writing
# dictionaries adhering to specific schema structure.

# Pydantic and dataclasses are checked at runtime.
# TypedDicts are checked at compile time by type checker.

# by default all fields are mandatory, we can declare
# some fields as optional by adding NotRequired

# we can declare all fields as optional except few
# ones by specifying total=False, Required

# we can declare some field values as immutable
# i.e. can be assigned only once using ReadOnly

# Note: 
# 1_) This will be enforced only type checker at compilation, not at runtime.
# 2_) TypedDicts cannot be inherited or extended hence increases code length
# 3_) we cannot do CRUD breaking the schema of the TypedDict.

from typing import TypedDict,Required,NotRequired
from typing_extensions import ReadOnly

class User(TypedDict):
    name: str
    age : int

user : User = {"name":"sShri","age" :22}

# del user["name"]
# user["hello"]="world"
# both above lines break schema hence static typing errors

class User1(TypedDict,total=False):
    name: str
    age: int
    email: Required[str]

user1 :User1= {"email":"abc@gmail.com"}

class User2(User): 
    phone: NotRequired[str]

user2 :User2= user # static typing errors here as TypedDicts cannot be inherited

class User3(TypedDict,total=False):
    sid: ReadOnly[int]

user3 :User3= {"sid":1}
# user3["sid"] = 10 errors by type checker
