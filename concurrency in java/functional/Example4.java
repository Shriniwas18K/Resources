package functional;

import java.util.function.Consumer;

/* Similarly we have consumers */
public class Example4 {
    public static void main(String[] args) {
        Consumer<InnerExample3> display=(pc)->{
            System.out.println("pc_name:"+pc.devname);
            System.out.println("pc_proc:"+pc.processor);
        };
        display.accept(new InnerExample3("XENON", "INTEL"));
    }
}
