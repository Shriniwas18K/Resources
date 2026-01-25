# all attributes starting with __ and not ending with __
# are stored by prefixing _classname to them in __dict__
# this is thus used to make private members
# though can still be accessed using _classname__attrname
class Product:
    __class_level_private_member = "class level private member" # stored in Product class __dict__
    def __init__(self):
        self.__private_member="private member" # stored as _Product__private_member in the instance __dict__

instance = Product()
print(instance.__dict__)
#print(instance.__private_member) errors AttributeError: attribute not found
print(instance._Product__private_member)
#print(instance.__class_level_private_member) errors
print(instance._Product__class_level_private_member)
print(Product.__dict__)