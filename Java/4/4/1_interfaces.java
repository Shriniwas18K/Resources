/*
 * Interfaces are Service Requirement Specification
 * given by clients, like JDBC API,Servlet API and 
 * implemented by vendors like Postgres connector,
 * Oracle Weblogic,Apache Tomcat servers.
 * 
 * It is contract between client and vendors.
 * 
 * Until Java 1.8 it was internally 100% pure abstract class wiht all public methods.
 * Now it allows private methods, and default methods. Hence they can have PSVM now.
 * We cannot instantiate them still. Hence running .class file of interface is possible
 * 
 * To implement any interface the class should provide implementation
 * to all its methods or declare itself as abstract and allow child
 * classes to implement remaining methods.
 * 
 * Class can extend only class but implement multiple interfaces at time.
 * 
 * All methods by default are public abstract unless declared private or given body making them default methods.
 * 
 * Interfaces variables are always public static final hence requirement level constants that need to be initialized at declaration.
 * 
 * 1) When two interfaceshaving same method signatures are implemented by one class then only one implementation is given
 * 2) When in above case method args are diffirent then its method overloading so all such overloads should be implemented
 * 3) When in 1] only return type differs and those are not covariant then in such case both interfaces cannot be implemented together
 * below is example of case 3, covariant means one of the return types is someway parent/ancestor of other type, but here String and StringBuffer are siblings
 * hence non covariant return types. String and StringBuffer both inherit from Object class hence they are siblings.
 * 4) When we access interfaces variables with same name in implementing class then we need to use FQN.
 * 
 * we also have marker or ability or tagged interfaces which dont require us to implement methods
 * but JVM implements them like Serializable,Clonable,RandomAccess,SingleThreadModel. These provide 
 * additional functionality.
 * 
 * Whenever we wants single method from very large interface having many methods then 
 * we might need to implement all of them, hence in such case we have Adapter classes which
 * implement all the methods as empty and declare themself as abstract which allows us
 * to selectively override the specific methods of our interest.
 */

import java.lang.reflect.Method;

interface A {
    String temp();
    int sameName = 18;
    private void itsOnlyWithinA(){
    }
    default void Method(){
        itsOnlyWithinA();
        System.out.println("this is the new default access modifier which is only for interfaces after JDK 1.8");
    }
}
interface B {
    StringBuffer temp();
    int sameName = 37;
    public static void main(String[] args) {
        System.out.println("B");       
    }
}
class Test1 implements A,B{

    @Override
    public StringBuffer temp() {
        // this method cannot be compiled hence Test1.class is not generated
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'temp'");
    }
    public static void main(String[] args) {
        System.out.println(A.sameName+B.sameName);       
    }
}