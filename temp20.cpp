#include<iostream>
// static variables declared inside function
// are accessible only inside function itself

// static variables are stored inside the memory
// of the binary itself,not stack not heap

// static variables declared inside stack are
// stored with the class itself, and can be
// accessed based on access modifier, and all
// functions within the class can access them

// if any member function is declared static
// then it cannot access instance members and
// the class

// static members and functions declared
// inside class need to be initialised
// outside class using :: operator

// all instances of the class can access the
// same value or object of static variable

static void print(){
	std::cout<<"static function\n";
}

class Entity{
	public:
	static void print(){
		std::cout<<"static member function\n";
	}
	private:static int data;
};

int Entity::data=18;

int main(){
	print();
	Entity::print();
}