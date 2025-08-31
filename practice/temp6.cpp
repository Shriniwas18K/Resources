#include<iostream>
#include<initializer_list>
struct A{
	A()=default;
	~A()=default;
	A(const A&)=delete;// this will not allow to create copy of A objects at all
	[[deprecated("Use Child Implementations")]]
	virtual void info(){
//		if(likely(2+2==4)){ C++20
			// likely informs compiler that usually this branch will be
			// exceuted most often so it optimizes it in code generation
			std::cout<<"Info(A)\n";
//		}
	}
};
struct B:virtual public A{
	virtual void info() override{
		std::cout<<"Info(B)\n";
	}
};
struct C:virtual public A{
	virtual void info() override{
		std::cout<<"Info(C)\n";
	}
};
struct D final:public B,public C{
	void info() override final{
		std::cout<<"Info(D)\n";
	}
	void methodUsingInitialiserList(std::initializer_list<int> ls){
		for(const int i:ls)
			std::cout<<i<<" ";
	}
};
[[nodiscard]]
int test(){
	return 37;
}
//[[noreturn]] for function which always throws exception
// noexcept for function which never thorws exception
int main(){
	D obj;
	obj.A::info();
	obj.B::info();
	obj.C::info();
	obj.info();
	obj.methodUsingInitialiserList({1,3,5,6,7});
	std::cout<<"\n"<<test();
	// structured bindings
	auto [a,b]=std::pair<int,int>{1,2};
	std::cout<<" "<<a<<" "<<b;
}