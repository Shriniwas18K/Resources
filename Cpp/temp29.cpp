#include<iostream>
#include<utility>
int main(){
	std::cout<<7/5<<"\t 7 and 5 are treated as long here\n"
	<<(float)7/5<<"\t 5 gets promoted to float implicitely,we done 7 to 7.0F explicitely\n";
	// we should be aware while casting that the resultant type should be capable of storing value
	// especially with the unsigned value, hence we can cast from any type to any type but the
	// resulting type should be capable of storing that casting value
	unsigned short x=97;// 9700 cannot fit into char
	char c=97;
	std::cout<<"\n"<<c<<"\t -1>0u : "<<(-1>0u);
	// be careful while comparing unsigned and signed values, as unsigned has always MSB as set
	// we cannot use our operators > to compare signed and unsigned values, we need to use
	// utility library operators cmp_greater which complete the purpose which are available
	// after C++20,else no option to compare between signed and unsigned
}