// bit fields are only for integral types
// char,short,int,long but the size of attribute
// specified must be less than its actual size
// the &addressof operator cannot be applied to
// them and are most memory optimised for usage
// Arrays of bit fields, pointers to bit fields,
// and functions returning bit fields aren't allowed.
struct BitField{
	int a:2;
	int  :3;
	short b:1;
};// size of each object above is always 2+3+1=6 bits
#include <iostream>
#include <memory>   // for std::uninitialized_fill

int main() {
    constexpr std::size_t SIZE = 5;

    // Step 1: Allocate raw uninitialized memory for 5 integers
    int* raw_memory = static_cast<int*>(::operator new(SIZE * sizeof(int)));
    std::cout << "Memory allocated at: " << static_cast<void*>(raw_memory) << "\n";

    // Step 2: Fill the raw memory with constructed integers (value = 42)
    std::uninitialized_fill(raw_memory, raw_memory + SIZE, 42);
    std::cout << "Memory initialized with value 42\n";

    // Step 3: Use the memory (print the values)
    for (std::size_t i = 0; i < SIZE; ++i) {
        std::cout << "raw_memory[" << i << "] = " << raw_memory[i] << "\n";
    }

    // Step 4: Destroy the constructed objects manually but here int is primitive type so automatically cleaned up
    std::cout << "Objects destroyed manually\n";

    // Step 5: Free the raw memory
    ::operator delete(raw_memory);
    std::cout << "Memory deallocated\n";

    return 0;
}
