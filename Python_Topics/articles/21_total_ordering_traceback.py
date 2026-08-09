# total_ordering, NotImplemented, traceback

# sometimes for custom items which support
# arithmetic operations we need to extend Python
# then we use functools.total_ordering to generate
# all __operator__ methods, if __eq__, and one 
# operator method like say __lt__ is implemented.

# NotImplemented is special constant. It is
# returned not raised. Only for __operator__ methods
# and it is required for total_ordering to work.

# sometimes we need print the error message then
# we use traceback module, it prints at top of execution.
from functools import total_ordering
import traceback

@total_ordering
class Item:
    def __init__(self, price: int = 1000):
        self.price = price
    
    def __eq__(self, other: type("Item")) -> bool:
        if not isinstance(other, Item):
            raise TypeError(
                f"{other} must be of type Item"
            )
        return self.price == other.price
    
    def __lt__(self, other: type("Item")) -> bool:
        if not isinstance(other, Item):
            return NotImplemented
        return self.price < other.price        

item1 = Item(200)
item2 = Item(100)
print(item1 > item2)
print(item1 < item2)
print(item1 < item2)
try:
    print(item1 < "") 
except:
    traceback.print_exc()    
print("executing after printing traceback")