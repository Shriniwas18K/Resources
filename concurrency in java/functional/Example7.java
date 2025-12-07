package functional;

import java.util.ArrayList;
import java.util.List;
/* Java supports fast prototyping and raw types like List
 * It is similar to pythonic Lists. All java collections 
 * support raw typing i.e. we can insert anything into
 * collection if it is raw type. IDE will give warnings of
 * type safety.
 * 
 * List<> etc collections or anything with <> is generic type
 * and will accept anything as parameter in <  > that extends
 * Object the root of java.
 */
public class Example7{
    public static void main(String[] args) {
        class Innova{
            public String toString(){
                return "Innova";
            }
        }
        class Nexon{
            public String toString(){
                return "Nexon";
            }
        }
        List pythonicList=new ArrayList();
        pythonicList.add(new Innova());
        pythonicList.add(new Nexon());
        pythonicList.add(1008);
        pythonicList.add("Vehicles");
        System.out.println(pythonicList);
    }
}