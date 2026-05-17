# the naive way of writing logic is nesting if else conditions
# which is harder to grasp and maintain, rather we should use
# guard clauses pattern which is easier to grasp and maintain.

def check_strength(pwd: str)->bool:
    if len(pwd)>10:
        if pwd.isalnum():
            return True
        else:
            print("password shoudl be alphanumeric")
    else:
        print("min length is 10")
    return False

def good_check_strength(pwd:str)->bool:
    if not len(pwd)>10:
        print("min length is 10")
    elif not pwd.isalnum():
        print("password shoudl be alphanumeric")
    else:
        return True
    return False


