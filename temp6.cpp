#include <iostream>
#include <ostream>

// The rule of 3 always define constructor,
// copy constructor,destructor together

// by default compiler generates these above
// three of them which we havent written, but
// those are empty body methods and atmost
// in genrated copy constructor too shallow
// copying is performed

// custom made implementations of these three special
// methods are required in case of heap allocation
// to prevent memory leaks at runtime and custom
// initialisation and resource cleanup, and custom
// copy constructors for deep copying heap stored values

class Array{
		int* data;
		// if we want no copies should be made at all
		// not even by compiler generated constructor
		// and copy assignment operator then use below
		// way of declaring private methods like below
//		Array& operator=(Array& rhs)=delete;
//		Array(const Array& rhs)=delete;
		// and then everywhere in methods we follow
		// pass by reference for this object
	public:
		Array(){
			data=new int[10];
		}
		~Array(){
			delete[] data;
		}
		Array(const Array& rhs){
			this->data=new int[10];
			for(int i=0;i<10;i++)
				this->data[i]=i;
			std::cout<<"\nCopy Constructor invoked\n";
		}
		void print(){
			std::cout<<"\n";
			for(int i=0;i<10;i++){
				std::cout<<this->data[i]<<" ";
			}std::cout<<"\n";
		}
		Array& operator=(const Array& rhs){
			//object which is already constructed is ,ade into copy of some object of same type
			std::cout<<"\ncopy assignment operator invoked";
			if(&rhs==this)return *this;
			this->data[0]=this->data[1]=this->data[2]=18;
			return *this;
		}
};
void callByValue(Array a){
	std::cout<<"copying due to call by value here\n";
}
int main(){
	Array a;
	Array a1=a;//copy constructor invoked when first same type assignment at declaration
	a1.print();
	callByValue(a);//copy constructor invoked when call by value object is passed
	Array a2;//object constructed
	a2=a1;//copy assignment operator
	a2.print();
}