package executorService;
import java.util.concurrent.*;
/*
If we wish to return something from thread then we wait we use Futures and Callables interfaces and
we submit tasks to executor service irrespective of its implementation.Future<T> and Callable<T>.
These are used in asynchronous operations.
Sometimes we may need that some task  should complete within given time else timout exception is thrown
*/
public class Example11{
	public static void main(String[] args)throws Exception{
		ExecutorService service=Executors.newSingleThreadExecutor();
		try{
		Future<Integer> result=service.submit(new Callable<Integer>(){
			@Override
			public Integer call() throws InterruptedException{
				Thread.sleep(10000);
				return 1;
			}
		});
		// check wheter task completes  in 6 seconds else throws timeout exception
		System.out.println(result.get(6,TimeUnit.SECONDS));
		}catch(TimeoutException e){
		System.out.println("Task could not be completed in time");
		}
	}
}
