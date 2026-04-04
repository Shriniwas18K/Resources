"""
these are class creation utility

suupose we only allow single class for some purpose in registry
"""
registry={}

class serializer:
    def __call__(self,cls):
        purpose=getattr(cls,'purpose',None)
        if purpose in registry:
            raise Exception('the class for this purpose already exists')
        registry[purpose]=cls
        print(f'registered class {cls.__name__} for the purpose {cls.purpose}')

# function based decorator
def serializer2(cls):
    purpose=getattr(cls,'purpose',None)
    if purpose in registry:
        raise Exception('the class for this purpose already exists')
    registry[purpose]=cls
    print(f'registered class {cls.__name__} for the purpose {cls.purpose}')

@serializer()#class based serializer needs to be called
class JSONSerializer:
    purpose = 'JSON'

@serializer2#if it was class based serializer then this will be __init__ call, as its function based hence direct __call__ is called as it is callable
class YAMLSerializer:
    purpose = 'YAML'

@serializer()
class JSONSerializer2:
    purpose = 'JSON'

# decorators are basically used for wrapping functions, similar to context manager but rather widely used design pattern
def decorator_function(decorated_function):
    def wrapper_function():
        print("Before executing decorated function")
        decorated_function()
        print("After executing decorated function")
    return wrapper_function

@decorator_function
def temp():
    print("Inside the actual function")
