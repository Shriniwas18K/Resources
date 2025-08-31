#include<iostream>
// template specialisation
template<typename T>
bool equal(T a,T b){
	return (a==b);
}
// when we need custom version with special
// implementation then compiler detects it
// and doesnt generate overload for the
// having same signature as this version
template<>
bool equal(float a,float b){
	std::cout<<"\nfloat version : ";
	return labs(a-b)<0.000001f;
}
template<>
bool equal(double a,double b){
	std::cout<<"\ndouble version : ";
	return abs(a-b)<0.000001;
}
int main(){
	// we would have needed to write equal<float> or equal<double>
	// but compiler since C++17 has CTAD compiler template
	// arguement deduction or type inferencing here
	std::cout<<equal(1.0000f,1.000f)<<equal(1.000,1.000);
}