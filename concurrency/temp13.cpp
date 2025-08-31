#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
// sometimes some thread wastes energy repeatedly
// acquiring mutex and releasing it waiting for
// certain condition to continue to execute into
// critical section, in other words to execute
// the critical section the thread needs to satisfy
// some other condition apart from the acquiring
// the mutex, this is limitation of mutex that it
// though restricts multiple threads from accessing
// critical section at a time but it doesnt give any
// way to signal threads to coordinate their actions
// and to do that we can use condition variable which
// serves as queue waiting for certain condition to
// occur to execute, it is place to wait and get
// notified to execute when certain condition occurs
// it is associated with mutex, and these work together
// to create construct called as monitor

// monitor is construct which protects critical section
// with mutual exclsuion or mutex and provides ability
// for threads to wait until a condition occurs along
// with mechanism to signal between those threads

// monitor is room with procedures and shared data in
// which only one thread can enter at a time and is
// protected by mutex, and till one thread is inside
// other threads keep waiting for execution in the
// conditional variable or waiting room for some
// condition to occur before they enter the monitor room
// or there may be multiple waiting room or conditional
// variables to acquire that same mutex

// the thread inside critical section executes and
// releases the mutex and signals the condition variable
// which allows one of threads waiting in it to execute by
// acquiring the mutex

// before using the condition variable thread needs to acquire mutex
// each condition variable has three operations : wait(),signal(),broadcast()
/* wait() : when called by thread then it automatically releases lock/mutex
			and goes to sleep and enters waiting queue, it reacquires lock
			when woken up, till that duration some other thread can acquire
			the mutex and use it by using signal() operation
*/
/*signal() : wakes up one thread from conditional variable queue, depending
			on language it is also called as notify() or wake()
*/
/*broadcast() : similar to signal operation except that it wakes up all the
 			threads at the waiting queue
*/
// in shared queue or buffer we need multiple conditional variables where
// multiple threads are accessing the same buffer then it need mutex to
// ensure that only one thread can add or remopve items from it at a time
// where we can have two conditional variables : BufferNotFull,BufferNotEmpty
// BufferNotFull : if thread needs to add an item then it has to wait for this variable to satisfy
// BufferNotEmpty : if thread needs to remove an item then it has to wait for this variable to satisfy
// these conditional variables help the threads to signal each other and update the state of shared queue
int soup_servings=100;
constexpr int NUMBER_OF_PEOPLE=10;
std::mutex slow_cooker_lid;
std::condition_variable soup_taken_by_some_other_thread;
void thirsty_person(int id){
	int put_lid_back=0;
	/* // this code shows how the threads waste energy acquiring and releasing mutex
	while(soup_servings>0){
		std::unique_lock<std::mutex> lid_lock(slow_cooker_lid); // mutex scoped onto this while loop
		if(id==soup_servings%NUMBER_OF_PEOPLE && soup_servings>0){ // condition
			soup_servings--; // critical section executed when condition satisfied
		}else{
			put_lid_back++;// if condition not satisfied even though mutex is acquired
		}
	}*/
	while(soup_servings>0){
		std::unique_lock<std::mutex> lid_lock(slow_cooker_lid); // mutex scoped onto this while loop
		while(id!=soup_servings%NUMBER_OF_PEOPLE && soup_servings>0){ // if condition not satisfied
			put_lid_back++;
			soup_taken_by_some_other_thread.wait(lid_lock);
		}// while the condition isnt satisfied the thread has to wait
		// once the condition is satisfied it can execute the critical section
		// and mutex is acquired here and released once the execution goes out
		// of scope, we can use notify_one() in case of two threaded program
		if(soup_servings>0){
			soup_servings--;
			soup_taken_by_some_other_thread.notify_all();
		}
	}
	printf("Person %d put back lid %d times\n",std::this_thread::get_id(),put_lid_back);
}
int main(){
	std::thread threads[NUMBER_OF_PEOPLE];
	for(int i=0;i<NUMBER_OF_PEOPLE;i++)
		threads[i]=std::thread(thirsty_person,i);
	for(int i=0;i<NUMBER_OF_PEOPLE;i++)
		threads[i].join();
	printf("All people are well fed");
}