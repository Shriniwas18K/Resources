
from enum import Enum,auto,Flag

class WeekDay(Enum):
    Monday = 0
    Tuesday = 1
    Wednesday = 2
    Thursday = 3
    Friday = 4

# if member values 0,1,2,3,4 arent required then use
# builtin type auto()

class Fruit(Flag):
    MANGO=auto()
    APPLE=auto()
    ORANGE=auto()
    AVOCADO=auto()
    BANANA=auto()

# Enums are widely used with bitmasking concepts
# using the Flag type
Indian_Basket = Fruit.MANGO | Fruit.APPLE | \
                Fruit.ORANGE
Latin_Basket = Fruit.AVOCADO | Fruit.BANANA

print(Fruit.MANGO in Latin_Basket)


