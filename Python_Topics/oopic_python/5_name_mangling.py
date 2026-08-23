class Parent:
    def __init__(self):
        self.__started="parent"

class Child(Parent):
    def __init__(self):
        self.__started="child"

print(Child().__dict__)