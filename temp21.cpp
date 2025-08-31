#include<iostream>
// overload of function generated at compile time
template<typename T>
T square(T x){
	return x*x;
}
// in modern cpp, it also generates overloaded functions
auto cube(auto x){
	return x*x*x;
}
template<typename T,
	int N // using such non-object types here in template parameters
	// generates multiple overloads one for each value of N at compile time
>
void print(){
	std::cout<<"\noverload number "<<N;
}
int main(){
	std::cout<<square(5.5)<<" " // automatic types inferred
			<<square<int>(5.5)<<" " // type casted arguements
			<<cube(9)<<"\n";
	print<int,1>();
	print<double,2>();
	print<float,3>();
}