"""
The dunder __getattr__ method of instance is called at
last in attribtue finding mechanism before throwing attribute error

The dunder __getattribute__ method bypasses whole
attribute finding mechanism

for overridding these methods the signature should remain same as in object class
"""
class A:
    def __getattr__(self,attr):# this is signature in object class too
        print("dunder getattr")

print(Proxy().any_attribute_or_method_that_doesnt_exist)

