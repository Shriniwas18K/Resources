#include<iostream>
#include<string>
/* lvalues are identifiers or something that is
associated with some kind of memory address.
rvalues are something that arent associated with
memory address.
amongst rvalues we have temporary rvalues which
are intermeddiate results  by copying the result
of some arithmetic calculation stored onto some
register in asm code and called as xrvalues.
remaining all are pure rvalues or prvalues.

lvalue_references are used to point lvalues.

rvalue_references are used to avoid redudant copying
occuring above from registers in asm code and directly
store the result of calculations, they are used when
some rvalue is expensive to copy hence we pass it by
pass by reference (rvalue reference).
*/
void delobject(std::string&& s){
	std::cout<<"\nobject is deleted here as it goes out of scope upon execution of method and it is created on stack, for objects on heap there will be memory leaks if not deleted with delete keyword\n";
}
void modifyobject(std::string& s){
	std::cout<<"\nmodified object";
	s[0]='@';
}
int main(){
	int x=10;
	std::cout<<"x is lvalue and 10 is prvalue here";
	int y=20;
	int z=x+y;
	std::cout<<"\nz is lvalue and (x+y) is xrvalue here after copying\n";

	int& lref_x=x;
//	lref_x is lvalue reference and it can point to lvalue only
//  lvalue reference is just alias only, the underhood object is
//  owned by lvalue variable itself
	int&& rref_z=x+y;
//	rref_z is rvalue reference of (x+y) which directly stores the
//	the result of operation without copying onto registers

//  we can use rvalue_reference to transfer the ownership of
//  values from one variables to another
	std::string s1="very long long string";
	std::string s2;
	std::cout<<"s1 : "<<s1<<"\ns2 : "<<s2<<"\n";
//  now we need to transfer ownership of s1 value to s2 value
//  hence we use rvalue_reference static cast here
	s2=static_cast<std::string&&>(s1);
//  now here s2 owns object owned by s1 and s1 becomes uninitialized
	std::cout<<"s1 : "<<s1<<"\ns2 : "<<s2<<"\n";
//  more convinient way of above syntax is
//	s2=std::move(s1);

//  we can pass both lvalue_reference and rvalue_reference as
//  method parameters both are considered as pass by reference
//  but in lvalue reference the ownership of object isnt passed
//  but in rvalue reference the ownership of object is passed
//  the address of object is passed in both cases.
//  the variable having address can modify the object but the
//  variable owning object can also delete the object.
	modifyobject(s2);
	delobject(std::move(s2));
}