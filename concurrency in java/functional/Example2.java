package functional;

import java.util.function.Function;

/* This way we declare functional interfaces, but it is
 * very rarely required. Instead, we use four default Java
 * functional interfaces.
 */
@FunctionalInterface
interface CustomFunctionalInterface {
    void temp();
}

/* The public interface Function<T, R> {
        R apply(T arg);
   } 
 * This is the most frequently used, and all these
 * use Java boxed types and classes and functions only.
 * 
 * For primitive types, we have specialized interfaces
 * like IntFunction, etc.
 * 
 * we can define these functions in static as well as instance scope
 */
public class Example2 {

    static Function<Integer, Void> print = (i) -> {
        System.out.println(i);
        return null; // Function<Integer, Void> requires a return value
    };
    // The type of 'i' is inferred as Integer

    public static void main(String[] args) {
        print.apply(42); // Test the lambda expression
    }
}
