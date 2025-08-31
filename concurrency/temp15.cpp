#include<iostream>
#include<mutex>
#include<chrono>
#include<condition_variable>
#include<thread>
// semaphore is synchronisation mechanism,
// kind of mutex but allows mutliple threads
// to access the critical section and it maintains
// counter or the number of threads that can enter now

// acquiring semaphore by thgread decreases count
// and is possible only if count is positive using
// acquire() method, if counter reaches 0 then threads
// trying to acquire semaphore will be blocked and
// put in waiting queue

// when thread is done using the resoure then
// increments the counter value by release method()

// this is for counting semaphore which is use to
// manage access of multiple threads to shared resource
// in conection pooling scenario of databases

// we can also have binary semahpore like mutex
// but key diffirence is that mutex can be acquired
// and released by same thread but semaphore can be
// by multiple threads hence semaphore is used as
// signaling mechanism for communication between threads

// producer-consumer semaphore based solution has two
// semaphores, fillCount and EmptyCount semaphore

// until C++20 semaphores arent officially part of
// the standard hence we need to use boost library
// or implement it by ourself
class Semaphore{
	public:
		Semaphore(unsigned long init_count){
			count_=init_count;
		}
		void acquire(){
			std::unique_lock<std::mutex> lck(m_);
			while(!count_){
				cv_.wait(lck);
			}count_--;
		}
		void release(){
			std::unique_lock<std::mutex> lck(m_);
			count_++;
			lck.unlock();
			cv_.notify_one();
		}
	private:
		std::mutex m_;
		std::condition_variable cv_;
		unsigned long count_;
};
Semaphore charger(2);

void cell_phone(int id){
	charger.acquire();
	printf(" Phone %d is charging\n",id);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	printf(" Phone %d is DONE charging\n",id);
	charger.release();
}

int main(){
    std::thread olivia(cell_phone,1);
    std::thread barron(cell_phone,2);
    std::thread steven(cell_phone,3);
    std::thread charle(cell_phone,4);
    std::thread mutant(cell_phone,5);
    olivia.join();
    barron.join();
    steven.join();
    charle.join();
    mutant.join();
}