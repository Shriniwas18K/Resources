# method chaining allows us to chain operations on
# same object, python uses it in map,filter,reduce.

# to make method chaining, the mandate is same object
# at address level must go in and return out from the 
# methods. Any other args can go in but only single 
# object should return from the methods.

# it prevents need of using temp variables that store
# intermediate results, allowing clear view, reducing
# cognitive burden.

class number:
    def __init__(self,n:int):
        self.num = n
    def mul(self,k):
        return self.num*k
    def add(self,k):
        return self.num+k
    def sub(self,k):
        return self.num-k

n = number(10)
temp1 = n.add(5)
temp2 = temp1.mul(10)
res = temp2.div(2)

res = n.\
        add(5).\
        mul(10).\
        div(2)

