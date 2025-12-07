"""
properties are used for computed attributes and getter setter
1) amount is computed property below everytime someone tries to access it
2) private member is property below that is added only when someone sets it,else not found
"""
class Item:

    def __init__(self):
        self.price = 1000
        self.discount = 10
        # it is optional to declare attributes here, we can even declare in
        # any other instance method too, like done in setter below
        # the properties declared here are initialized at time of construction by this method execution

    @property
    def amount(self):
        return self.price*(1-self.discount/100)

    # getters and setter and outside will see diffirent name of 
    # private member as seen below

    @property
    def private_optional_member(self):
        return self._private_member 
        # if setter not executed earlier then error
        # the setter dynamically adds _private_member property to instance
    
    @private_optional_member.setter
    def private_optional_member(self,val):
        print("validated value")
        self._private_member = val

item = Item()
#print(item.private_optional_member) # gives error not found
item.private_optional_member = "description optional"
print(item.private_optional_member)