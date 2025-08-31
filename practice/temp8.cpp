#include<iostream>
#include<variant>
// static members are stored in the binary of program iteslf at runtime
// they are tied to struct or classes and not instances, and all instances
// can access same static variable
// if any method is declared static then it cant access instance members
// static members need to be initialised in global scope(file atmost)
// function scope static persists between calls
// class scope static accessible to all objects
// global scope static persists throughout lifetime of program
// we can create static lambdas but they cant capture variables of enclosing scope
// friend functions are not members of classes structs still they can access all the private members of them
// hence we can declare any function not belonging to class as its friend and write it inside class but still
// it is not member function of class
// we use alignas operator to specify size of structs classes but it should be moer or equal to actual size
struct alignas(8) UDTs{
	int x{18}; // 4bytes
	int y{37}; // 4bytes
	UDTs():x{37},y{18}{}
	UDTs(int a,int b):x{a},y{b}{}
	friend std::ostream& operator<<(std::ostream& lhs,const UDTs& rhs){
		lhs<<rhs.x<<" "<<rhs.y<<" ";return lhs;
	}
};// first inplace initialisers then constructor initialiser list then constructor invoked
// unions store only one data member at time and have the size of max sized data member in them
// but if we access the not stored data members then no errors hence we use variants which give
// error on accessing not stored data members, when we write value of one data member then the
// data members are released, its basically all data members accessing that same memory
union alignas(8) UDTu{
};
int main(){
	std::cout<<alignof(UDTs)<<" "<<sizeof(UDTs);
	std::cout<<alignof(UDTu)<<" "<<sizeof(UDTu);
	std::variant<UDTs,int> var;
	var=UDTs();
	std::cout<<std::get<UDTs>(var);
}