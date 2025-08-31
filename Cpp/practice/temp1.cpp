#include<iostream>
#include<functional>
/*
1) std::array allocates on stakc
at compile time and is used over
raw arrays as it provides utility
methods similar to vector and is
wrapper on raw arrays

2) references are aliases for the
variables and are created using &

3) & is addressof operator and has
two uses, for making references and
address extraction in making pointers

4) we use decltype to create objects of
types without actually writing them
completely thus more readable

5) pointers are types which store addresses
of objects or anything in cpp at runtime,
depending on 32bit(4byte pointer) or 64bit
(8 byte pointer) OS the pointer variable
has its size, which can be seen using sizeof
operator

6) pointers are used for runtime dynamic memory
allocation on heap using new operator and free
it using delete operator

7) all variables declared on stack, i.e.
without using new operator have lifetime
only in the execution scope where they
are declared

8) raw arrays convert to pointers when passed
as function arguements which makes them unable
to determine size hence in all old codebases
we see the array and its size are passed together
in the function arguements, and also arrays are
always passed by reference hence any changes
inside function to array affect everywhere
throughout array lifetime and no copying, and
raw arrays which are allocated on stack have
lifetime only in the execution scope where they
are declared,whereas the raw arrays on heap remain
allocated throughout program execution unless
explicitely deallocated using delete[]
operator,arrays are themselfs hence
pointers and they are contigous memory locations

9) we use function pointers for runtime dispatch
of functions of same signature using std::function
*/
void print(int*,int);
void info(){
	std::cout<<"\ninfo\n";
}
void desc(){
	std::cout<<"\ndesc\n";
}
int main(){
	int i{18};
	int& j{i};// alias j=i=18;
	std::cout<<&j<<" = "<<&i<<"\n";// references are pointing to same object 18
	decltype(i) k{37};
	void* ptr{&i};
	int* ptr1{&k};
	std::cout<<ptr<<" "<<sizeof ptr<<" and "<<ptr1<<" "<<sizeof ptr1<<"\n";
	{
		int raw_array_on_stack[10];
		int* alias=raw_array_on_stack;
		for(int i=0;i<10;i++)alias[i]=i;
		print(raw_array_on_stack,10);
	}
	std::function<void(void)> ptr2{};
	int v;std::cout<<"1 or 2 : ";
	std::cin>>v;
	switch(v){
		case 1:
			info();
			// falling into switch loop
			[[fallthrough]]
		case 2:
			desc();
			break;
		default:
			std::cout<<"\ndefault case\n";
	}
}
void print(int raw_array[],int n){
	for(int i=0;i<n;i++)
		std::cout<<raw_array+i<<" : "<<raw_array[i]<<"\n";
}