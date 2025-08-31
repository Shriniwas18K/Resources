#include<iostream>
// code duplication can be removed using
// the delegating constructors
class Entity{
public:
	std::string name;
	int x;
	int y;
	Entity():x{7},y{8}{}
	Entity(std::string _name):Entity()
//	,y{890} not allowed with delegate constructor
	{
		name=_name;
	}
};
// all the startup code goes into default
// constructor and the parameterized ones
// delegate the initialization to it
int main(){
	Entity e{"mike"};
	std::cout<<e.name<<" "<<e.x<<" "<<e.y;
}