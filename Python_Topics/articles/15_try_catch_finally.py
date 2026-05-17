# if we use | operator for telling multiple errors then that except
# block doesnt execute. (err1,err2) syntax must be used.
# Python 3.14 introduces err1,err2 syntax.

# finally will always override the return value of any 
# other try except block above it, hence inside loops
# if full execution of loop is required then set some
# flag variable inside finally and continue the loop.
def func():
    try:
        print("hello world")
        raise ValueError
    except (TypeError,ValueError) as e:
        print("typeval")
        return 1
    except Exception as e:
        print("general")
        return 2
    except:
        print("More concise than above")
    finally:
        # overrides the return value always
        print("Finally")
        return 3

res = func()  
print(res)
