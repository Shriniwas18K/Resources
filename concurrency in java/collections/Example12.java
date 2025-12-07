package collections;
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

/*If we use collections that need to be operated by multiple threads then we need
synchronization that can be achieved by using synchronized versions of Collections*/
public class Example12{
	public static void main(String[] args) throws InterruptedException{
		List<Integer> arr=Collections.synchronizedList(new ArrayList<>());
               Thread one=new Thread(()->{
                        for(int i=0;i<100;i++){ 
                                arr.add(i);
                        }
                });
		Thread two=new Thread(()->{
			for(int i=0;i<100;i++){
				arr.add(i);
			}
		});
		// Both threads are operating on same collection
		one.start();
		two.start();
		one.join();
		two.join();
		System.out.println(arr.size());
	}
}
