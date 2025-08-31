#include<iostream>
/*Always we declare base class destructor as virtual
so when derived class objects are reclaimed then
derived class destructor is invoked.

Which parameterized base class constructor is invoked
depends on the arguements given to the constructor*/
class Base{
	public:
		Base(){
			std::cout<<"Base Constructor Invoked\n";
		}
		Base(int i){
			std::cout<<"Base Parameterized Constructor Invoked\n";
		}
		virtual ~Base(){
			std::cout<<"Base Destructor\n";
		}
};
class Derived:public Base{
	public:
		Derived(){
			std::cout<<"Derived Constructor Invoked\n";
		}
		Derived(int j):Base(j){
			std::cout<<"Derived Parameterized Constructor Invoked\n";
		}
		~Derived(){
			std::cout<<"Derived Destructor\n";
		}
};
int main(){
	Base* obj=new Derived(18);
	delete obj;
}