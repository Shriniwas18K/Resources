package collections;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.atomic.AtomicInteger;

/* if we need primitive numeric variables or array that need 
 * to be operated by multiple threads then we use atomic 
 * variables. These have atomic operations which have multiple steps.
 * 
 * In below example both threads operate on same integer with diffirent
 * time intervals but result is correct as 10
 */
public class Example17 {
    static AtomicInteger ai=new AtomicInteger(10);    
        public static void main(String[] args) throws InterruptedException {
            CountDownLatch latch=new CountDownLatch(2);
            new Thread(()->{
                for(int i=0;i<5;i++){
                    try {
                        Thread.sleep(1000);
                        System.out.println(ai.getAndAdd(i));
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }latch.countDown();
        }).start();
        new Thread(()->{
            for(int i=0;i<5;i++){
                try {
                    Thread.sleep(100);
                    System.out.println(ai.getAndAdd(-i));
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }latch.countDown();
        }).start();
        latch.await();
        System.out.println(ai);
    }
}
