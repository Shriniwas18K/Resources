#include<iostream>
#include<memory_resource>
// std library containers work with heap allocation by default
// but if we need custom stack allocation then we can use
// polymorhic memory resource and get 3.5x performance boost
// the vectors are fastest std library containers, using
// compiler explorer and quick bench we see these are useful
// heap allocation is highly slow

// pmr vector is std vector with polymorphic allocators, thus
// pmr namespace gives us type erased way to work with memory
// resources and allocators, and have containers of things which
// are themselves allocator aware in minimal amount of code

// the std allocators are the default allocators for std vectors
// which use defualt new and dlete to manage resources, we use
// always allocator of some kind, either std or custom or pmr

// memory_resource is an abstraction interface for allocating
// and deallocating memory which can be used for custom and std stuff

// pmr::monotonic_buffer_resource inherits from memory_resource and
// minimal virtual function calls if we come up with performant
// memory allocation stratergy that works with your code

// pmr::monotonic_buffer_resource is meant to be used when we have
// very fast allocations in situations were memory is used to
// build up some objects and then released all at once,it isnt
// useful when containers grew over time, this happens due to
// copying happenging inside on every insertion and the container
// doesnt live on buffer instead data lives on buffer and container
// has pointers to it, if the data added is more than buffer and
// isnt allocator aware i.e everything else than pmr namespace
// like std::string then again heap allocation occurs which thus
// doesnt use the buffer and again that overcopying occurs and the
// allocated memory isnt freed, so we need to use allocator aware types like std::pmr::string
int main(){
	std::byte stackbuf[2048];
	std::pmr::monotonic_buffer_resource rsrc(stackbuf, sizeof stackbuf);
	std::pmr::vector<int> v1({1,2,5,5,2,5},&rsrc);
}