import static java.lang.System.out;

class Main {
    public static void main(String[] args) {
        Q childRef = new Q();
        childRef.description();
        P parentRef = childRef; // implict upcasting allowed
        // this is method overridding
        // outside the child and next generations classes,
        // we cannot access the overridden implementation.
        // this is runtime resolved using vtable of class.
        // Only the implementation that belongs to actual
        // object runs there. Reference type is ignored 
        // incase of resolving overridding method. It is
        // only for instance methods. Only non-static,
        // non-final,non-private methods can be overridden 
        // and vtable lookup occurs for them. JVM maintains
        // it internally and performs dynamic dispatch at
        // method call. One table per class.
        parentRef.instanceMethod();
        childRef.instanceMethod();
        // Fields cannot be overridden
        // they are shadowed hidden if child class declares
        // fields with same name, though can still be accessed
        // in the child class using super, and also outside
        // child class using diffirent reference types.
        out.println(parentRef.instanceField);
        out.println(childRef.instanceField);
        
        // static members shouldnt be accessed using references
        // rather they should be accessed using reference types
        
        // protected behaves like public in same package
        // it shines outside same package, where the 
        // protected members can be accessed only inside
        // the child classes in the hierarchy using super 
        // or this upcasting. This allows to access
        // any non-private non-overridden method or shadowed
        // field to be accessible inside the class hierarchy.
        // If overridden method is tried to access then
        // latest child implementation overridding it executes.
        
        // java doesnt provide super.super... syntax for 
        // accessing ancestry fields, methods that are shadowed
        // overridden, but we can upcast this to the desired
        // class in ancestry and access its non-private members
        
        // reference casting allows us to access diffirent
        // static members of those reference types.
        
        // reference upcasting is safe and thus allowed
        // implicitely by reference assignments
        
        // reference downcasting isnt safe and throws
        // ClassCastException at runtime, if child type 
        // reference tries to parent type object.
        P parentRef1 = new P();
        // Q childRef1 = parentRef1; CCE
        
        // both below are polymorphism types
        // method overloading/hiding is compile time resolution
        // method overridding is runtime resolution
    }
}
class P{
    int instanceField = 90;
    void instanceMethod(){
        out.println("Parent impl");
    }
}
class Q extends P{
    int instanceField = 100;
    void description(){
        // we can access all non-private members of parent class using super in child class.
        out.println(this.instanceField);
        out.println(super.instanceField);
    }
    void instanceMethod(){
        out.println("Child impl");
    }
    void chooseImpl(String cls){
        // we can accessed the overridden implementation too
        // with super inside the child class and overridding
        // implementation with this.
        if(cls.equals("P"))
            super.instanceMethod();
        else
            this.instanceMethod();
    }
}
class A{
    int nonPrivateMember = 108;
    void instanceMethod(){
        out.println("Overridden Impl");
    }
}
class B extends A{

}
class C extends B{
    // super cannot be used to access A class members
    int nonPrivateMember = 1008; // shadowed field
    void instanceMethod(){
        out.println("Overridding Impl");
    }
    void desc(){
        // this upcasting
        out.println(((A)this).nonPrivateMember);
        // this upcasting cannot access overridden
        // implementation of method, though it can
        // access shadowed fields.
        ((A)this).instanceMethod();
        // super keyword can access overridden
        // implementation, but limitation is that
        // only parent class will be covered in it.
        // Hence if current class overriddes method
        // then that method then it doesnt execute,
        // overridden version executes. Version said
        // as in hierarchy, class creates new version
        // of that method,if it overriddes it. So if
        // in long hierarchy, some deep child uses
        // super.instanceMethod() then latest version
        // executes, excluding version defined in that
        // same deep child class. Here latest version
        // was of A class, excluding current class version.
        super.instanceMethod(); // Overridden Impl
    }
}
