#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
// data races occur when two or more threads
// access the same memory location where
// atleast one writes the memory, we need
// mutexes for handling them, they can be
// easily discovered

// race condition is flaw in timing or
// ordering in program execution showing
// undefined behavior, depends on the
// ordering of threads in acquiring of
// mutexes ,and they arent easily
// discoverible as they are random,
// recommended is to use sleep statements
// to modify timing and execution order
// in order to detect them

// race conditions are caused by data races
// but they are both independent things
// we can have either of them

// race conditions are heisenbug
std::mutex pencil;
unsigned long bag_of_chips=0L;
void cpu_work(unsigned long workUnits){
	unsigned long x=0;
	for(unsigned long i;i<workUnits*10000;i++)
		x++;
}
void barron_shopper(){
	cpu_work(1);
	std::unique_lock<std::mutex> lock(pencil);
	bag_of_chips*=2;
	printf("Barron DOUBLES the number of chips\n");
}
void olivia_shopper(){
	cpu_work(1);
	std::unique_lock<std::mutex> lock(pencil);
	bag_of_chips+=3;
	printf("Olivia ADDS the bag of chips\n");
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
