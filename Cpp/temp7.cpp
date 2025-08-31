#include<iostream>
#include<ostream>
class Vector3f{
	public:
		float x,y,z;
		Vector3f& operator+(Vector3f& opr){
			Vector3f* res=new Vector3f();
			res->x=this->x+opr.x;
			res->y=this->y+opr.y;
			res->z=this->z+opr.z;
			return *res;
		}
		float operator[](std::size_t idx){
			if(idx==0)return this->x;
			else if(idx==1)return this->y;
			else return this->z;
		}
};
/*RAII means the classes which allocate resources in
constructors and free them all in destructors hence
dont require explicit cleanup*/
std::ostream& operator<<(std::ostream& os,const Vector3f& obj){
	std::cout<<"\nx : "<<obj.x<<"\ny : "<<obj.y<<"\nz : "<<obj.z;
	return os;
};
constexpr bool operator==(const Vector3f& lhs,const Vector3f& rhs){
	return (lhs.x==rhs.x)&&(lhs.y==rhs.y)&&(lhs.z==rhs.z);
};
struct Vector{
	float x,y,z;
	// structs have everything always public, remaining everything they
	// have similar to classes, this,constructor,copy assignment operator,
	// everything is similar to classes.
	// the only thing is structs cannot ber inherited or extended
};
int main(){
	Vector3f a,b;
	a.x=a.y=a.z=5;
	b.x=b.y=b.z=3;
	std::cout<<"a+b : "<<a+b;
	std::cout<<"\na==b:"<<(a==b ?"true":"false");
}