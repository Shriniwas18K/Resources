/*
 * we can have classes which allow only one instance at runtime
 * which is done for performance benifits.e.g. Runtime class
 * 
 * It can be done using factory/builder pattern
 * 1) make all constructors private
 * 2) maintain static variable to hold singleton instance
 * 3) maintain static factory method that returns reference to that instance
 * 
 * == checks if the operands are referencing to same object in the memory
 */
class Singleton{
    private Singleton(){}
    private static Singleton singletonInstance;
    public static Singleton create(){
        if(singletonInstance!=null)return singletonInstance;
        singletonInstance = new Singleton();
        return singletonInstance;
    }
}
class Test6{
    public static void main(String[] args) {
        Runtime r1 = Runtime.getRuntime();
        Runtime r2 = Runtime.getRuntime();
        System.out.println(r1 == r2);
        System.out.println(r1.equals(r2));
        Singleton s1 = Singleton.create();
        Singleton s2 = Singleton.create();
        System.out.println(s1 == s2);
        System.out.println(s1.equals(s2));
    }
}