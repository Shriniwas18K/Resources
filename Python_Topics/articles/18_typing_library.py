# The typing library provides excellant support for building
# compiled Python using static type checkers like MyPy.

# Some noteworthy things:

# 1] Self: It refers to the type of the entity itself. It is
#    useful for copy constructors, class methods.
# 2] Optional or Type|None : Both of these look same but are
#    diffirent, because None is type in Python too. It is
#    prefered to use Optional[T]
# 3] Forward Declarations: Sometimes we have to infer some 
#    types that are declared later, so we actually enclose
#    them in previous usages with "", e.g. Optional["INode[T]"]

# Follow convention of C# and Java, 
# 1] Interfaces contain only behavior as method signatures. 
#    Named as I<Name>.
# 2] Abstract Classes contain data members with default values
#    and behavior or methods with default implementations.
#    Named as CA<Name>.
# 3] Concrete Classes contain logic and implementations. 
#    Named with CC<Name>.