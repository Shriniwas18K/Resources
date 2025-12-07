package executorService;
import java.util.concurrent.*;
/*
The executor checks wheter thread is idle , if found then it is given task to run from the queue.
Else it creates new thread on the fly and gives it task for execution.It kills thread if it is idle
for more than 60s.This allows us to create dynamically threads depending on amount of tasks to execute
*/
public class Example9{
	public static void main(String[] args){
		ExecutorService service=Executors.newCachedThreadPool();
		try{
			for(int i=0;i<150;i++){
				service.execute(new Runnable(){
					@Override
					public void run(){
						System.out.println("Executing Task with "+Thread.currentThread().getName());
					}
				});
			}
		}finally{}
	}
}
