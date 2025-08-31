#include <iostream>
#include <utility>

// Mega Rule: Always define all these for any class or struct
/*
	1) Constructors
	2) Destructors
	3) Copy Constructors
	4) Copy Assignment operators
	5) Move Constructors
	6) Move Assignment operators
	7) Conversion operators for parent classes to current class in hierarchy
*/
// Avoid friend functions unless absolutely necessary (usually for operator overloading)
// Declare pure and parameterized constructors and conversion operators as explicit to prevent implicit conversions anywhere
// Copy and Move Constructors shouldnt be declared explicit
// Use list initialization { } everywhere to avoid accidental type casting
struct UDT {
    int i;

    explicit UDT(int j) : i{j} {
        std::cout << "Constructor invoked\n";
    }

    ~UDT() {
        std::cout << "Destructor invoked\n";
    }

    UDT(const UDT& rhs) {
        std::cout << "Copy Constructor invoked by taking lvalue reference\n";
        i = rhs.i;
    }

    UDT& operator=(const UDT& rhs) {
        if (this != &rhs) {  // Prevent self-assignment
            std::cout << "Copy assignment operator invoked by taking lvalue reference\n";
            i = rhs.i;
        }
        return *this;
    }

    UDT(UDT&& rhs) noexcept {
        std::cout << "Move Constructor invoked by taking rvalue reference\n";
        i = std::exchange(rhs.i,0);
    }

    UDT& operator=(UDT&& rhs) noexcept {
        if (this != &rhs) {  // Prevent self-assignment
            std::cout << "Move assignment operator invoked by taking rvalue reference here\n";
            i = std::exchange(rhs.i,0);
        }
        return *this;
    }
};
// explicit base class constructors need to be explicitely
// called in the derived class while construction which
// removes the ambiguity that which constructor will be
// invoked in case of multiple inheritance hence it is
// recommended to declare explicit to all constructors and
// conversion operators, it improves clarity
struct childUDT : public UDT {
    int j;

    explicit childUDT(int a, int b) : UDT(b), j{a} {
        std::cout << "Child constructor invoked\n";
    }

    explicit childUDT(UDT baseobj) : UDT(baseobj) { // ? Pass `baseobj` directly
        std::cout << "Child constructor invoked and created child object from base class object\n";
    }
};
// if that child constructor wouldnt have been explicit then the
// base object would have been made as it is derived and keep
// the derived fields uninitialised
void test(childUDT obj){
	std::cout<<"Function test() invoked\n";
}
void test1(UDT obj){
	std::cout<<"Derived object sliced off to base and the copy constrcutor is invoked in base\n";
	std::cout<<"Function test1() invoked\n";
}
int main() {
    UDT o1(18);       // Constructor
    UDT o2(o1);       // Copy Constructor
    UDT& o3 = o2;      // nothing invoked its just creating lvalue reference
    o3=o1;				// Copy Assignment
    UDT o4(std::move(o3));  // Move Constructor
    UDT o5 = std::move(o4); // Move Constructor
    o5 = std::move(o1);     // Move Assignment
//  test(o5);// not allowed implicit conversion to childUDT due to explicit
	test(childUDT(UDT(18)));
	childUDT o6(18,37);
	test1(UDT(o6));
    return 0;
}
