#include<iostream>

struct Entity{
	mutable int j;
	void print(const int& a,const int& b)const{
		j=37;
		std::cout<<"a="<<a<<" b="<<b<<"\n";
	}
};

int main(){
	Entity e;
	e.print(9,9);
	std::cout<<"j="<<e.j;
}
// if we declare some variable as const
// then essentially we cannot modify the
// value of variable after initialisation
// i.e. the reference cannot point to
// somewhere else because indeed variables
// are just referencing value literals
// int i=18;
// 18 is integer literal,i is reference to it

// below is valid only for member functions of structs or classes

// we can add const modifier in function header
// which indicates that we cannot mutate any
// parameters in the struct or class where function
// is present but still some of them can be modified
// by declaring them mutable outside the function