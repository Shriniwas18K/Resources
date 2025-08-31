/*
 * abstract can be declared to classes and methods with no body
 * if any class contains atleast one abstract method that wasnt
 * overidden then that class should override that method or 
 * declare itself as abstract.
 * 
 * concrete classes means having no abstract methods remaining to
 * be overridden in the hierarchy can be declared as abstract 
 * too,just to provide enhanced implementation later.
 * 
 * abstract class cannot be instantiated, but it cannot be 
 * used with static things because those are implemented,
 * hence they are compiled.
 */
abstract class AbstractClass {
    static{
        System.out.println("executes because abstract means no instantiation but still class was loaded because its static method was used");
    }
    static void temp(){
        System.out.println("will have enhanced implementation later");
    }
    void print(){
        System.out.println("It actually looks concrete but this method's implementation needs to be enhanced hence its class declared as abstract");
    }
}
class Test3 {
    public static void main(String[] args) {
        AbstractClass.temp();
    }
}
