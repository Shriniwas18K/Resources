package functional;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/* java traditionally supports functional programming
 * using anonymous inner classes and functional interfaces
 * 
 * the functional interfaces are SAMs(Single abstract method)
 * Examples are Runnable,Comparator,etc. 
 * 
 * The Java 8 added lambda expressions,method references,and
 * predefined SAMs which reduced syntax of traditional ones.
 * 
 * Internally they are all wrapped into objects only as java
 * has added support to functional programming whereas 
 * internally its object oriented.
 * 
 * Functional programming (FP) talks about
 * 1) functions should maximum times be pure , means their 
 *    body should not contain any outside dependent stuff
 * 2) immutable data structures : once instantiated never modify 
 *    any object and if we wish to modify then create new one 
 *    with updated values. This means no setter methods exposed
 *    and all fields of class must be final and as they cannot
 *    be modified hence all can be public too.
 * 
 * Above two features are main pros of FP.
 */
public class Example1 {
    public static void main(String[] args) {
        List<Integer> numbers=new ArrayList<>();
        numbers.add(1);
        numbers.add(11);
        numbers.add(121);
        numbers.add(1008);
        Collections.sort(numbers, new Comparator<Integer>() {
            @Override
            public int compare(Integer n1, Integer n2) {
                return n1.compareTo(n2);
            }
        });
        // both the statements here mean same
        Collections.sort(numbers, (n1, n2) -> n1.compareTo(n2));
    }
}
