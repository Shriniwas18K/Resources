# locals() returns dict containing all variables in that scope block.
# vars(object) returns copy of __dict__ of the object
# vars() returns dict containing all variables in the scope block.
# globals() returns all the module level variables.
"""
{'name': 'Samsung galaxy s21 ultra', 'price': 72}
{'Product': <class '__main__.Product'>,
    .
    .
    .
 'func': <function func at 0x000001D28D11A340>,
 'pprint': <function pprint at 0x000001D28D3FDC60>,
 'samsung_mobile': <__main__.Product object at 0x000001D28D3F5C10>,
 'temp': 18}
{'fn': <function func.<locals>.fn at 0x000001D28D3BEFC0>,
 'gn': <function func.<locals>.gn at 0x000001D28D589E40>,
 'temp': 37}
{'Product': <class '__main__.Product',
    .
    .
    .
 'func': <function func at 0x000001D28D11A340>,
 'pprint': <function pprint at 0x000001D28D3FDC60>,
 'samsung_mobile': <__main__.Product object at 0x000001D28D3F5C10>,
 'temp': 108}
{'fn': <function func.<locals>.fn at 0x000001D28D3BEFC0>,
 'gn': <function func.<locals>.gn at 0x000001D28D589E40>,
 'temp': 1008}
"""
from pprint import pprint

temp = 18

def func():

    temp = 37

    def fn():
        global temp
        temp = 108
    def gn():
        nonlocal temp
        temp = 1008

    pprint(globals())
    pprint(locals())

    fn()
    gn()

    pprint(globals())
    pprint(locals())

class Product:
    def __init__(self,name,price):
        self.name = name
        self.price= price

samsung_mobile = Product("Samsung galaxy s21 ultra",72)

pprint(vars(samsung_mobile))

func()  
