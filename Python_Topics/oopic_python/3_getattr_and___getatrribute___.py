"""
The dunder __getattr__ method of instance is called at
last in attribute finding mechanism before throwing attribute 
error hence we can use it create lazily computed attributes 
similar to properties by overridding it.

The dunder __getattribute__ can be overridden to bypass
entire attribute access mechanism, in order to create proxy classes.
"""
from typing import Any

class Item:
    def __init__(self, price: int = 1000):
        self.price = price

    def __getattr__(self, name: str) -> Any:
        if name == "amount":
            return self.price * 1.1

class Proxy:
    def __getattribute__(self, name: str) -> Any:
        print(f"Proxy: {name} attribute is being accessed on {self}")
        return super().__getattribute__(name)

    def __setattr__(self, name:str , value: Any) -> Any:
        print(f"Proxy: {name} attribute is being set on {self}")
        super().__setattr__(name, value)

class Cloth(Proxy):    
    def __init__(self, price: int):
        self.price = price
        
print(Item().amount)
cloth = Cloth(1000)
print(cloth.price)
cloth.price *= 2
