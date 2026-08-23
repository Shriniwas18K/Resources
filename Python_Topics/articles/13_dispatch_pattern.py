# Python supports method overloading by options
# 1)use isinstance and type check the args at 
#   runtime inside the same function and provide
#   diffirent implementations.
# 2)functools.singledispatch,singledispatchmethod
#   with typing library and dispatch pattern.

# functools.singledispatch decides which impl to
# invoke based on first non-cls non-self type of
# the function. However it oesnt handle second or
# other types. without typing we can pass the
# first type in the register function.

# for classes which have self,cls etc args we use
# functools.singledispatchmethod which considers
# first diffirent arg than these for resolving
# implementations.

def naive_report(value1,value2):
    if type(value1) == int:...
    elif type(value1) == str:...
    elif isinstance(value1,dict):...
    
from functools import singledispatch
@singledispatch
def report(value1,value2):...

@report.register(int)
def _(v1,v2=10):
    print("hello world")
    
@report.register(str)
def _(v1,v2=18):
    print("bonjour")
    
report(37)
report("abc")

for key,value in report.registry.items():
    print(key,value)

# However when using typing library we can have
# powerful dispatch pattern coming into picture.
# It eliminates the need to handle long tightly
# coupled isinstance and type checks at runtime
# which voilate OCP(Open/Closed Principle) i.e.
# to add any new functionality ensure old doesnt
# break and tight coupling makes it cubersome.
# Hence to promotes extensibility and type 
# awareness we use Dispatch Pattern. Consider 
# example of JSON Serializer.

# The first parameter type is checked with the 
# types and thier implementations registered in
# thier registry. If none of them matches then
# fallback to default implementation raising
# type error. It is better than returning None
# thus user gets notified at the spot. Also
# they shine when serializing custom types
# keeping serialization logic outside class 
# thus clear sepration of concerns. Users 
# wanting to extend the serializer for their
# own types can register thier implementations. 

# Custom Types and Containers can store primitive 
# builtin types like int,str,bool,float which are
# already JSON Serializable hence we need helper
# function to serialize which delegates to
# to_json_serializable only for non-JSON
# Serializable types which later dispathces to
# the appropriate registered implementation based
# on the object's type. The stored data must
# also be serialized hence recursive calls to
# serialize are required.

# List,Tuples,Sets,FrozenSets need to be converted
# to lists for JSON Serializability. To support 
# multiple types to have same handler apply
# multiple decorators.

from dataclass import dataclass
from datetime import datetime
from decimal import Decimal
from typing import Any
from json import dumps

@dataclass(frozen=True,slots=True)
class Money:
    amount: Decimal
    currency:   str

@singledispatch
def to_json_serializable(obj: Any) -> Any:
    # Default implementation: if none of
    # registered implementations match
    raise TypeError(f"Unsupported type: {type(obj)
    \.__name_))}")
    
@to_json_serializable.register
def _(obj:Decimal) -> str: 
    # _ signals for singledispatch
    return str(obj)
    
@to_json_serializable.register
def _(obj:datetime) -> str:
    return obj.isoformat()
    
@to_json_serializable.register
def _(obj:Money) -> dict[str, Any]:
    return f"""{{ 
    "amount":{serialize(obj.amount)}, 
    "currency":{serialize(obj.currency)
    }}"""

@to_json_serializable.register(set)
@to_json_serializable.register(list)
@to_json_serializable.register(tuple)
def _(obj:list[Any]|tuple[Any]|set[Any]) 
    -> list[Any]:
        return [serialize(x) for x in obj]

def serialize(obj: Any) -> Any:
    if obj is None or isinstance(obj,(bool,int,\
    str,float)):
        return obj
    return to_json_serializable(obj)
    
payload = {
    "id" :42,
    "when":datetime.now(),
    "total":Money(24.02,"INR"),
    "tags": {"vip","new"},
    "stocks":["APPL","MSFT"],
    ("tuple","key"):("value","val")
}

print(dumps(serialize(payload)))