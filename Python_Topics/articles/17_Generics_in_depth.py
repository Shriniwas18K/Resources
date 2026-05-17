# Generics are way to write more code in less lines.
# They are usually in the base layers of software.
# Similar to Cpp templates, Java Generics are Python ones.

from typing import Generic, TypeVar


class Parent:...
class Child(Parent):...

# Variance is specifically for containers using Generics.

# 1] Covariance: We can safely substitute Child type in place
#    of the Parent type. Hence type widening allowed.
# 2] Invariance: Only exact type can be used.

# Covariant Containers: They are immutable producers of
# values, hence if they define Parent as return type
# then too they can safely produce Child type as its
# perfectly valid, Child always has everything inherited
# from Parent class. This is specifically for read-only
# containers or immutable containers. 
T_co = TypeVar("T_co",covariant=True)
class Producer(Generic[T_co]):
    def __init__(self,val: T_co) -> None:
        self.val : T_co = val
    def produce(self)->T_co:
        return self.val
child_producer : Producer[Child] = Producer(Child())
parent: Parent = child_producer.produce()
# These are Covariant Containers:
# 1] Sequence[T_co]
# 2] MappingView[T_co]
# 3] Tuple[T_co]
# 4] Frozenset[T_co]
# 5] Iterable[T_co]
# 6] Iterator[T_co]
# All are immutable, or the ones which give/produce values
# hence its safe to give out Child type value where Parent
# type value is expected.

# Invariant Containers: These are mutables or containers that
# both produce and consume values. These are invariant containers.
# 1] List[T], list[T]
# 2] Dict[K,V], dict[K,V]
# 3] Set[T], set[T]
# 4] bytearray
# 5] Deque[T]
# 6] MutableSequence[T]
# 7] MutableMapping[T]
# 8] MutableFrozenSet[T]

# Contravariance: we can use Parent type where Child type is
# expected. This is rarely the case, because anywhere the 
# Parent type may not contain the methods attributes that are
# exclusive to Child type. Hence not used.
# Only Callable[[T_contra],T_co] is the known contravariant.
