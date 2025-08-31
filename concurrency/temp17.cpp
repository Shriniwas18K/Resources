#include<iostream>
#include<thread>
#include<boost/thread/barrier.hpp>
// to prevent race conditions we use
// synchronisation mechanism called
// barriers, all threads need to reach
// the stage of barrier before proceeding
// ahead, before it threads might be
// doing anything

// this enforces runtime ordering of threads
// irrespective of scheduling of threads

// these arent part of C++20 so we need to
// use them through boost collection of libraries

// here first olivia will add +3 to all chips
// then barron will double the chips, and then
// on every execution the output will be 512

// similar to barriers we have latches, where
// stage is reached when the count reaches 0,
// threads can reduce count value by using
// count_down(), whenever stage is reached
// then barrier or latch releases, hence we
// need to initialise calculate the count value
// in the latch constructor

// the tasks that can be executed parrallely
// irrespective of thier ordering are called
// as asynchronously executed tasks or they

// also we have thread pools to prevent the
// repeated thread lifecycle management and
// abstract it similar to ExecutorServices
// and Executors in Java

// all are experimental in C++20 and hence
// can be used as part of boost libraries
std::mutex pencil;
boost::barrier fist_bump;
unsigned long bag_of_chips=0L;
void cpu_work(unsigned long workUnits){
	unsigned long x=0;
	for(unsigned long i;i<workUnits*10000;i++)
		x++;
}
void barron_shopper(){
	cpu_work(1);
	fist_bump.wait();
	// below executed after wait completes,i.e. all threads reach stage 1
	std::unique_lock<std::mutex> lock(pencil);
	bag_of_chips*=2;
	printf("Barron DOUBLES the number of chips\n");
}
void olivia_shopper(){
	cpu_work(1);
	{
		std::unique_lock<std::mutex> lock(pencil);
		// lock only the critical section else threads
		// would keeping waiting as well as keep it acquired
		bag_of_chips+=3;
	}
	printf("Olivia ADDS the bag of chips\n");
	fist_bump.wait();
}
int main(){
	std::thread shoppers[10];
	for(int i=0;i<10;i+=2){
  		shoppers[i]=std::thread(olivia_shopper);
  		shoppers[i+1]=std::thread(barron_shopper);
	}
	for(int i=0;i<10;i++)shoppers[i].join();
	printf("Bag of chips has %d chips",bag_of_chips);
}
