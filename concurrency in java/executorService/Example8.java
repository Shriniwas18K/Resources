package executorService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/* Executor service manages all thread lifecycle. It maintains blocking queue of Tasks which
 * implement Runnable Interface which are submitted to Thread Pool for execution. In thread
 * pool we submit tasks of fixed number of threads which are maintained alive until program
 * is running. In case SingleThreadExecutor only one thread is maintained with Main and tasks
 * are executed sequentially by the single thread.In case FixedThreadExecutor multiple threads
 * are maintained and executed parrallely.Each executor service maintains its own task queue.
 * 
 * See below the lines of initiated are executed first i.e. the synchronous code in main completes
 * execution first then the asynchronous execution of executor service starts.
 */
public class Example8 {
    public static void main(final String[] args) {        
        ExecutorService singleThreadExecutorService=Executors.newSingleThreadExecutor();
        System.out.println("Single Thread Executor Service initiated");
        
        try{
            for(int i=0;i<5;i++){
                singleThreadExecutorService.execute(new Runnable(){
                    @Override
                    public void run(){
                        System.out.println("Executing Task by "+Thread.currentThread().getName());
                    }
                });
            }
        }finally{}

        ExecutorService manyThreadExecutorService=Executors.newFixedThreadPool(5);
        System.out.println("Many Thread Executor Service initiated");

        try{
            for(int i=0;i<5;i++){
                manyThreadExecutorService.execute(new Runnable(){
                    @Override
                    public void run(){
                        System.out.println("Started executing task by "+Thread.currentThread().getName());
                        try {
                            Thread.sleep(5000);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                        System.out.println("Completed execution of task by "+Thread.currentThread().getName());
                    }
                });
            }
        }finally{}

        System.out.println("Synchronous code in main executed");
    }
}
