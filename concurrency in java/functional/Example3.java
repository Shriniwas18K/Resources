package functional;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Supplier;

/* to produce some values we have suppliers
 * internally 
 * @FunctionalInterface
 * public interface Supplier<T> {
 *   T get();
 * }
 * 
 */
public class Example3 {
    public static void main(String[] args) {
        Supplier<InnerExample3> AMDPC=() -> new InnerExample3("XENON","AMD");
        // think of this kind when we have kind of builder of lombok being used for large classes or constructors    
        List<InnerExample3> storage=new ArrayList<>();
        storage.add(AMDPC.get());
    }
}
class InnerExample3 {
    public String devname;
    public String processor;
    public InnerExample3(String devname,String processor){
        this.devname=devname;
        this.processor=processor;
    }
}