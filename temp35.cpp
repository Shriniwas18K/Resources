#include<iostream>
// using keywoprd in cpp
// the typedef in C becomes using in CPP
using void_t=void;
void_t temp(){

}
template<typename T,int>
struct DataStructure{
	static void info(){
		std::cout<<"info\n";
	}
};
using Int10=DataStructure<int,10>;

template<typename T>
using Any10=DataStructure<T,10>;

int main(){
	temp();
	{
		using namespace std;
		cout<<"scoped usage of using namespace\n";
	}
	{
		using std::cout;
		cout<<"specific usage of using\n";
	}
	Int10::info();
	Any10<double>::info();
}