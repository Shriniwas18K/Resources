/*
 * Method Overriding: child class redefines the parent class method
 * implementations, then parent class method is overridden method
 * and child class method is overriding method
 * 
 * The overridding and overridden methods must have same return type
 * and same method signature, formal parameter names do not matter here.
 * 
 * Method resolution is done by JVM at runtime based on objects,hence
 * its is runtime dynamic polymorphism or late binding.
 * 
 * The overriding method can return child type of overriden method return type
 * Because these are covariant return types since 1.5JDK.Its only for objects
 * not primitive return types.
 * 
 * If the overidden method is final then overridding method isnt possible
 * 
 * We can override non abstract method as abstract, which allows us to 
 * conditionally hide some methods in the hierarchy.
 * 
 * we can change synchronized,native,strictfp when overriding
 * we can override non final methods as final
 * 
 * while overriding we cannot decrease the scope the method
 * public>protected>default>private
 * 
 * the overridding method can throw only the checked exceptions
 * which are child of overridden method exception
 * 
 */

import java.io.IOException;

class Parent{
    void nonAbstract(){
        System.out.println("non abstract method");
    }
    void temp() throws Exception{

    }
}
abstract class Child extends Parent{
    abstract void nonAbstract();
    public final strictfp synchronized void temp() throws IOException{

    }
}
class Test2 {
    
}
