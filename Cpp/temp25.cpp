#include<iostream>
// union objects have size of the
// largest data type stored in them
// irrepesctive of whatever is
// instantiated in them, and they
// store only one data member at a time
union Entity{
	double y;//8bytes
	int x;// 4bytes
	float z;// 4bytes
};
// here even though we optimized data layout
// still it will take 8bytes memory only

// unions can have functions,constructors,
// and static etc all things but we cant
// use union as base classes
int main(){
	Entity u;
	std::cout<<sizeof u<<" ";
	u.x=18;u.y=900.00001;u.z=989898989898989.0f;
	std::cout
		<<"\nx="<<u.x
		<<"\ty="<<u.y
		<<"\tz="<<u.z
		<<"\n"<<alignof(u);
	// u.x was stored first in those 8bytes
	// which was removed when u.y was written
	// wherein again u.z had enough space to
	// occupy so it was written well

	// only last written member is stored
	// properly in union is concrete as
	// every member in union is stored at
	// same address rather the struct store
	// each member at diffirent address from
	// the insights of compiler explorer
} 