package utils;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/* Cyclic barrier is similar to join() but kind of put inside for loop
 * but more flexible where threads can operate in levels collectively
 * 
 * It is more functional and kind of superset of countdownlatch
 * 
 * we can have it used with executor service
 * 
 * same cyclic barrier can reused when all threads have called barrier.await()
 */
public class Example15 {
    public static void main(String[] args) {
        int NUM_THREADS=3;
        CyclicBarrier barrier=new CyclicBarrier(NUM_THREADS,()->{
            System.out.println("all threads have reached checkpoint");
        });
        ExecutorService service=Executors.newFixedThreadPool(NUM_THREADS);

        // type "fori" and then see how IDE gives for loop
        for(int i=0;i<NUM_THREADS;i++){
            service.execute(()->{
                try{
                // always type "sout" and see how IDE recommends below statement
                System.out.println("Stage 1 is done by "+Thread.currentThread().getName());
                barrier.await();

                System.out.println("Stage 2 is done by "+Thread.currentThread().getName());
                barrier.await();
                
                System.out.println("Stage 3 is done by "+Thread.currentThread().getName());
                barrier.await();
                }catch(InterruptedException|BrokenBarrierException exception){
                    System.out.println(exception.getMessage());
                }
            });
        }
        service.shutdown();
    }
}
