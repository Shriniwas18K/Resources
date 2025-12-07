"""
we have three ways for printing any object
two are written and one is __format__ which
takes preference over __str__
"""
class Base:
    def __init__(self):
        self.a='hello'
        self.b='world'
    def __repr__(self):
        # for developers
        name=self.__class__.__name__
        return f'{name}({self.a!r},{self.b!r})'
    def __str__(self):
        return f'a={self.a!r},b={self.b!r}'

obj=Base()
print(f'{obj=}')# repr runs using obj!r or obj=
print(f'{obj}')# str runs