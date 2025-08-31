#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>

void operate(int& refparam){
	refparam=18;
}
void function(const int& refparam){
//	now we can read or access refparam values here but cannot modify
}
int main(){
//	& operator address of
//  cpp supports operator overloading so sizeof & both can be seen as functions
	int x=100;
	int y=1000;
	int z;
	{
		z=13405;
	}
	std::cout<<&x<<" "<<&(y)<<" "<<&z<<" ";
	std::cout<<sizeof x<<" "<<sizeof(y)<<"\n";
//	& is used to create references or alias which are replaced at compile time
//  with the actual address of variables
	int& ref=x;
//	int& is full type of ref
	std::cout<<"address of ref : "<<&ref<<"\n"<<"address of x   : "<<&x<<"\n";
	std::cout<<ref<<" "<<x;
//	they are used for pass by reference
//  by default everything in cpp is pass by value
//  but we use & for pass by reference
	operate(x);
	std::cout<<"\nx after operations : "<<x<<"\n";
//	in call by value copy of value being passed is created but
//  passing references removes copying overhead and directly
//	puts the arguement objects into method.
	std::cout<<typeid(x).name()<<"\n";
//	sometimes addresses of string and char values need to be casted to void*
	char c='a';
	std::string s="a";
	std::cout<<(void*)&c<<" "
		<<(void*)&s;
//  use decltype from type_traits to create another variable of same type
	std::unordered_map<int,int>map;
	decltype(map) map1;
//	like this helps us to create same type variables
	std::cout<<"\n"<<typeid(map1).name()<<"\n";
	const int q=100;
	std::cout<<std::is_const<decltype(q)>::value;
}