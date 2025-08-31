#include <iostream>
#include <numeric>
#include <iterator>
#include <array>
/*
modern cpp programmers prefer use of STL everywhere
hence instead of raw arrays and data structures
they prefer using the ones built into STL

std::array allocates memory and compile and is kind of
wrapper on C-style arrays providing utility methods
-> T at() for bounds checked access to prevent buffer overflow
-> T* data() for actually getting underlying pointer in memory
-> front(),back(),size(),empty(),max_size() utility methods

it allocates memory onto stack only, and size cannot be changed
onced declared, whereas vectors are dynamically sized heap based
*/

void print(int[],int);

int main() {
	// raw arrays
//	int arr[100];
//	std::iota(std::begin(arr),std::end(arr),18);
//	using iota algorithm to fill arrays
//	print(arr,10);
//	std::cout<<arr[1000]
//	<<"\n is perfectly allowed buffer overflow\n";
	{
		std::array<int,100> arr{};//list initialization
//		all values here initialized to 0
		arr.fill(18);
		int i=0;
		arr[18]=124454;
		for(auto it=arr.data();i<200;it++)
		{
			std::cout<<*it<<" ";
			i++;
		}
	}
}

void print(int a[],int n) {
	for(int i=0; i<n; i++)
		std::cout<<a[i]<<" ";
}