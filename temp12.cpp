#include<iostream>
class Ancestor{
	// any class containing atleast one pure virtual
	// function is called abstract class and it
	// cannot be instantiated
	public:
		virtual void func()=0;
	// such kind of classes are like Java Interfaces
};
class Base:public Ancestor{
	public:
		virtual void func() override{
//			these are abstract functions which contain some
//			default implementation for derived classes
			std::cout<<"Base implementation default\n";
		}
};//each class has its own vtable for dynamic dispatch and overridden implementation
class Derived:public Base{
	public:
		void func() override{
			std::cout<<"Overriden implementation Derived\n";
		}
};
int main(){
	Base* obj=new Derived;
	obj->func();
	obj=new Base;
	obj->func();
	delete obj;
}