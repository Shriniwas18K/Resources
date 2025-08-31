/* interfaces files are hpp which contain only method
signatures and classes signatures. when we use #include
then essentially the code is copy pasted, and if twice
the same code gets copy pasted and variables already
defined errors come.Hence we use header guards as below.
The interface files are included before compilation
and the implementation files are included during compilation
and infact they can be already kept compiled and included
directly by linker.
*/
#ifndef TEMP5_additionals_HPP
#define TEMP5_additionals_HPP
int sum(int,int);
class UDT{
	public:
		UDT();
		void printInfo();
		~UDT();
};
#endif