#include <iostream>

// due to virtual inheritance only single copy of base
// class members is in derived grandchild class
class A {
public:
    virtual void func() {
        std::cout << "class A\n";
    }
};  // ✅ Fix: Added missing semicolon
// Diamond inheritance ambiguity resolution using virtual inheritance
class B : virtual public A {
public:
    void func() override {
        std::cout << "class B\n";
    }
};
class C : virtual public A {
public:
    void func() override {
        std::cout << "class C\n";
    }
};

class D : public B, public C {
public:
    void func() override {  // Explicitly resolve ambiguity
        std::cout << "class D\n";
    }
};// use const wherever possible
int main() {
    D obj;
    obj.func();  // ✅ Calls D's func(), resolving ambiguity
	obj.B::func();
	obj.C::func();
	obj.A::func();
	int i=4.2;
	int j(4.2);//() can be considered as constructor for objects
//	int k{4.2};//narrowing/casting doesnt occur here
//  this is initialiser list syntax used for strict type checking of arguements
	}
}
