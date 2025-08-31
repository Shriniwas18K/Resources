#include<thread>
#include<mutex>
// suppose thread wants to reacquire
// the same mutex again even though
// it has acquired it, so we use
// recursive mutex which keeps track
// of number of times the thread has
// acquired the mutex and the thread
// also has to release it same number
// of times else deadlock, this allows
// reusing the same mutex
std::recursive_mutex marker;
void inc(int* shared1,long* shared2){
	marker.lock();
		(*shared1)++;
		marker.lock();
			(*shared2)--;
		marker.unlock();
	marker.unlock();
}
int main(){
	int shared1=10;
	long shared2=10L;
 	std::thread t1(inc,&shared1,&shared2);
	std::thread t2(inc,&shared1,&shared2);
	t1.join();
	t2.join();
	printf("shared1 = %d\nshared2 = %d",shared1,shared2);
}