#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>
// producer-consumer pattern using queue(FIFO)
// in case multiple threads operate on it then
// we require to use synchronisation mechanisms as
// -> to enforce mutual exclusion of producers and consumers
// -> prevent buffer underflow and overflow scenarios

// some programming languages include such implementations
// of thread safe synchronised queues but you can always
// use conditional variable and mutex to make it

// sometimes producers might be producing at very high
// rate and consumers might not consume at such demand
// which would cause buffer overflow, sometimes in n/w
// applns the data might arrive in bursts, hence we
// should consider as average rate of production<average
// rate of consumption, we can increase the number of
// consumer threads

// some programming languages offer implementations of
// unbounded queues which are implemented using linked
// lists to have pretending unlimited capacity,cpp
// provided STL queue isnt thread safe but we will make

// pipeline consists of several steps which is usually
// series of various producer-consumer pairs, if all
// the threads run parrallel then they can match the
// rate of processing data to rate of production
// of data upstream

// condition variables use only unique locks
class ServingLine{
	public:
		void serve_soup(int i){
			std::unique_lock<std::mutex> ladle_lock(ladle);
			soup_queue.push(i);
			ladle_lock.unlock();
			soup_served.notify_one();
		}
		int take_soup(){
			std::unique_lock<std::mutex> ladle_lock(ladle);
			while(soup_queue.empty())soup_served.wait(ladle_lock);
			int bowl=soup_queue.front();
			soup_queue.pop();
			ladle_lock.unlock();
			return bowl;
		}
	private:
		std::queue<int> soup_queue;
		std::mutex ladle;
		std::condition_variable soup_served;
};

ServingLine serving_line;

void producer(){
	for(int i=0;i<1000000;i++)
		serving_line.serve_soup(i);
	serving_line.serve_soup(-1);// last bowl
	printf("\nProducer is done serving soup\n");
}
void consumer(){
	int soup_eaten=0;
	while(true){
		int bowl=serving_line.take_soup();
		if(bowl==-1){
			printf("Consumer ate %d bowls of soup\n",soup_eaten);
			serving_line.serve_soup(-1);// put the last bowl
			return;
		}else{
			soup_eaten++;
		}
	}
}
int main(){
	std::thread barron(producer);
	std::thread olivia(consumer);
	std::thread stever(consumer);
	barron.join();
	olivia.join();
	stever.join();
}