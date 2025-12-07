"""
allows dynamically creating classes
and are actually inheriting tuple class
hence comparable and accessible similar to tuples

but these are immutable, we have methods
like _replace(**kwargs) which return new instance
of namedtuple with updated values

all the namedtuple methods start with _
"""
from collections import namedtuple

Quaternion = namedtuple('Quaternion','w x y z')

q1=Quaternion(w=1,x=0.1,y=0.1,z=0.2)

print(q1)#__repr__ is already available

q2=(1,0.1,0.1,0.2)

print(q1==q2)

# named based access
print(q1.w)
#position based access
print(q1[0])

q3=q1._replace(w=9)

print(q3)