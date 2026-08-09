# decorators and decorator factories

# Many decorators have these common issues:
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

from typing import (
    Callable
    ,ParamSpec
    ,TypeVar
    ,Tuple
    ,cast
    ,Any
)
from functools import wraps


P = ParamSpec("P")
T = TypeVar("T")

def decorator(func: Callable[P, T]) -> Callable[P, T]:
    @wraps(func)
    def wrapper(*args: P.args, **kwargs: P.kwargs) -> T:
        print(f"Before executing {func.__name__}")
        res: T = func(*args, **kwargs)
        print(f"After executing {func.__name__}")
        print(f"{func} metadata was accessible due to wraps")
        return res
    return wrapper

@decorator
def add(a: int,b: int) -> int:
    return a + b

print(add(3,4))

class DecoratorFactory:
    
    def getDecorator(
        *,
        config_param1: str,
        config_param2: str,
        exceptions_handled: Tuple[BaseException]
    ) -> Callable[
        [Callable[P,T]], Callable[P,T]
    ]:
        def decorator(func: Callable[P, T]) -> Callable[P, T]:
            @wraps(func)
            def wrapper(*args: P.args, **kwargs: P.kwargs) -> T:
                try:
                    print(f"Before executing {config_param1}")
                    res: T = func(*args, **kwargs)
                    print(f"After executing {config_param2}")
                    print(f"{func} metadata was accessible due to wraps")
                    return res
                except exceptions_handled as e:
                    print(f"Gracefully handling {e}")
                    return res
            return cast(Callable[P,T], wrapper)
        return decorator

@DecoratorFactory.getDecorator(
    config_param1 = "hello", config_param2 = "world")
def prod(*args: Tuple[int, ...]) -> int:
    res = 1
    for i in args:
        res*=i
    return res
    
print(prod(1,2,3,4))