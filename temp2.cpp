#include<iostream>
#include<functional>
void print(int array[]){
	std::cout<<"size of array is "<<sizeof array<<" bcoz it is pointer";
}

void indian(){
	std::cout<<"namaste";
}
void american(){
	std::cout<<"highfive";
}
int main(){
	int x=10;
	int* ptr=&x;//stores addresses
	/*Every pointer has memory
	of 4bytes on 32bit system and 8bytes
	on 64 bit system. Types are written
	in source code for convinience of users
	but pointer is simply integer in hexadecimal
	format in range of 32 to 64 bit unsigned.

	memory (RAM) is assumed internally as linear
	number line from 0x000000 to 2^32 or 2^64*/
	std::cout<<*ptr<<" and size of "<<sizeof ptr;

	/*pointers are mainly used for dynamic memory
	allocation on heap using new keyword*/

	int* p_x=new int(9090);
	std::cout<<"\ndynamically allocated integer : "<<*p_x;
	delete p_x;
	int* arr=new int[10];
	int i=0;
	while(i<10)std::cout<<*(arr+i++)<<" ";
	delete[] arr;
	/* arrays variables are pointers to the
	contigous memory allocated both in stack and heap*/
	int  a1[100];
	int* a2=new int[10];
	// the memory is automatically reclaimed when
	// execution goes out of scope
	// whenever we pass any kind of arrays into
	// functions then they are always passed by
	// reference i.e. they decay to pointers
	// and thence we cannot determine the number of elements
	// in array which is passed arguement into the function
	// hence many codebases show size_t n variable is
	// passed to function taking array with its number
	// of elements. Thus raw arrays are always passed
	// by reference hence no copying involved. But we
	// can pass by value using std::vector and std::array.
	print(a1);
	/* function pointers can be used in dynamic function
	overloading at runtime, event driven programming,GUIs*/
	void(*fptr)(void)=nullptr;
	std::cout<<"\nenter your way (1/2):";
	int way;
	std::cin>>way;
	switch(way){
		case 1:
			fptr=indian;
			break;
		case 2:
			fptr=american;
			break;
	}fptr();
	// in more cleaner syntax to above fptr declaration we use
	std::function<void(void)> fptr1=nullptr;
	fptr1=indian;
	fptr1();
}