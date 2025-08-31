#include<iostream>
//templates gnerate code at compile time
//and similar compile time evaluation is
//done using constexpr which is indeed
//const modifier with indication to the
//compiler to evaluate the function call
//anything that is fixed and can be done
//at compile time rather than runtime
//which saves us many function calls and
//data movements between registers
constexpr int add(int a,int b){
	return a+b;
}//here add function get evaulated at
//compile time itself and not at runtime
//hence we save stack memory and function
//calls and register movements,but the
//constexpr is suggestion for compiler
//and it may evaluate at compile time
//only if the result is fully deterministic
int main(){
	constexpr int i=add(9,9);
}