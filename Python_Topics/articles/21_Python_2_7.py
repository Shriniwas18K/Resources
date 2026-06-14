# Python 2.7 is used everywhere today in all projects
# though EOS in 2020. Major ones those were written
# way before this decade still rely on it. Its 
# diffirent from Python3. Hence its written in 
# this article itself. Python is at the heart
# a scripting language hence its dynamically
# typed nature. Its used for scripting in 
# sysops devsops environments.

# / used for division and default precision
# when any floating point number comes is
# 16 decimal places with 16th place approxes.

# when overflow occurs in integer calculations
# then automatically switch to long data type
# where values printed are suffixed with 'L'.
# though there isnt double data type.

# the one word print statement
print 2**100

# variables are references and arent tied to 
# types, rather values are tied to types
i=100
j=i+1

# global namespace contains
# i-> int,100
# j-> int,101

# two types of strings; ascii and unicode
# both support same methods
# in ascii each char is 8 bit,0
# to 256 ascii values
# in unicode each char is 32 bit.
# unicode strs are u' ' or u" " or u""" """.

# null character is '\x00' with value 0
# LF or linefeed or newline character is with
# value 10

# strings methods: 
s = 'hello'
print s.center(10)  # '  hello    '
print s.ljust(10)   # 'hello      '
print s.rjust(10)   # '      hello'

# string format() method since 2.6
print '{0} is pythonist'.format('he')# he is pythonist
# positional index based args
print 'hello {name}'.format(name='shrini')# hello shri
# keyword based args
print '{0:f} {1:s} {2:d}'.format(2,'2',2)# 2.0000 '2' 2
# type codes (s string) (int d) (float f)
print '{x:1.2f}'.format(x=123.45678)# 3.45
# digits before.after decimal point
# rounding occurs during formatting
print '{0:e}'.format(6.022*10**23) # 6.022e+23
# e enforces exponential notation

# space management using < > ^ to display fields
print '{0:6d}|{1:7s}'.format(7,'hello')#' 10|hello '
# specify length expected to capture
# by defaults ints are written from right
# and strs are written from left
# change it using ^ < >
# ^ tells write from center in that field area
# < tells write from left in that field area
# > tells write from right in that field area
print '/{0:^6s}/'.format('git') # '/  git  /'
print '/{0:<6s}/'.format('git') # '/git    /'
print '/{0:>6s}/'.format('git') # '/    git/'
# s is above for string, d for int, f for float

# before format() there % operator used for this 
# formatting like C %s,%d.

# special char printing to done like
print '{0:@^7s}'.format('git') # @@git@@

# for floats if precision is more than value
# then random chars are printed
print '{0:.6f}'.format(1.2) # 1.200000

# parameteric field lengths
print '{temp:@^{w}s}'.format(temp='git',w=7)# @@git@@

# all ' '," ",""" """,''' ''' are same string
# lstrip,rstrip,strip methods remove trailing
# spaces and newlines.

l = [1,2,3,4,5]
# insert multiple elements at same index
l[2:2] = [6,7,8]
print l
# delete multiple elements assigning empty list
l[2:5] = []
del l[2:3]
print l
# we can do above with only mutable sequences(list)

# the dict doesnt preserve order of insertion
d = {1:'a',2:'b'}
print d.has_key(5) # T/F
print d.get(5,"default")
# setdefault method checks if the key exists in dict
# if exists then returns d[key], else it makes
# d[key] = default value as given and returns
# the default value.
print d.setdefault(9,"default value")
print d

# cmp(x,y) builtin method, invokes __cmp__
# on x passing y, returning -1 if x<y, 0 if
# x==y else +1 if x>y
print cmp(1,4) # -1
print cmp(9,8) # +1
print 9>8 # invokes __cmp__

# some people do write horizontal codes using ;
# seprate multiple statements in same line using ;
print 1;print 2;print 3

# *args,**kwargs works fine, positional,keyword
# args rules stay same, keyword args at right

# /,* syntax doesnt exist for functions.

# namespaces are like dicts
print dir() # prints everything in global namespace
print dir(l) # prints everything in namespace of l
# while importing modules using
# from M import x, the enclosing namespace gets copy of x in it
# import M, the enclosing namespace gets copy of M itself
from math import pi
print dir()
import math
print dir()

# modules packages are for modularity and namespaces

# the first line of module,function,class if is str
# then it can be retreived using __doc__.
print math.__doc__

# objects are namespaces aka key-value pairs
# everything is object, class,instances,functions,modules,
# indented blocks, everything is namespace in Python.

# Python starts up with only __builtisn__,
# __doc__, __name__.



