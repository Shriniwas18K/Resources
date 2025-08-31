#include<iostream>
#include<thread>
#include<mutex>
// OS scheduler decides which thread to execute
// and if some thread holds some shared resource
// for very long time then the threads requesting
// to acquire that resource are in starvation
// diffirent threads have difirent priorities and
// are treated diffirently by diffirent OS but
// generally higher priorities are executed more often
// and also sometimes due to more amount of concurrent
// threads also causes starvation
int sushi_count=5000;
void philosopher(std::mutex& chopsticks){
	int sushi_eaten{0};
    while(sushi_count>0){
		chopsticks.lock();
		sushi_count--;
		sushi_eaten++;
		chopsticks.unlock();
	}
	printf("Thread %d eaten %d sushis\n",std::this_thread::get_id(),sushi_eaten);
}
int main(){
	std::array<std::thread,10> threads;
	std::mutex chopsticks;
	for(int i=0;i<10;i++)
		threads[i]=std::thread(philosopher,std::ref(chopsticks));
	for(int i=0;i<10;i++)
		threads[i].join();
	printf("philosophers done eating\n");
}