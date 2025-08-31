#include<iostream>
//in-class initializer
class Entity{
	public:
		int x{4};
		int y{890};
		}
//		int y {5.7889}; type conversion isnt allowed in {}
		int* arr{nullptr};
		Entity():x{7}{
		}
};
// first the initialisation of inplace values
// second the constructor member initialiser list
// third the constructor body executes
int main(){
	Entity e;
	std::cout<<e.x<<" "<<e.y;
}