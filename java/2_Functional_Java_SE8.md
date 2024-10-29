Functional Paradigm contains concepts

1. pure functions : function execution should depend only on its local data,they should not I/O.
2. lazy evaluation : deferred execution of function until its result is needed
3. immutability : data once stored cannot be changed. if data needs to be changed then it needs to be put in new variable

Java added features like functional interfaces,streams,lambdas,method references.

funtional interface : interface with only single abstract method(SAM) and marked
with annotation FunctionalInterface. It contains default and static methods to add
more functionality to interface.lambdas get matched to SAM of functional interface.
They can be inherited implemented extended but SAM only mathces assigned lambda if
FunctionalInterface annotation is present on interface.
@FunctionalInterface
interface Helloworld{
String description(String name);
default String helperDefault(){
return "This is helper function for additional functionality";
}
static String helper(){
return "This is static helper function";
}
}
public class Solution{
public static void main(String args[]){
Helloworld h=namearg->{return "this is description of"+namearg;};
//above function namearg type is inferred as String of arg of SAM
//and method body is within {} is body of SAM of interface
System.out.println(h.description("arg"));
//method reference
var func=Helloworld::helperDefault;
}
}

we can make first class functions using java.util.function

Functional Interfaces can work with boxed types String,Integer etc
and classes interfaces only,not with primitive data types.

Function<inputargtype,returntype>funcname=methodreference or lambda expression
var res=func.apply(args);
//SAM in Functional Interface Function<T,R> is R apply(T t)

some functions do not take args and only return values such are called Suppliers
Supplier<returntype>suppliername=methodreference or lambda expression
var res=suppliername.get();
//SAM in Functional Interface Supplier<R> is R get()

some functions take args and not return values such are called Consumers
Consumer<inputtype>consumername=methodreference or lambda expression
var.method(consumername);
//SAM in Functional Interface Consumer<T> is accept(T t)

some functions take args and test some condition on them returning boolean value
such are called predicate.
Supplier<returntype>suppliername=methodreference or lambda expression
//SAM in Functional Interface Predicate<T> is boolean test(T t)

we can do functional composition using andThen default method on Functional
Interface Function<T,R> which is
default <V> Function<T,V> andThen(Function<? super R,? extends V>after)
class HelloWorld {
public static void main(String[] args) {
System.out.println("Try programiz.pro");
Function<String,String>getBio=name->"This is bio of "+name;
Function<String,String>addDecorations=bio->"%%%%%%%%%%%%%%%%%\n"+bio+"\n%%%%%%%%%%%%%%%%%%";
Function<String,Void>print=content->{System.out.println(content);return null;};
Function<String,Void>pipeline=getBio.andThen(addDecorations).andThen(print);
pipeline.apply("Java SE 17 junior engineer");
}
}
such pipelines can be designed for data processing using streams filter map reduce

lambdas scan access the valuesin the scope they are created but it is advised
to keep lambdas pure hence they should operate only on local data. lambdas are
more than syntactic sugars , they use invokedynamic instruction in generated'
byte code to bypass object creation as compared to anonymous classes.

we can add immutability to java by using

1. records for SE17 and ahead.
2. unmodified collections
   but they are shallow immutablity i.e. only reference
   of the variable storing value suppose collection must remain constant
   but elements of collection can change.
3. copyOf static method in each collection creates new container with
   new objects and new reference with exactly identical data.

   Java performs autoboxing of primitive types into objects int to Integer
   implicitely which can lead to unpredictable behavior. Primitive types are
   memory efficient and immutable so advisable to use in functional programming.
   Same with Strings as they are immutable.prefer using primitive types and
   not wrapped objects for memory efficiency.
   Immutability make stability and easy to debug and concurrent execution and
   parrallel execution without need of synchronization.
