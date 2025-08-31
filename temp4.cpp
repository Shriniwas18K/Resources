#include<iostream>
#include<memory>
#include<string>
class UDT{
	public:
		std::string name;
		UDT(std::string Name){
			this->name=Name;
			std::cout<<"\nconstructor invoked for "<<this->name;
		}
		~UDT(){
			std::cout<<"\ndestructor invoked for "<<this->name;
		}
};
void this_method_execution_scope_contains_object(UDT&& obj){
	std::cout<<"\nobject gets memory reclaimed or deleted here when this method completes execution";
}
int main(){
	std::cout<<"Smart Pointers for automatic memory management";
// unique pointer, only one variable can own the object
// at a time and it is automatically deleted when variable
// goes out of execution scope
	{
		std::unique_ptr<UDT> u_ptr=std::make_unique<UDT>("unqiue A");
		// but we can surely transfer the ownership of the
		// object using move
		this_method_execution_scope_contains_object(std::move(*u_ptr));
	}
// shared pointer, the idea of shared ownership by pointers
// on the same object, reference count is maintained,object
// memory is reclaimed when all pointers are reassigned
// somewhere or go out of execution scope
	std::shared_ptr<UDT> s_ptr1=std::make_shared<UDT>("shared B");
	std::shared_ptr<UDT> s_ptr2=s_ptr1;
	std::cout<<"\ncurrent reference count is "<<s_ptr2.use_count();
	s_ptr1=nullptr;
	std::cout<<"\ncurrent reference count is "<<s_ptr2.use_count();
// weak pointer, the idea of shared ownership along with the
// pointers which point the object but not own the object,
// hence the reference count isnot affected.
	std::weak_ptr<UDT> w_ptr=s_ptr2;
	std::cout<<"\ncurrent reference count is "<<s_ptr2.use_count();
// the weak pointers arent counted as owning object so they
// may even access object even after it is reclaimed which
// can throw SIGSEGV at runtime(null pointer exception)
}