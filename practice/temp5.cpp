#include<iostream>
struct Ancestor{
	virtual void test()=0;
};
struct Base:public Ancestor{
	int i;
	explicit Base(int k):i{k}{
		std::cout<<"Base Constructor\n";
	}
	virtual void test() override{
		std::cout<<"Base Test\n";
	}
	static void info(){
		std::cout<<"Base Info\n";
	}
	virtual ~Base(){
		std::cout<<"None\n";
	}
};
struct Derived:public Base{
	int j;
	explicit Derived(int a,int b):Base(a),j{b}{
		std::cout<<"Derived Constructor\n";
	}
	void test() override{
		std::cout<<"Derived Test\n";
	}
	static void info(){
		std::cout<<"Derived Info\n";
	}
	~Derived(){
		std::cout<<"Derived Destructor\n";
	}
};
int main(){
	{
		Base b(18);
		Derived d(37,97);
	}std::cout<<"Stack allocated objects done\n";
	{
		Base* b_ptr=new Derived(18,37);
		b_ptr->info();// static methods are invoked depending on reference type
		b_ptr->test();// instance methods are invoked depending on object type
		Derived* d_ptr=static_cast<Derived*>(b_ptr);
		d_ptr->info();
		d_ptr->test();
		delete d_ptr;
	}
}