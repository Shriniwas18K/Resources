#include<iostream>
#include<future>
// sometimes we are waiting for result
// of some tasks to execute in future

// these tasks may be executing asynchronously
// and their result can be thus captured
// into futures,similar to Java Futures

int asynchronous_task(){
	std::this_thread::sleep_for(std::chrono::seconds(10));
	return 37;
}
int main(){
	// this is kind of declaring function as asynchronous
	// similar to async def in python/nodejs
	// INTERNALLY it spawns forks new thread to execute the task
	std::future<int> res = std::async(std::launch::async,
		asynchronous_task
	);
	// get function waits the execution until task executes
	// it is kind of await keyword in nodejs/python
	printf("%d",res.get());
}