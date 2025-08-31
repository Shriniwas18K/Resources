#include<iostream>

// similar to std::array we made our container
template<typename T,int n>
class Container{
	public:
		T data[n];
		static T m_val;
};
// each generated class has its own static variable
template<typename T,int n>
T Container<T,n>::m_val;

int main(){
	Container<int,10> c1,c2;
	Container<int,10>::m_val=18;
	Container<float,10> c3;
	Container<float,10>::m_val=37;
	std::cout<<Container<int,10>::m_val<<" "
		<<Container<float,10>::m_val;
}