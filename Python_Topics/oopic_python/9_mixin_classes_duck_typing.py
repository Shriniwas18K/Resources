"""
Mixin is design pattern. These are classes
adding functionality to the inheriting classes
"""
class LoggerMixin:
    def login(self):
        print("logged in")
class User:
    def __init__(self):
        self.name="name"

class LoggedUser(LoggerMixin,User):...