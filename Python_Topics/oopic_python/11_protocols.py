"""
these are interfaces of python and can be enforced
when static type checking with mypy is done.
"""
from typing import Protocol,Any

class Runnable(Protocol):
    def run(self)->Any:...

class Car:
    def run(self)->Any:
        print('car is travelling')

def execute(runnable: Runnable)->None:
    runnable.run()