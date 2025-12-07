package functional;
/* ? is called wildcard used with generics
 * 
 * ? extends T indicates that any type which 
 * is parent of T will accepted as element
 * 
 * ? super T indicates that any type which 
 * is inherits of T will be accepted as element
*/

import java.util.ArrayList;
import java.util.List;

public class Example8 {
    public static void main(String[] args) {
        class A{};
        class B extends A{};
        class C extends B{};
        List<? super A> temp=new ArrayList<>();
        temp.add(new B());
        temp.add(new A());
        List<? extends Object> temp1=new ArrayList<>();
        // here we cant add anything in temp1 because 
        // Object is root class i.e. it is parent of itself
    }
}
