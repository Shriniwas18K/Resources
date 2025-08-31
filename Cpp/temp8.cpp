#include<iostream>
#include<vector>
/*The rule of 5: we togetherly define all
these for some class
1) Constructors(default,parameterized) and Destructor
2) Copy Constructors
3) Copy assignment operator overload
4) Move Constructors
5) Move assignment operator overload
*/
class Vector3f{
		float x,y,z;
	public:
		Vector3f():x(0.0f),y(0.0f),z(0.0f){
			std::cout<<"Constructor invoked\n";
		}
		~Vector3f(){
			std::cout<<"Destructor invoked\n";
		}
		// const is optional in all constructors
		// Copy Constructor policy
		Vector3f(const Vector3f& rhs){
			std::cout<<"Copy Constructor invoked\n";
			this->x=rhs.x;this->y=rhs.y;this->z=rhs.z;
		}
		// Copy assignment operator policy
		Vector3f& operator=(const Vector3f& rhs){
			if(this==&rhs)return *this;
			this->x=rhs.x;this->y=rhs.y;this->z=rhs.z;
			// though the x,y,z are private members
			// still they are accesible from rhs as
			// its inside class member function
			std::cout<<"Copy assignment operator invoked\n";
			return *this;
		}
		// Move Constructor policy
		Vector3f(const Vector3f&& rhs){
			this->x=rhs.x;this->y=rhs.y;this->z=rhs.z;
			std::cout<<"Move constructor invoked\n";
			// it is used to grab resources of the rhs object
			// thus the lifetime of resources is controlled
			// by this current object, thus these can be used
			// to reduce memory allocations because in copy
			// constructors we allocate the memory again whereas
			// in move constructors we own the memory of rhs itself
		}
		// Move assignment operator policy
		Vector3f& operator=(const Vector3f&& rhs){
			if(this==&rhs)return *this;
			// similar to move constructor
			this->x=rhs.x;this->y=rhs.y;this->z=rhs.z;
			std::cout<<"Move assignment operator invoked\n";
			// check done to see we arent assigning the object to itself
		}
};
/* The STL containers move the objects to diffirent locations using
std::move hence the move constructor is invoked again, as well as
copy them so the copy constructors are also invoked again as seen
in program output, thus we should always prefer to use move semantics
and reduce redudant copying going on while execution*/
Vector3f return_value_optimisation(){
	std::cout<<"Object created inside method but its lifetime is beyond it\n";
	Vector3f vec;
	return vec;
}
int main(){
	Vector3f res=return_value_optimisation();
	std::cout<<"Object is existing outside method due to some sort of compiler optimisations\n";
	std::cout<<"This is called as return value of optimisation\n";
	std::vector<Vector3f> vec1;
	std::vector<Vector3f> vec2;
	for(int i=0;i<5;i++){
		Vector3f obj;
		vec1.push_back(obj);// copy constructor invokes and memory allocation doubles
		vec2.push_back(std::move(obj));//move constructor invokes and memory allocation is only as per requirement
	}//always prefer to use move semantics because it reduces need of copying everywhere thus memory and performance efficient
}