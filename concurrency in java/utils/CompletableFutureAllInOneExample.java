package utils;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeUnit;
/* CompletableFutures open room to asychronous operations
 * which uses fork join pool underhood, it is similar to 
 * javascript async await stuff and allow method chaining
 * kind of stuff
 */
public class CompletableFutureAllInOneExample {
    public static void main(String[] args) {
        // Fetch data from three sources asynchronously
        CompletableFuture<String> future1 = fetchDataFromSource1();
        CompletableFuture<String> future2 = fetchDataFromSource2();
        CompletableFuture<String> future3 = fetchDataFromSource3();

        // Combine results
        CompletableFuture<String> combinedFuture = CompletableFuture.allOf(future1, future2, future3)
            .thenApply(voidResult -> {
                try {
                    // Get the results of individual futures
                    String result1 = future1.get();
                    String result2 = future2.get();
                    String result3 = future3.get();
                    // Combine the results
                    return "Combined Result: " + result1 + ", " + result2 + ", " + result3;
                } catch (InterruptedException | ExecutionException e) {
                    throw new RuntimeException(e);
                }
            });

        // Handle the final result or any exceptions
        combinedFuture.thenAccept(result -> System.out.println("Final Result: " + result))
                      .exceptionally(ex -> {
                          System.err.println("An error occurred: " + ex.getMessage());
                          return null;
                      });

        // Block main thread to wait for all tasks to complete (not recommended for real apps)
        combinedFuture.join();
    }

    private static CompletableFuture<String> fetchDataFromSource1() {
        return CompletableFuture.supplyAsync(() -> {
            simulateDelay("Source 1");
            return "Data from Source 1";
        }).orTimeout(2, TimeUnit.SECONDS).exceptionally(ex -> "Source 1 failed: " + ex.getMessage());
    }

    private static CompletableFuture<String> fetchDataFromSource2() {
        return CompletableFuture.supplyAsync(() -> {
            simulateDelay("Source 2");
            return "Data from Source 2";
        }).orTimeout(2, TimeUnit.SECONDS).exceptionally(ex -> "Source 2 failed: " + ex.getMessage());
    }

    private static CompletableFuture<String> fetchDataFromSource3() {
        return CompletableFuture.supplyAsync(() -> {
            simulateDelay("Source 3");
            return "Data from Source 3";
        }).orTimeout(2, TimeUnit.SECONDS).exceptionally(ex -> "Source 3 failed: " + ex.getMessage());
    }

    private static void simulateDelay(String source) {
        try {
            System.out.println("Fetching data from " + source);
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
