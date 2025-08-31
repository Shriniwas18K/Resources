#include<iostream>
#include<optional>
/*we can have optional values to prevent SIGSEGV or
trying to access nullpointer if value isnt present
then exception is thrown*/
std::optional<int> info(std::string arg="default"){
	if(arg=="first")return 1;
	else if(arg=="second")return 2;
	else if(arg=="third")return 3;
	return std::nullopt;
}
int main(){
	std::optional<int> res=info("first");
	std::optional<int> res1=info("fifth");
	try {
        std::cout<<res.value()<<" "<<res1.value(); // throws std::bad_optional_access
    } catch (const std::bad_optional_access& e) {
        std::cout << "Caught exception: " << e.what() << '\n';
    }
}