#include<thread>
#include<atomic>
// when we are using only simple
// builtin data types then we can
// have each thread maintain its
// local copy of variables and
// update the global version in
// the shared memory, thus those
// variables are called as atomics
void inc(std::atomic<int>* var){
	for(int i=0;i<10;i++)*var++;
}
int main(){
	std::atomic<int> shared{0};
	std::thread t1(inc,&shared);
	std::thread t2(inc,&shared);
	t1.join();
	t2.join();
	printf("shared = %d",shared.load());
}