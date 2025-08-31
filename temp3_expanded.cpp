#include<iostream>
#include<utility>// std::forward
#include<functional>// std::reference_wrapper
#include<vector>
/*
lvalues are something having an address
rvalues are something that is temporary or doesnt have an address like numbers characters 10,'a' etc

in rvalues the ones which are temporary values like intermieddiate calculation results are called xrvalues
remaining all are pure ravleus or prvalues

the references pointing to lvaleus are lvalue references : used as aliases, and in pass by reference only adddrees of the object is passed here hence object ownerhsip doesnt change here
the references pointing to rvaleus are rvalue references : used in pass by reference to remove redudant copying using std::move to transfer the ownership of object to another scope

in case of templates of overloaded functions we need to use std::forward for reference forwarding

T funcname(T obj...){...} // here compuslory ojbect is expected as arguement hence compulsory copying done
// but to prevent this copying we can use std::ref, this is especially in case of STL containers which have
// all functions which are intended like above to make copying, i.e whatever object is passed in the function
// its copy is stored in container, and thus to prevetn this copyign and storing the actual object or its reference
// we use std::reference_wrapper,hence the ownership of objects isnt transferred to container and the objects have
// lifetime independent from the container itself, and the container only contains references to them

// similarly when those objects inside container are passed to std algorthsm then again copying occurs hence
// we need to use the move iterators of STL there
*/
// in below all fucntions where lvalue_reference or rvalue_reference is passed as arguement there is no copying at all
void deleteObject(std::string&&);
void modifyObject(std::string&);
void process(std::string&);
void process(std::string&&);
template<typename T>
void forwardToCorrectProcess(T&& arg){
	process(std::forward<T>(arg));
}
int main(){
	std::string lvalue="rvalue";
	std::string& lvalue_reference = lvalue;
	deleteObject(std::move(lvalue));
	deleteObject("rvalue_string");
	modifyObject(lvalue);
	modifyObject(lvalue_reference);
	forwardToCorrectProcess(lvalue_reference);
	forwardToCorrectProcess(lvalue);
	forwardToCorrectProcess("rvalue");
	forwardToCorrectProcess(std::move(lvalue));
	std::vector<std::reference_wrapper<std::string>> vec;
	vec.push_back(std::reference_wrapper<std::string>(lvalue));
	vec.push_back(std::reference_wrapper<std::string>(lvalue_reference));
	std::cout<<"\nvector elements\n";
	for(auto i:vec)
		std::cout<<i.get()<<" ";
	std::vector<std::string> dest;
    // Using move iterators to transfer ownership
    std::copy(std::make_move_iterator(vec.begin()),
              std::make_move_iterator(vec.end()),
              std::back_inserter(dest));
    std::cout << "\nDestination contains: ";
    for (const auto& s : dest) std::cout << s << " ";
}
void modifyObject(std::string& lvalue_reference){
	std::cout<<"\nThe object isnt owned here only accessed using lvalue reference\n";
	std::cout<<lvalue_reference;
}
void deleteObject(std::string&& rvalue_reference){
	std::cout<<"\nThe std::string object is owned here now and is in this function scope only\n";
	std::cout<<rvalue_reference;
}
void process(std::string& lvalue_reference){
	std::cout<<"\nlvalue_reference overloaded function correctly called\n";
}
void process(std::string&& rvalue_reference){
	std::cout<<"\nrvalue_reference overloaded function correctly called\n";
}