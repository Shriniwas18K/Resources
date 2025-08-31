/*
 * Overriding wrt static methods
 * 
 * we cannot override static methods as non static and vice versa
 * 
 * both child and parent static methods overriden is called 
 * method hiding,method resolution is based on references at compile time 
 * 
 * In method hiding, parent class implementation is still accessible, but
 * in overridden parent class implementation cannot be accessed from child object
 * 
 * In overridding, both parent and child class references on child object, 
 * give implementation of child class only, because JVM decicdes to invoke
 * the implementation based on runtime object time, and its instance methods
 * 
 * Method hiding is compile time decided by compiler and thus reference
 * based, i.e. as static methods are tied to references hence they still
 * remain accessible based on reference.
 */
class Parent{
    public static void method() {
        System.out.println("Parent static method");
    }
}
class Child extends Parent{
    public static void method(){
        System.out.println("Child static method");
    }
}
class Test3 {
    public static void main(String[] args) {
        Parent parentRef = new Child();
        parentRef.method();
        Child childRef = new Child();
        childRef.method();
    }
}
