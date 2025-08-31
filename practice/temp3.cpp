#include<iostream>
#include<memory>
struct UDT{
	int i;
	UDT(int j):i{j}{
		std::cout<<"Constructor "<<i<<" invoked\n";
	}
	~UDT(){
		std::cout<<"Destructor "<<i<<" invoked\n";
	}
};/*using smart pointers the objects are reclaimed once
the unique pointer goes out of execution scope{}, or once
all shared pointers go out of execution scopes{} means
reference count reaches 0, weak pointers are used to
prevent cyclic references to same object
*/
int main(){
	{
		std::shared_ptr<UDT> s_ptr1=std::make_shared<UDT>(2);
		std::shared_ptr<UDT> s_ptr2=s_ptr1;
		std::shared_ptr<UDT> s_ptr3=s_ptr1;
		std::weak_ptr<UDT> w_ptr=s_ptr1;
		// weak pointer is temporary made into shared pointer to access the value
		std::cout<<"value inside object is "<<w_ptr.lock()->i<<"\n";
		std::cout<<"value inside object is "<<s_ptr1->i<<"\n";
		std::cout<<"shared pointers pointing to the object are "<<s_ptr1.use_count()<<"\n";
	}
	std::unique_ptr<UDT> u_ptr=std::make_unique<UDT>(1);
}