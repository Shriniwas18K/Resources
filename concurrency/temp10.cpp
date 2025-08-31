#include<iostream>
#include<mutex>
#include<thread>
// another form of deadlock is through thread death
// if thread or process who has acquired locks gets
// abruptly terminated or aborted then it may not release
// locks and in that case active threads and process
// will stay waiting for acquiring locks thus inifite wait

// this can be prevented by using scoped_lock which
// releases locks acquired by thread or process if the
// execution goes out of scope , here also when the
// while loop prematurely completes, but only since C++17

int sushi_count=100;
void philosopher(std::mutex& first_chopstick,std::mutex& second_chopstick){
    while(sushi_count>0){
		first_chopstick.lock();
		second_chopstick.lock();
		sushi_count--;
		if(sushi_count==10){
			printf("Thread %d terminates without releasing locks\n",std::this_thread::get_id());
			break;
		}
		second_chopstick.unlock();
		first_chopstick.unlock();
	}
//
//	while(sushi_count>0){
//		std::scoped_lock locks(first_chopstick,second_chopstick);
//		sushi_count--;
//		if(sushi_count==10){
//			printf("Thread %d terminates without releasing locks\n",std::this_thread::get_id());
//			break;
//		}
//	}
//
}
int main(){
	std::mutex chopstick_a,chopstick_b;
	std::thread barron(philosopher,std::ref(chopstick_a),std::ref(chopstick_b));
	std::thread olivia(philosopher,std::ref(chopstick_a),std::ref(chopstick_b));
	barron.join();
	olivia.join();
	printf("philsophers done eating");
}