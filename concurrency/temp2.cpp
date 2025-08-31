#include<iostream>
#include<thread>
#include<chrono>
// is cpp thread creation itself starts running it
// every thread has four states :
// 1) new 2) runnable 3) blocked 4) terminated
// 1) new : when the thread is created
// 2) runnable : when start() is called on thread, but in cpp
//     thread creation itself takes it to runnable state, and also
//     when its wait from blocked state is finished
// 3) blocked : when thread is waiting for some event to complete
// 4) terminated : thread execution completed or its abruptly aborted
void task(){
	printf("Child Thread running\n");
	printf("Child Thread enters blocked state\n");
	std::this_thread::sleep_for(std::chrono::seconds(10));
	printf("Child Thread running\n");
	printf("Child Thread completed\n");
}
int main(){
	printf("Main Thread running\n");
	std::thread childThread(task);
	printf("Main Thread running when Child Thread is running\n");
	printf("Main Thread waiting for Child Thread to complete\n");
	childThread.join();
	printf("Child Thread joined Main Thread\n");
	printf("Main Thread completes execution");
}