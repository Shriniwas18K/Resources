"""
python usually saves attributes in dictionaries like __dict__
which are geared towards fast access and not towards saving memory

And in case of lot of small objects its signifcant increase

slots will save 50-60% memory, only for instance attributes

but we cannot dynamically attributes to slotted classes,
and slots cannot contain property and class level attributes
"""
import tracemalloc
from typing import Any # to track memory usage

class Car:
    __slots__=['a','b','c','d','e']
    #e = "class level attribute" not allowed as its in slot
    def __init__(self):
        self.a=""
        self.b=""
        self.c=""
        self.d=""
    
tracemalloc.start()
cars=[Car() for i in range(100)]
current,peak = tracemalloc.get_traced_memory()
print(current/1_000_000,"mb",peak/1_000_000,"mb")