# for some logics we have long if-else,case-label ladders which 
# are tightly coupled code. Instead we can use Command Pattern.
# To make any change, it affects other surrounding code.
# Consider example of task executor and classic way.
# Command Pattern allows to change commands and their
# operations in loosely coupled manner.

# Many people say Command Pattern is same as Dispatch
# Pattern but its not, Dispatch Pattern involves same
# operation on diffirent kinds of entities. Command 
# Pattern involves many operations using same entity.
# In other words only Dispatch Pattern can acheive
# function overloading and has builtin support using
# functools module singledispatch,singlemethoddispatch.

from typing import Callable,Self,Any,List

class Executor:
    @staticmethod
    def configure(attr:str,val:str):...
    @staticmethod
    def build() -> Self:...
    def submit(self,task:Callable,*args:List[Any])->bool:...
    def execute(self) -> bool:...
    def shutdown(self) -> bool:...

command = input("Enter your input: ")
executor = None

# classic way if-else | switch-case
if command == "configure":
    attr,value = input("Enter attribute,value:")
    Executor.configure(attr,value)
elif command == "build":
    executor = Executor.build()
    
match command:
    case "submit":
        status = executor.submit(print,"hello","world")
    case "execute":
        status = executor.execute()
    case "shutdown":
        status = executor.shutdown()

# command

registry = {
    # command : operation pairs
    "configure" : configure,
    "build" : build,
    "submit" : submit,
    "execute" : execute,
    "shutdown" : shutdown
}

def commandInputHandler(userInputCommand:str):
    if userInputCommand in registry:
        commandOperationHandler = registry[userInputCommand]
        status = commandOperationHandler()
        if status == 0:
            print(userInputCommand, " completed successfully")
        else:
            print(userInputCommand, " errored")

commandInputHandler(command)
