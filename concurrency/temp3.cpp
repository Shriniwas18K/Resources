#include<iostream>
#include<thread>
#include<chrono>
// daemon threads keep running in background
// and do not stop parent thread from termination
// and we shouldnt call join() method on them
// from parent thread, so they are best suitable
// for garbage collection and some dynamically
// typed languages include them in thier runtime
// environment

// by default new threads are non-daemon and must
// explicitely set to daemon by calling detach()

void backgroundTask(){
	while(1){
		std::this_thread::sleep_for(std::chrono::seconds(1));
		printf("doing background task\n");
	}
}
int main(){
	std::thread daemonThread(backgroundTask);
	daemonThread.detach();
	for(int i=0;i<10;i++){
		std::this_thread::sleep_for(std::chrono::seconds(1));
		printf("%d \t",i);
	}
	printf("Main Thread task completed");
}