#include<iostream>

class UDT{
	int data;
	public:
		explicit UDT(int val){
			data=val;
		}
};
/*
There are multiple ways of initialising objects
from classes. Sometimes compiler performs implicit
type conversions which can be mysterious in long
run so we prefer to make our constructors explicit
and use list initialisation{}.
*/
int main(){
	UDT obj{500.1230f}; // compiler give error that it cant cast here
	UDT obj1(500.1230f);
	// here compiler converted val to 500 and object constructed
	UDT obj2{500};// compiler allows her object construction
}