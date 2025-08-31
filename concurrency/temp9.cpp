#include<iostream>
#include<mutex>
#include<thread>
// deadlocks are situations of programs
// where there is cyclic or infinite waiting
// for availalbility of resources between
// processes and threads

// dining philosophers : each philospher needs
// needs two his own exclusive chopsticks to
// eat sushi
// the deadlock is overcomed by assiging same
// priorities to mutexes both the philosphers take
int sushi_count{500};
// nesting locks may create deadlocks

// to prevent deadlocks we used here lock ordering in 1)
// but the threads might not know ahead of time which lock
// to acquire so we need another mechanism called scoped locks

// scoped_lock object takes ownership of one or more mutexes
// in the scope in which it was created and it has builtin
// deadlock avoidance algorithm when it is used to acquire
// multiple mutexes at once, those mutexes are automatically
// released once execution goes out of scope

void philosopher(std::mutex& first_chopstick,std::mutex& second_chopstick){

    while(sushi_count>0){
		first_chopstick.lock();
		second_chopstick.lock();
		sushi_count--;
		second_chopstick.unlock();
		first_chopstick.unlock();
	}

/*
	while(sushi_count>0){
		std::scoped_lock lock(first_chopstick,second_chopstick);
		sushi_count--;
	}
*/
}
int main(){
	std::mutex chopstick_a,chopstick_b;
	std::thread barron(philosopher,std::ref(chopstick_a),std::ref(chopstick_b));
	std::thread olivia(philosopher,std::ref(chopstick_a),std::ref(chopstick_b)); // 1)
//	std::thread olivia(philosopher,std::ref(chopstick_b),std::ref(chopstick_a));
//  above is also free from deadlock if used with scoped_lock which is C++ 17 onwards
	barron.join();
	olivia.join();
	printf("philsophers done eating");
}