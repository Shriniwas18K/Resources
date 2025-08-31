/*
 * While executing .class file
 * 
 * 1) identification of static members
 * 2) execution of static variable assignments and blocks
 * 3) execution of PSVM
 * 
 * Inside static block if we are trying to read the static
 * variable then we have two cases:
 * 1) if we directly read static variable then it is direct read.
 * 2) if we indirectly read static variable by calling static method
 * 
 * If variable declaration is identified by JVM but it is
 * in uninitialized state then it is said to be we RIWO
 * Read Indirectly Write Only state, which means that we
 * get the default values of variable.
 * 
 * Static initialzer blocks are executed at the time of class loading
 * which happens when first time the object of the class is created
 * or even if someone invokes some static method of the class. They are
 * used in Object class to load threading libraries, driver manager class
 * top register driver into the database, to perform all tasks required 
 * for the class objects to function.
 * STATIC CONTROL FLOW IN INHERITANCE
 * 1) identification of static members from parent to child
 * 2) initialization of static members and execution of static
 *    initializer blocks from parent to child
 * 3) execution of child PSVM
 * When child class is loaded in memory then parent must be loaded first implicitely
 * If somewhere in middle of static control flow there is instance initialization then
 * instance and (optionally static control flow if class of that instance is coming 
 * first time in memory) occurs, then the static control flow resumes itself.
 */
class Test1{
    static Object test;
    static{
        System.out.println(test);// direct read in RIWO state
        print();//indirect read RIWO state
        test=18;
        System.out.println(test);//direct read
    }
    static void print(){
        System.out.println(test);//indirect read
    }
    public static void main(String[] args) {
        new Test1();
    }
}
class Test2 extends Test1{
    static int temp=18;
    static{
        System.out.println(temp);
    }
    public static void main(String[] args) {
        System.out.println("Child PSVM");
    }
}