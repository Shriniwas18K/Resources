package executorService;
import java.util.concurrent.*;
/*Here we can execute some task with periodic intervals on fixed number of threads*/
public class Example10 {
    public static void main(String[] args) {
        ScheduledExecutorService service = Executors.newScheduledThreadPool(2);
        service.scheduleAtFixedRate(
                new Runnable() {
                    @Override
                    public void run() {
                        System.out.println("Executing Scheduled Task");
                    }
                },
                1000, // initial delay
                2000, // periodic delay
                TimeUnit.MILLISECONDS
        );
    }
}
