# the __init_subclass__ hook

# to perform any tasks on subclass just
# after its creation,like adding members
# dynamically or registering in some registry
# can be done using __init_subclass__. 
# test or utility classes may not register,
# which shows power of this hook.

# it differs from metaclasses as it doesnt
# require anything related to them, and they
# act before subclass creation. __new__
# and __init__ methods of metaclass create subclass.

# Example: Extensible Plugins architecture
# we will allow creating new plugins by subclassing
# abstract base plugin, and making concrete classes.
from abc import ABC,abstractmethod
from typing import ClassVar, Any
from copy import deepcopy
import inspect
import time

class PluginBase(ABC):
    registry: ClassVar[list[type("BasePlugin")]] = [] # static
    
    def __init_subclass__(cls: Any, * , register: bool = True,
        **kw) -> None:
            if register:
                # some custom validation logic for subclass to be valid
                if not inspect.isabstract(cls) and getattr(
                    cls, "priority", None
                ) is not None:
                    PluginBase.registry.append(cls)
                # this cls is subclass
                PluginBase.registry.sort(
                    key = lambda cls:getattr(cls, "priority", 100))
    @abstractmethod
    def execute(self, payload: dict[str, Any]) -> dict[str, Any]:
        pass

class BasePlugin(PluginBase):
    @abstractmethod
    def transform(self, payload: dict[str, Any]) -> dict[str, Any]:
        raise NotImplementedError
    
    def execute(self, payload: dict[str, Any]) -> dict[str, Any]:
        return self.transform(payload)

class UpperCasePlugin(BasePlugin):
    priority = 1
    def transform(self, payload: dict[str, Any]) -> dict[str, Any]:
        result = deepcopy(payload)
        for key in payload:
            if payload[key] is not None and isinstance(payload[key],str):
                result[key] = result[key].upper()
        return result

class TimeStampPlugin(BasePlugin):
    priority = 10
    def transform(self, payload: dict[str, Any]) -> dict[str, Any]:
        result = deepcopy(payload)
        for key in payload:
            if payload[key] is not None and isinstance(payload[key],str):
                result[key] = result[key] + str(time.time())
        return result

class UtilityPlugin(BasePlugin,register = False):
    def __repr__(self):
        return repr(PluginBase.registry)
        
payload = {
    "hello" : "world"
}
for plugin in PluginBase.registry:
    payload = plugin().transform(payload)
    print(payload)