# Decorators are powerful design pattern as well
# as heavily used Python feature. Though many 
# decorators have these common issues:
# 1] lose function metadata
# 2] break type checking
# 3] lack configurability

# Production grade decorators are 
# 1] preserve function identity: functools.wraps
#    decorator copies passed function metadata
#    like __doc__,__annotations__,__module__,
#    to the wrapper function which helps IDEs,
#    debuggers to demystifying during execution.
# 2] type safe: using ParamSpec, Concatenate,
#    Callable from typing, where ParamSpec 
#    indicates *args, **kwargs of method, 
#    and Concatenate is used for fixed args 
#    of method, where method is Callable.
# 3] configurable: further instead of single
#    hard coded decorator, we can make factory
#    function returing decorators configured
#    to given parameters like handling only 
#    certain exceptions.

# Consider a retry decorator for network operation
# A naive implementation may catch all exceptions 
# and retry indefinitely, which could hide beneath
# permanent crashes or overhelm the underlying 
# n/w service like DDOS. To prevent that add
# 1] exponential backoff to reduce load on 
#    overwhelmed systems by flood of requests.
# 2] selective exception handling to distinguish
#    from transient and permanent crashes.
# 3] jitter to prevent synchronized retry storms.
# 4] preserved function identity for debugging
#    function data correctly.
# 5] type safety for type checkers to understand
#    decorated function.
# This makes production grade implementation.

# Decorator factories and thundering herd problem

# Basically we create decorator factory through
# which get custom configured retry decorators.
# 1] wraps(func) gets the applied function
#    metadata inside decorator for debugging
# 2] * is made in factory function so all users
#    write keyword based config param-value pairs 
#    while creating a decorator.
# 3] the temporary exceptions or transient  
#    crashes which we want to be handled while 
#    retrying are passed during creation of 
#    decorator in the factory method. Entering
#    info and retryable boolean instance member
#    makes it useful of why should retry occur.
# 4] also additionally when we want only some
#    custom exceptions to be handled based on some
#    custom logic then we can pass predicates.
# This is way of externalizing configuration like
# Spring Boot does. In full fledged framework the
# config will be some YAML/XML/JSON file which 
# will be parsed using some Serializer and 
# injected into such decorator factory function.
# Thus inversion of control occurs in factory.

# Exponential backoff: each subsequent retry will
# wait longer than previous one.
#   base_delay = initial_delay*(backoff**attempt)
# This reduces chances of flooding requests.

# Jitter adds randomness to prevent thundering
# herd problem. It occurs when multiple clients or
# processes are waiting for an resource to be
# released and once resource is available then all
# race for that resource. There are many jitter
# strategies for load distribution and latency.
# This is in system design.

def naive_retry(func):
    def wrapper(*args,**kwargs):
        for attempt in range(3):
            try:
                return func(*args,**kwargs)
            except:
                if attempt == 2:
                    raise
                time.sleep(1.0)
        return None
    return wrapper

from typing import (
    Callable
    ,ParamSpec
    ,Concatenate
    ,TypeVar
)
from functools import wraps
from random import uniform

P = ParamSpec("P")
T = TypeVar("T")

def ProdRetryFactory(
    *,
    retries: int = 3,
    delay: float = 0.05,
    backoff: float = 2.0,
    jitter: float = 0.2,
    exceptions: tuple[type[BaseException],...] =
        (Exception,),
    predicate: Callable[[BaseException],bool] | 
    None = None,
) -> Callable[P,T]:
    
    
    def getDecorator(func: Callable[P,T]) 
    -> Callable[P,T]:
        
        @wraps(func)
        def wrapper(
            *args: P.args,**kwargs: P.kwargs
        ) -> T:
        
            attempt = 0
            while True:
                try:
                    # can access function metadata
                    # for debugging and inspection
                    print(f"Execution begins: {\
                        func}")
                    res = func(*args,**kwargs)
                    print(f"Execution completed:{\
                        func}")
                    return res
                except exceptions as e:
                    if predicate is not None and\
                    predicate(e):
                        raise
                    if attempt >= retries:
                        raise
                    base = delay * (\
                           backoff ** attempt)
                    sleep_for = base
                    if jitter != 0:
                        sleep_for += uniform(0,\
                            base*jitter)
                    time.sleep(max(0,sleep_for))
                    attempt += 1
                    
        return cast(Callable[P,T],wrapper)
    return getDecorator

class Error(Exception):
    def __init__(self,msg:str) -> None:
        super().__init__(msg)
        self.retryable = False
        
class TransientError(Error):
    def __init__(self,msg:str) -> None:
        super().__init__(msg)
        self.retryable = True
        
class PermanentError(Error):
    def __init__(self,msg:str)->None:
        super().__init__(msg)

TooManyRequests = TransientError("329 Too many \
    requests. Pls try after some time.")

UnAuthorized = PermanentError("401 UnAuthorized.")

# The decorator gets applied on below function
retryGetWeather = ProdRetryFactory.getDecorator(
    retries = 3, 
    exceptions = (TooManyRequests),
    predicate = lambda e: getattr(\
                        e,"retryable",True)
    )

@retryGetWeather
def getWeatherFromWeatherAPI(city: str = "Pune"):
    import requests
    import json
    try:
        res = requests.get(\
        f"https://openweatherapi.com/?city={city}"
        ) # type: ignore
        return json.loads(res)["weatherInDegrees"]
    except e:raise e
    
    
    
    
    