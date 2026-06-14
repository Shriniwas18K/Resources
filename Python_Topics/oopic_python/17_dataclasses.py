from dataclasses import dataclass,field
"""
use type annotations

when default values not given then 
its required to set the value of
those attribtes at time of creation

whichever default values we give are immutable

if we want mutable default values then we use field

it is recommended to make these as immutable hence we will
use them as keys in dictionary, as they become hashable.
hence add
1] frozen=True,
2] slots=True makes them slotted removing __dict__

when declaring them immutable, in that case we can still
set or modify attributes in __post_init__ using
object.__setattr__ method.

we can enforce keyword args during creation statement
by setting kw_args=True. Then every user has to give
non default keyword arguement values, which prevents
bugs of positional arguements where user may shift
the values of positional args, or not know whats
expected, writing keyword args during creation
makes it explicit for reader.
"""
@dataclass#(frozen=True,slots=True,kw_args=True)
class Bookmark:
    url: str # default value not given hence required
    title: str = 'default' # optional
    default_tags: tuple[str] = ('web','oop') # immutable default values only
    mutable_tags: list[str] = field(default_factory=list)

    def __post_init__(self):
        print("instance created")
        print("post init modification of attributes(even if immutable slotted)")
        if self.title == "":
            object.__setattr__(self,"title","dummy_value")

b1=Bookmark(
    url='https://google.com'
)
b2=Bookmark(
    url='https://msdn.com'
)

print(b2.mutable_tags)
b1.mutable_tags.append('internet')
print(b1.mutable_tags)
print(b2.mutable_tags)
