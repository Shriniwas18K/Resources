# duck typing : dynamic polymorphism

# if something walks like duck quacks like a duck
# then it must be a duck

# any object can be used in the context as long as it
# behaves as the context expects i.e. it has all 
# the data members and methods used on it inside the
# context, then it is perfectly valid to use object

# due to dynamically typed nature of Python, if the
# code wasnt ensured to be perfectly correct by
# static typing and type checkers then it needs to be
# tested with coverage of all paths in the code with 
# all possible scenarios because of duck typing.

# Python does provide operator overloading by
# overidding the dunder methods __add__,etc.

# Python supports method overloading by options
# 1)use isinstance and type check the args at 
#   runtime inside the same function and provide
#   diffirent implementations.
# 2)use *args **kwargs varargs approach

# Safer option is use functools.singledispatch which
# decides the implementation to invoke based on first
# non-cls non-self type of the function. However it
# doesnt handle second or other types, i.e. other 
# types can be anything with any default values.
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
    
# for classes which have self,cls etc args we use
# functools.singledispatchmethod which considers
# first diffirent arg than these for resolving
# implementations.

# functional programming

# map cavaet: its iterables are varargs and the 
# function processes the iterable until the smallest
# size index, that too parallely see output
list(map(print,
    ['a','b','c','d'],
    range(3), # smallest size iterable
    [108,18,37,1008]
))
# a 0 108
# b 1 18
# c 2 37
 
# partial functions: dynamic function construction,
# populate the args as per requirement from 
# leftmost to right
from functools import partial
def printer(*args):
    for i in args:
        print(i)
partial_function1 = partial(printer,"hello world")
partial_function2 = partial(
    partial_function1,"bonjour")
concrete_function = partial(
    partial_function2,"ciao")
    
concrete_function()

# python functions are objects hence first class
# functional programming is widely practised with
# the use of itertools and functools modules,
# generators,decorators.
