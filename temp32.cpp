#include<iostream>
struct Base{
	int baseData{1};
	Base(){baseData=11;
	}
	virtual void Do(){
		std::cout<<"Base Do() :\t"<<baseData<<"\n";
	}
	static void info(){
		std::cout<<"Base info()\n";
	}
};// structs are similar to classes to use
// the same stuffs are followed for both
struct Derived:Base{
	int derivedData{2};
	Derived(){derivedData=18;
	}
	void Do(){
		std::cout<<"Derived Do() :\t"<<derivedData<<"\n";
	}
	static void info(){
		std::cout<<"Derived info()\n";
	}
};// we willl illustrate dynamic casting
// with polymorphism that occurs
int main(){
	// when we static_cast pointers or references then
	// still the underlying object remains same unchanged
	// only the reference or type gets casted
	// we cannot change the type of object in heap at runtime
	Base* b=new Base;
	Derived* d=new Derived;
	static_cast<Derived*>(b)->Do();// Base Do() invoked
	d->Do();// Derived Do() invoked

	// but rather if the references are casted then we
	// can indeed access the static methods because they
	// are attached to data type hence as we are casting types
	// so we can access the static methods binded to those types
	static_cast<Derived*>(b)->info();// Derived info() invoked
	d->info();// Derived info() invoked

	if(dynamic_cast<Derived*>(b)){
		// this cast isnt valid same as static_cast
		// of Base to Derived for the same reason that
		// Derived needs explicit constructor to be written
	}

	if(dynamic_cast<Base*>(d)){
		// fully valid cast, Derived can be treated as Base
		// but Base needs virtual functions for making
		// runtime dynamic polymorphism
		Base* ptr=dynamic_cast<Base*>(d);
		ptr->Do();// virtual of Base hence Derived version is invoked
		ptr->info();// static of Base
	}

	// we shouldnt use C-style casts because it doesnt thorw error
	std::cout<<(int*)(d);//allowed
 }