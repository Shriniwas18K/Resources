# Sometimes we need some objects that should
# always be in memory thus never gc collects
# these objects. For making such objects we 
# use cyclic references.

# list appended to itself creates cyclic reference
# they are represented in Python by [...]

l = [18]

l.append(l)

print(l)
print(l[1])
print(l[1][1][1][1])
