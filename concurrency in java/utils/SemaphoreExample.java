package utils;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Semaphore;

public class SemaphoreExample {
    private static final int MAX_CONCURRENT_TASKS = 3;

    public static void main(String[] args) {
        Semaphore semaphore = new Semaphore(MAX_CONCURRENT_TASKS);
        ExecutorService executor = Executors.newFixedThreadPool(10);

        for (int i = 0; i < 10; i++) {
            executor.submit(() -> {
                try {
                    semaphore.acquire();
                    // Simulating task execution
                    System.out.println("Task executed by: " + Thread.currentThread().getName());
                    Thread.sleep(2000); // Simulating a delay
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                } finally {
                    semaphore.release();
                }
            });
        }

        executor.shutdown();
    }
}
