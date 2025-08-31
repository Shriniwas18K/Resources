#include<iostream>
#include<string>

struct Entity{
//	Entity():name(""),x(0),y(0){
//	}
	Entity()=default;
	std::string name;
	int* collection;
	int x,y;
};
/*zero initialisation stratergies when object is created with {}
1) use constructor then assign fields to 0 in it or use member initialiser lists
2) use constructor()=default
3) dont write constructor itself
*/
int main(){
	Entity e;
	std::cout<<e.name<<" "<<e.x<<" "<<e.y<<" "<<e.collection<<"\n";
	//uninitialized variables give random values or 0 for int variables
	//for uninitialised string we have empty string
	Entity e1{};
	std::cout<<e1.name<<" "<<e1.x<<" "<<e1.y<<" "<<e1.collection;
}