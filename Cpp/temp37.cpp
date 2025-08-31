#include<iostream>
#include<typeinfo>
#include<map>
#include<any>
/*void* is typeless pointer and can store the
address of any type, but to access value we need
to static cast it to the type of value stored,it
is mostly used in C-style APIs and modern safer
way to store such stuff whose compile time type
is unknown but we want runtime type safety is
std::any and used for heterogenous containers*/
int main(){
	std::any var;
	var=37;
	std::cout<<std::any_cast<int>(var)<<" ";
	int i=37;
	void* ptr=&i;
	std::cout<<*static_cast<int*>(ptr)<<"\n";
	std::map<std::string, std::any> config;
	config["timeout"] = 30;
	config["hostname"] = std::string("localhost");
	config["debug"] = true;
	// below shows structuered bindings or unpacking pairs tuples
	for(const auto& [key, value] : config) {
        std::cout << key << ": ";
        if (value.type() == typeid(int)) {
            std::cout << std::any_cast<int>(value);
        } else if (value.type() == typeid(std::string)) {
            std::cout << std::any_cast<std::string>(value);
        } else if (value.type() == typeid(bool)) {
            std::cout << (std::any_cast<bool>(value) ? "true" : "false");
        } else {
            std::cout << "[unknown type]";
        }
        std::cout << '\n';
    }
}