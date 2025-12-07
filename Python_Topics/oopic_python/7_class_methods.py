"""
Suppose we want to create User from name,password or token
then we can use class methods

class methods are used to create instance of class
using buildFromToken() kind of in builder pattern, where we
cannot initialize complex logic in single init

thus we can have these as alternate constructors
"""
def extract(token):
    _=token.split(",")
    return _[0],_[1]
class User:
    def __init__(self,name,password):
        print("constructor invoked")
        self.name=name
        self.password=password
    # suppose we wish create another user from token
    @classmethod
    def buildFromToken(cls,token):# cls is the A class itself
        ext_name,ext_password=extract(token)
        print("classmethod invoked")
        return cls(ext_name,ext_password)

a=User("carry","@#")
b=User.buildFromToken("elloit,$75")