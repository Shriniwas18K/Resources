#include<iostream>
#include<thread>
#include<mutex>
// data race both threads accessing
// same resource at same time
class Entity{
	public:
		int e=0;
};
std::mutex marker;
// mutex is lock which can be used to protect
// critical section and make it acessible
// only to one thread at instant by
// acquieing mutex, once thread requests for
// locking mutex till then till that mutex is
// released by the other thread who currently
// acquired mutex, the thread remains in
// blocked state waiting for release of mutex
// requesting to acquire/lock mutex is
// blocking operation similar to file,n/w I/O

// acquiring and releasing mutex is also atomic
void inc(Entity* e){
	// critical section used for atomic transactions
	// which means either transaction occurs complete
	// or doesnt occur at all
	marker.lock();
	for(int i=0;i<10;i++)e->e++;
	marker.unlock();
	// minimise the code in critical section
}
int main(){
	Entity e;
	std::thread t1(inc,&e);
	std::thread t2(inc,&e);
	t1.join();
	t2.join();
	printf("e = %d\n",e.e);
}