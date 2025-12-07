"""
They mandate the inheriting classes to override
the methods declared as abstract, the abstract
implementation is default, and we cannot instantiate

There are no compile time error, instead the
error comes when instance is initialized

They are really helpful with mixins because
they allow to define certain methods that
the mixin expects user to override

Thus we have two kinds of methods in any
abstract class:
1) abstract methods
2) mixin methods
"""
from abc import ABC,abstractmethod

class BaseMixin(ABC):
    @abstractmethod
    def m(self):...

    def mixin_method(self):
        print("default implementation")

class Derived(Base):
    def m(self):
        print("Derived")

print(Derived().m())
print(Derived().mixin_method())