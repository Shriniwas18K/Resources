#include<thread>
#include<shared_mutex>
// there are cases where we have multiple
// reader threads for some shared resource
// and single writer and in such cases we
// can have shared mutex which maintains
// count of readers at each instant and
// doesnt allow reading when some thread
// is writing that resource,available since C++17
std::shared_mutex marker;
void read(int* shared_resource){
	marker.lock_shared();// for reader threads
		printf("Thread %d get value as %d\n",std::this_thread::get_id,*shared_resource);
	marker.unlock_shared();
}

void write(int* shared_resource){
	for(int i=0;i<10;i++){
		std::this_thread::sleep_for(std::chrono::seconds(1));
		marker.lock();//for writer threads
			(*shared_resource)++;
		marker.unlock();
	}
}

int main(){
	int shared=10;
	std::thread t1(read,&shared);
	std::thread t2(read,&shared);
	std::thread t3(write,&shared);
	std::thread t4(read,&shared);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}