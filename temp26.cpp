#include<iostream>
#include<variant>
// variants are typesafe unions
// sometimes we try to access the
// data memebrs in the union which
// arent having any initialsed
// values which doesnt give any error
// rather gives random values, but
// to prevent those we use type safe
// version of unions called as variants
// which give error when accessing
// uninitialized members, they are
// slightly slow but yet safe and
// use templates and class based
// implementation underhood
int main(){
	std::variant<int,float,double> u;
	u=97.0f;
	std::cout<<get<float>(u)<<" ";
	// using int,double gives error
	// as they arent initialised
	u=99.0;
	std::cout<<get<double>(u);
}