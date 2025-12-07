from dataclasses import dataclass,field
"""
use type annotations

when default values not given then 
its required to set the value of
those attribtes at time of creation

whichever default values we give are immutable

if we want mutable default values then we use field

it is recommended to make these as immutable hence
we will use them as keys in dictionary, as they become hashable

ther are lot advantages for immutable things prevents
many issues like shared access and other potential bugs
"""
@dataclass#(frozen=True)
class Bookmark:
    url: str # default value not given hence required
    title: str = 'default' # optional
    default_tags: tuple[str] = ('web','oop') # immutable default values only
    mutable_tags: list[str] = field(default_factory=list)

    def __post_init__(self):
        print("instance created")

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