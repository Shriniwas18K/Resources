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
