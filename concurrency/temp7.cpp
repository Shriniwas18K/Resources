#include<thread>
#include<mutex>
#include<chrono>
std::mutex marker;
// acquiring/locking mutex is blocking
// operation so use non-blocking approach
// for this using try_lock() method which
// returns true if thread could acquire mutex
// if it didnt acquire mutex then false so
// thread isnt kept in waiting state and
// rather it can do something else, it wont
// attempt to lock mutex again implicitely
void inc(int* shared){
	if(marker.try_lock()){
		(*shared)++;
		std::this_thread::sleep_for(std::chrono::seconds(10));
		marker.unlock();
	}else
		printf("thread %d couldnt acquire mutex so will do something else\n",
			std::this_thread::get_id());
}
int main(){
	int shared=10;
	std::thread t1(inc,&shared);
	std::thread t2(inc,&shared);
	t1.join();
	t2.join();
	printf("shared = %d",shared);
}