#include<iostream>
#include<thread>
#include<mutex>
// LIVELOCK looks similar to deadlock, it
// occurs when two or more threads are competing
// to resolve the stuff, it occurs when threads
// are designed to respond actions of each other
// all threads are busy doing something but
// combination of their efforts reuslts in nothing
// this occurs usually in deadlock resolution algos
// if many process or threads go to resolve the
// deadlock then the over effort causes livelock of threads
// use random selection to resolve deadlocks which
// prevents from livelocks

// In livelock CPU utilisation is maximum whereas in
// deadlock CPU utilisation is minimum hence livelock

// in below example threads are constantly picking
// up and putting down chopsticks causing livelock
// this can be resolved by calling yeild() on thread
// which puts down chopstick i.e. releases lock which
// now causes it to wait for moment and reschedule its
// execution, the implementation of yeild depends on OS
int sushi_count=100;
void philosopher(std::mutex& first_chopstick,std::mutex& second_chopstick){
    while(sushi_count>0){
		first_chopstick.lock();
		if(!second_chopstick.try_lock()){
			first_chopstick.unlock();
			std::this_thread::yield();
		}else{
			sushi_count--;
			second_chopstick.unlock();
			first_chopstick.unlock();
		}
	}
}
int main(){
	std::mutex chopstick_a,chopstick_b;
	std::thread barron(philosopher,std::ref(chopstick_a),std::ref(chopstick_b));
	std::thread olivia(philosopher,std::ref(chopstick_a),std::ref(chopstick_b));
	std::thread steve(philosopher,std::ref(chopstick_a),std::ref(chopstick_b));
	std::thread nikki(philosopher,std::ref(chopstick_a),std::ref(chopstick_b));
	barron.join();
	olivia.join();
	steve.join();
	nikki.join();
	printf("philsophers done eating");
}