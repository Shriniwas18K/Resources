package collections;
/* BlockingQueue interface shows the behaviour of queue
 * that stores tasks to be executed by threads.It is extended
 * by two interfaces BlockingDeque and TransferQueue.
 * 
 * Blocking of execution occurs if the queue becomes empty means there 
 * is no task to execute.
 * 
 * BlockingDeque provides access from both ends to threads.
 * 
 * TransferQueue provides special method called transfer which
 * allows a busy thread to transfer the task given to it to 
 * any idle thread.
 * 
 * These are implemented by ArrayBlockingQueue,LinkedBlockingQueue,
 * PriorityBlockingQueue(allows to sort tasks using comparator),DelayQueue,
 * SynchronousQueue(it allows pushing and polling at same time by diffirent
 * threads similar to producer consumer pattern)
 * 
 * we have snychronized collections but they dont offer blocking operations,
 * here blocking queue offers blocking operation that means in a situation 
 * where you have multiple producer threads generating tasks and multiple 
 * consumer threads processing these tasks. A BlockingDeque can help manage 
 * the load efficiently, allowing producers to wait if the deque is full 
 * and consumers to wait if the deque is empty.
 */
import java.util.concurrent.BlockingDeque;
import java.util.concurrent.LinkedBlockingDeque;

public class Example14 {
    public static void main(String[] args) {
        BlockingDeque<String> deque = new LinkedBlockingDeque<>(10);

        // Producer thread
        Thread producer = new Thread(() -> {
            try {
                for (int i = 0; i < 15; i++) {
                    deque.putFirst("Task " + i);
                    System.out.println("Produced: Task " + i);
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        });

        // Consumer thread
        Thread consumer = new Thread(() -> {
            try {
                for (int i = 0; i < 15; i++) {
                    String task = deque.takeLast();
                    System.out.println("Consumed: " + task);
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        });

        producer.start();
        consumer.start();
    }
}

