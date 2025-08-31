#include<iostream>
#include<initializer_list>

// initializer list is temporary array that is used for
// fast initialization,infact it is more lighter than arrays
class Entity{
	public:
		Entity(std::initializer_list<int> ls){
			std::cout<<"\nInitializer list invoked here\n";
			for(int i:ls)
				std::cout<<i<<"\t";
		}
		Entity(int i,int j){
			std::cout<<"\nParameterized Constructor invoked\n"
			<<"i="<<i<<" j="<<j<<"\n";
		}
};
// compiler first checks is direct parameterized constructor found
// else it will go for initializer list, when {} are used then it
// will look for initializer list based constructor else it will
// zero initialize the values in the object
int main(){
	Entity e{};
	Entity e1{1,2,3};
	Entity e2(1,2);
}