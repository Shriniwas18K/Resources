#include<iostream>
struct Entity{
	int x{100};
	int y{200};
	int z{300};
};// 12bytes
int main(){
	auto x=37;// value considered as long
	// for making values as specific types
	// we use suffixes
	// u or U for unsigned
	// l or L for long
	// f or F for float
	// always consider explicitely putting suffixes
	float y=37.00;// value was considered as double which was casted to float

	// reinterpreted casts are only used for single reading or writing of file
	// they are used to move bits level,i.e. if source and destination type
	// bits are matched then it is valid, and also sometimes rather to initialize
	// objects from the files or other objects instead of copy constructors
	Entity e{};
	char bytes[sizeof e];
	memcpy(bytes,&e,sizeof e);
	std::cout<<*(int*)(bytes+12)<<"\n";
	std::cout<<*reinterpret_cast<int*>(bytes+12)<<" "
		<<*reinterpret_cast<bool*>(bytes+12)<<"\n";
	Entity* e1;e1->x=900;e1->y=950;e1->z=900;
	e=*reinterpret_cast<Entity*>(e1);
	std::cout<<e.x<<" "<<e.y<<" "<<e.z;
	// e becomes entity e1,shallow copying using reinterpret_cast
}