# == compares values in Python 
# is compares memory address or identity in Python

obj2 = obj1 = object()

print(obj1 == obj2) # True
print()

# shallow copy, by default when Python copies objects then it
# does shallow copy where one level deep copies are made,
# if there are nested objects then they arent copied, they 
# are just referenced by new copied higher level objects
# for copying nested objects we need to deepcopy
# deepcopy makes exactly end to end independent copies.
from copy import deepcopy

l1 = [1,2,[3,4]]
l2 = l1.copy()
l3 = deepcopy(l1)

l2[2].append(5) # did insert into l1 nested list 
print(l1) # [1,2,[3,4,5]]

l3[2].append(6) # didnt affect l1 at all
print(l1) # [1,2,[3,4,5]]

# mutable_defaults
# whenever Python makes mutable default args then it creates them all
# at once, and if someone doesnt pass the value and same default
# gets modified in that case, that modification is seen to all
# the solution to this is using Optionals.
# list,dict are mutable, tuples are immutable, thus things of mutable and 
# immutable generic containers were written before.
def func(temp: list[int] = []):
	temp.append(18)
	print(temp)

func() # [18]
func() # [18,18]
func() # [18,18,18]

def funcOpt(temp: list[int]| None = None):
	if not temp:
		temp = []
	temp.append(18)
	print(temp)

funcOpt() # [18]
funcOpt() # [18]
funcOpt() # [18]


