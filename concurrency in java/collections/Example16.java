package collections;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.CountDownLatch;

/* if we need a hashmap to be accessed by multiple threads
 * then we require atomic operations like insertion. In such case
 * we use concurrent hashmap. It stores internally as array of
 * segments and for each insertion and fetching , lock is acquired
 * and released from the segments.
 */
public class Example16 {
public static void main(String[] args) throws InterruptedException {
    CountDownLatch latch=new CountDownLatch(2);
    Map<String,String> map=new ConcurrentHashMap<>();
    new Thread(()->{
        for(int i=0;i<5;i++){
            try {
                Thread.sleep(1000);
                map.put("key"+i,"val"+i );
                System.out.println("inserted into map");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }latch.countDown();
    }).start();
    new Thread(()->{
        for(int i=0;i<5;i++){
            try {
                Thread.sleep(500);
                map.put("KEY"+i,"VAL"+i );
                System.out.println("inserted into map".toUpperCase());
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }latch.countDown();
    }).start();
    latch.await();
    System.out.println(map);
}
}
