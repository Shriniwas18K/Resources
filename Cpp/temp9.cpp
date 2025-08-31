#include<iostream>
/* Generally we shouldnt use the friend
functions and classes.They are indications
of improper API design. It is only useful
for operator overloading. Even custom classes
can have same name as the one declared as
friend so they can be code smell. Hence friend
functions and classes are rarely used in cpp
*/
class SecureClass{
	private:
		int data=18;
		friend class FriendClass;
};
class FriendClass{
	public:
		void print(SecureClass& obj){
			std::cout<<"Secure private data accessed by friend : "<<obj.data;
		}
};
int main(){
	FriendClass obj1;
	SecureClass obj2;
	obj1.print(obj2);
}