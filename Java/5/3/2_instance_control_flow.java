/*
 *  INSTANCE CONTROL FLOW:
 * 1) identification of all instance members from parent to child classes
 * 2) execution of all instance initializer blocks from parent to child classes, and mean while parent constructors as they occur
 * 3) execution of the constructor of the class whose object needs to be created
 * 
 * Instance control flow occurs everytime we create object.
 * Constructor is the last one that gets executed in each class instance control flow
 */
class Parent{
    int temp;
    Parent(){
        System.out.println("Parent Constructor");
    }
    {
        System.out.println("Parent Initializer");
        System.out.println(temp);
        temp=18;
        System.out.println(temp);
    }
 }
class Child extends Parent{
    int test;
    Child(){
        System.out.println("Child Constructor");
    }
    {
        test=37;
        System.out.println("Child Initializer");
    }
}
class Test3{
    public static void main(String[] args) {
        new Child();
    }
}