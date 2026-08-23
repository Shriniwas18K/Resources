# the __init_subclass__ hook

# Often told as metaprogramming part, it is not
# related to metaclasses. Its rather hook thats 
# called just after subclass is created, in the
# ancestry class where its defined. We can give
# arguements during subclass declaration and 
# capture them here, like register.

# metaclass methods __new__,__init__ are called
# before subclass creation, if custom meta class 
# is involved. and they create and initialize 
# subclass. Thats only part of metaclasses here.

# we can use it to perform any tasks on subclass 
# just after its creation, like adding members 
# dynamically or we can register it in some
# registry using __init_subclass__.Test or 
# utility classes may not register using
# attribute register=False, which shows 
# power of this hook.

# Example: Extensible Plugins architecture
# we will allow creating new plugins by 
# subclassing abstract base plugin, and 
# making concrete classes.

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