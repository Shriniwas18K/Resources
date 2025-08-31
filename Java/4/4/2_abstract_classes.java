/*
 * Interfaces and abstract classes have some diffirences
 * 
 * In interfaces implementation is unknown
 * In abstract classes partial implementation is known
 * 
 * In interfaces we have every method public abstract(before 1.8)
 * In abstract classes we can have concrete methods
 * 
 * In interfaces by default public abstract, hence our access modifiers of members should be compliant
 * In abstract classes we have no restrictions on access modifiers of members
 * 
 * In interfaces every variable is public static final always, not in abstract classes
 * 
 * In abstract classes we can have constructors, static and instance initializer blocks but in interfaces we cannot
 * 
 * Abstract class constructors are executed when we declare super(args.....) in child class constructor
 * 
 * In abstract classes we have instance variables which can be initialized using constructors hence they can have constructors called by child class constructors
 * but in interfaces we cannot have instance variables hence we cannot have constructors too.
 * 
 * When executing abstract class constructor in child classes then abstract class object isnt created but its instance variables are initialized
 * 
 * If everything is abstract then we can use interfaces, but using interfaces it prevents child specific initialization of variables
 * 
 * For abstract class extenders object creation is costly, but for interface implementors its easy
 */
abstract class Abstract {
    int temp = 0;// child classes can declare its value on thier wish
    void concrete(){
        // allowed
    }
    Abstract(){
        // constructor allowed and by default executed because super(...) is implicitely first line in child class constructors
        System.out.println("Abstract class constructor");
    }
}
interface Interface {
    int temp = 0;// its public static final, not changeable by chile classes
    // concrete methods can be default or private
}
class A1 extends Abstract {
    {
        temp=18;
    }
    A1(){

    }
}
class B1 extends Abstract {
    {
        temp=37;
    }
}