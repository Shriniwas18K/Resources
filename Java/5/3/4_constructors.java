/*
 * Constructors are place to only perform initiasation of class members
 * after creating the object.It only performs initialisation not object
 * creation, the object is created by new operator only.
 * Other than initialisation any other activity we perform should go in
 * the initializer blocks. The constructor is the last one that executes
 * in the instance control flow, hence all the activity that needs to be
 * performed after initialisation can also go into it.
 * 
 * Rules for Constructors:
 * 1) name of class and constructor is same,no return type.
 * 2) compiler supplies the default noarg constructor with super() if no
 *    constructor is written at all by the programmer.
 * 3) every class should always have defination of noarg constructor,
 *    because super() calls the noarg constructor of the parent class.
 * 
 * we can also use this() as the first line which calls the constructor of the
 * current class itself, when using parameterized constructors.
 * 
 * super()/this() only one of them can be used, compiler doesnt supply them
 * if programmer writes them, they must be first line if written, and they
 * can be written anywhere except static areas.
 * 
 * Constructors can only be overloaded, not overridden,not method hidden,not static
 * 
 * abstract classes can have constructors,interfaces cannot.
 * 
 * constructors cannot give recursive calls to constructors.
 */
class Parent4{
    int temp=18;
    Parent4(){
        super();
        System.out.println("Parent noarg");
    }
    Parent4(String s){
        System.out.println(s);
        System.out.println("Parent parameterised");
    }
}
class Child4 extends Parent4{
    int temp=37;
    Child4(){
        super("From Child");
        System.out.println("Child noarg");
    }
    Child4(String s){
        System.out.println("Child parameterized");
        System.out.println("super used to access parent members: "+super.temp);
        System.out.println("this used to access current members: "+this.temp);
    }
}
class Test5 {
    public static void main(String[] args) {
        new Child4("Thank you");
        new Child4();
    }
}
