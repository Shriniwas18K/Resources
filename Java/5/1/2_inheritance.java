/*
 * IS-A relationship : Inheritance
 * - Advantages : Code Reusability
 * 
 * - extends keyword
 * 
 * - Whatever non private things are available in
 *   parent class becomes available in child class
 *   hence using child class reference we can call
 *   both methods of parent and child class.on child object
 * 
 * - Parent reference(ref) can be used to hold child objects, 
 *   but converse is not true because if Child ref attempts
 *   to access Child specific instance variables then those
 *   arent available in the Parent object
 * 
 * - Whatever specific to child class is not accessible
 *   by the reference of parent class on child object
 * 
 * - By default every class inherits java.lang.Object which
 *   is the root class having the core methods needed for 
 *   every object
 * 
 * - one class can extend only one class at time which prevents
 *   the ambiguity of multiple inheritance wherein both parent
 *   classes have same method signature coming, and need to
 *   decicde which should be invoked
 * 
 * - multiple inheritance is possible wrt to interfaces i.e. one
 *   class can implement multiple interfaces because they dont
 *   contain implementation, thus implementation remains single
 * 
 * - cyclic inheritance, class inheriting itself isnt allowed
 */
class Parent{
    void parentSpecific(){
        System.out.println("Parent Specific");
    }
}
class Child extends Parent{
    void childSpecific(){
        System.out.println("Child specific method only accesible by child reference");
    }
}
class Test2{
    public static void main(String[] args) {
        Parent parentRef=new Child();
        //ref.childSpecific(); parent ref cannot call the child specific methods on child objects
        Child childRef = new Child();
        childRef.childSpecific();
        childRef.parentSpecific();
        // Child ref can access both parent and child methods(method hiding and overriding can happen)
        // can access both parent and child methods
        // Child childRef1 = new Parent(); not allowed
    }
}