"""
descriptors live on class level, they are tricky 
to work with and pydantic etc libs use for validation

raymond hettinger has wrote tutorial on using them
"""

class Validator:
    def __get__(self,inst,cls):
        if inst is None:
            print("class level attribute access")
            return cls.__dict__[self.attribute_name]
        print("instance level attribute access")
        if self.attribute_name not in inst.__dict__.keys():
            print("attribute wasnt initialized at instance level")
            return
        return inst.__dict__[self.attribute_name]

    def __set__(self,instance,value):
        print(f"setting {self.attribute_name} value to {value}")
        instance.__dict__[self.attribute_name]=value

    def __set_name__(self,owner,name):
        print("instance is initializing the attribute ",name)
        self.attribute_name=name

class A:
    demo=Validator()

a=A()
a.demo="hello"
b=A()
print(a.demo)
print(b.demo)
print(A.demo)