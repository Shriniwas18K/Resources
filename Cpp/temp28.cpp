#include<iostream>
#include<cassert>
// auto keyword should be used only when needed
// where the is very obvious to know for compiler
int main(){
	int age=7;
	// runtime error checking using macro assert
	// part of cassert library
	assert(age>0 && "age should be positive");
	// compile time error checkign using
	// static_assert builtin cpp , used
	// only with const and constexpr conditions
	constexpr int res=2+2;
	static_assert(res==4,"2+2 should be equal to 4");
	// mostly used for hardware architecture checking
	// before compilation of the program
}