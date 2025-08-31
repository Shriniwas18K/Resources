#include<iostream>
// the C-style casts perform these modern cpp casts only, it first
// tires static cast else dynamic cast else reinterpret cast

// static cast works with all types but not pointers and references
// it is fully compile time and works well but is less safe because
// we dont have error checking static cast

// dynamic cast works with all pointers and references and if cast
// cannot happen then null pointer is returned, we use it to safely
// convert between classes in inheritance hierarchy at runtime,but
// we need something virtual in base class, and we need runtime type
// information and is more expensive

// whenever we want to cast then prefer dynamic casts because we can
// check catch the error thrown
struct Base{
	int baseData{1};
	Base(){baseData=11;
	}
	virtual void Do(){
		std::cout<<"Base Do() :\t"<<baseData<<"\n";
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
};
int main(){
	// static cast
	float f{3.14f};
	int i=static_cast<int>(f);// same as int i=f; implicit casting
	std::cout<<i<<"\n";
	int j=(int)f;// C-style cast isnt preferred but allowed

	Derived d;Base b;// on stack memory
	d.Do();b.Do();
	// treating Derived as Base
	(static_cast<Base>(d)).Do();
	// even if we make any functino virtual in Base or Derived
	// then too that virtual function itself gets called
	// to treat Base as Derived we need constructor
	// in Derived which performs the casting from Base&
	//	(static_cast<Derived>(b)).Do();
	// logically thinking Derived contains all members of the
	// Base hence it can be easily treated as Base but converse
	// needed treatment in constructing Derived object
}