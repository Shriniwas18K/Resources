# Suppose we have one User dataclass and we want to serialize
# users to diffirent formats, YAML, JSON, ...

# naive approach will be adding serialize method and ladder
# checks and Format wise logic in it

# naive approach voilates Open/Closed principle as everytime 
# when we need to add support for new Format then we need to
# modify and touch this class and all others using it will
# get affected, and this serialize() method will soon grow
# into big bloat of logic that needs to be chunked, and all
# those using this serialize() method will need to make the
# changes in their code. 

# OCP says anything(class specifically) should be open to
# extension but closed for modification.

# thus we use SerializerStrategy Protocol that allows users to create
# their own Serializers with custom formats and logic and
# dependency inject them without any inheritance mandates
# and prevents us from hardcoding any logic.
# This is stratergy design pattern.

# This can still be further optimised to the use case.

from typing import Any,Protocol
class SerializerStrategy(Protocol):
    def serialize(self,objdict: dict[str,Any])->str:...

from dataclasses import dataclass,asdict

@dataclass
class User:
    name: str
    age: int

    # naive approach
    # def serialize(self,Format: str)->str:
    #    if(Format == "JSON"):
    #        ...
    #   elif(Format == "YAML"):
    #       ...
    #   ...

    # Dependency Injection approach
    def serialize(self,serializer: SerializerStrategy)->str:
        return serializer.serialize(asdict(self))

import json
# users can create their own serializer classes and use DI
class JSONSerializer:
    def serialize(self,objdict: dict[str,Any])->str:
        json_str = json.dumps(objdict)
        return json_str

user = User(name="Shri",age=22)
print("JSON Serialized")
print(user.serialize(JSONSerializer()))
