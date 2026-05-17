# Interfaces in Python can be declared by two ways 
# based on what we are developing and for whom.

# 1] For the developers by the developers
# We are developing inside the organization and
# our library is base layer or will be extended
# by developers and we want them to explicitely
# inherit(implement) our interface, and we will
# share our interface files with them for this
# then use ABCs.

# 2] For the users who will be just using APIs 
# If we are developing public facing library
# or something wherein we cannot share our
# interface files or mandate our users to
# inherit(implement) our interfaces, or our
# codebase is already built from years and
# we are just providing type hints to users
# then use Protcols.

# ABCs introduce tight coupling and explicit inheritance
# whereas Protocols promote polymorphism and flexibility.

# Entire Python is built around Protocols, whereas
# much of frameworks built around ABCs, because
# Protocols were introduced in v3.8, and ABC stay
# in the language from long back. Protocols are 
# structural subtyping, whereas ABCs are nominal 
# subtyping. Both form modern Python.

# Examples

# 1] Suppose we have developed Generic LinkedList
# interface in base layer, thats will be used by everyone
# then if someone wants to add new LinkedList
# implementation then he needs to comply with our
# interface hence we mandate him to inherit(implement)
# it to be used in our base layer. Because base 
# layer should be type safe by type checker as it
# will be used by tons of software built later on top of it.
from abc import ABC
from typing import Protocol, TypeVar,Generic

T = TypeVar('T')
class ILinkedList(ABC,Generic[T]):
    def insert_at_head(self,val: T)->None:
        pass
    def insert_at_tail(self,val: T)->None:
        pass

class CSinglyLinkedList(ILinkedList[T]):
   def insert_at_head(self, val: T) -> None:
       pass
   def insert_at_tail(self, val: T) -> None:
       pass
   
# 2] Suppose our codebase is already developed years
# ago like django codebase, where we cannot insert
# types to every single file now in millions of lines
# still we want users to comply with the public APIs
# and get advantage of type hinting where they know
# the codebase of django is not type safe exactly by 
# the type checkers, or we cannot share the interface
# files because single update in our interface will
# need them needs users to recompile/rebuild their
# applications. In this case we use Protocols. Here
# users can have anything Printable so to use our
# library they shouldnt need to explicitely subclass
# IPrintable and wrap their classes with it, rather 
# they can just simply add __repr__ method to their classes.
class IPrintable(Protocol):
    def __repr__(self) -> str:
        ...
def our_library_print_function(printable: IPrintable)->None:
    print(f"{printable=}")

class MyClass:
    def __repr__(self) -> str:
        return f"<MyClass instance>: values"
    