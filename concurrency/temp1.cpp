#include<stdio.h>
#include<thread>
#include<chrono>
// concurrency useful when GUIs event driven programming
// parrallel programming useful when same operation on multiple elements like matrix multiplication and image processing

// concurrency involves very fast swapping of processes or threads by context switching of scheduler
// which pretends to be parrallel execution but is sequential indeed, in context switch the scheduler
// has to swap out process or thread from processor and save its state and put it in waiting queue if
// it is in blocked state else release and reclaim its memory resources, and also load the next process
// or thread and its previous state if it was in waioting queue or from ready queue onto the processor
// and such kind of swapping and deciding which thread or process to execute involves the role of
// scheduler independent of programmer which uses algorithms like SJF,SRTF,round robin,etc.

// all concurrent programs can beinfit from parrallel execution if parralel hardware like GPUs given
// but parrallel programs always require true parrallel hardware to execute

// threads are subparts of process sharing the process address space and execution code and memory

// use thread safe printf , dont use std::cout it is not thread safe
// always code should be independent thread order of execution as Scheduler might execute any one anytime
// use STL classes for platform independent code as diffirent OS implement process threads
void task(){
	printf("task started\n");
	printf("Child Thread ID \t %d\n",std::this_thread::get_id());
	std::this_thread::sleep_for(std::chrono::seconds(5));
	printf("task completed\n");
}
int main(){
	std::thread childThread(task);
	printf("Main Thread ID \t %d\n",std::this_thread::get_id());
	// below tells parent thread(main thread here) has to wait for completion for execution of child thread
	childThread.join();
}