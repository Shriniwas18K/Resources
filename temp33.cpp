#include<iostream>
#include<vector>
#include<algorithm>
// functors are very useful they are functions with state/data
// function object : functor
// key is operator() and the idea is to store partial computation result
// lambdas are builton top of functor
struct Value{
	int m_result{0};
	int operator()(int newResult){
		m_result=newResult;
		return newResult;
	}
	bool operator<(const Value& val){
		return this->m_result<val.m_result;
	}
};
struct ValueComparator{
	// these comparators are passed into STL functions
	bool operator()(const Value& lhs,const Value& rhs)const{
		return lhs.m_result<rhs.m_result;
	}
};
static int global=18;

struct Example{
	void info(){
		std::cout<<"\nm_data="<<m_data<<" ";
		auto temp=[*this]()mutable{
			// only since C++17
			// if we access the members of class/struct/union
			// inside the lambda inside them then we need to
			// capture the current instance using 'this' which
			// captures everything inside instance by reference
			// *this captures everything inside instance by value
			// creating local copy inside lambda
			// =,& cannot be used here inside lambda inside c;asses
			m_data=37;
			std::cout<<"m_data : "<<m_data;
		};
		temp();
	}
	int m_data=18;
};

int main(){
	Value v;Value v1;v1(97);
	int res=v(18);
	std::cout<<res<<"\nv<v1 : "<<(v<v1)<<"\n";
	std::vector<Value> vec{v,v1};
	std::sort(vec.begin(),vec.end(),ValueComparator());
	std::for_each(vec.begin(),vec.end(),[](Value& v){
		std::cout<<v.m_result<<" ";
	});// small functions inplace can be made as lambdas
	// we can also store functions in variables
	auto print_vec=[](Value& v)->void{
		std::cout<<v.m_result<<" ";
	};
	std::sort(vec.begin(),vec.end(),[](const Value& lhs,const Value& rhs){
		return lhs.m_result>rhs.m_result;
	});// the lambda is translated to that comparator above kind
	std::for_each(vec.begin(),vec.end(),print_vec);
	// we can capture the variables in the scope where lambda is declared
	int sum=0;
	std::for_each(vec.begin(),vec.end(),[&sum](const Value& v){
		sum=sum+v.m_result;
	});
	std::cout<<"\nsum="<<sum;
	// [] in lambdas are captures
	auto temp=[](int n){
		global=37;
		std::cout<<"n="<<n;
	};
	// it is actually function pointer void(*temp)(int), same C-style function pointer
	// as this lambda doesnt capture any variable from enclosing scope

	// when lambdas capture the variables in enclosing scope then it is translated
	// to functors, &variable means call by reference into lambdas
	int j=18;
	auto temp1=[&j](){
		j=37;
	};
	std::cout<<j<<" ";//37

	// when lambdas capture variables directly then they are meant as read only
	// but there is copy or call by value being passed to the lambda and if it
	// wants to modify that copy then it should state it as mutable
	auto temp2=[j]()mutable{
		j=18;
		std::cout<<j;
	};

	// [&] means capturing all the variables by reference into lambda
	// [=] means capturing all the variables by value into lambda
	// use cppinsights to see lambdas translation into functors

	// the global and static variables stay throughout program
	// so we can modify them as it is lambdas without =,&
	std::cout<<"\nglobal="<<global;
	Example e;
	e.info();
}