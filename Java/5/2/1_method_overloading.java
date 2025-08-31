/*
 * when two methods have same name but diffirent
 * - number of formal parameters
 * - data type of formal parameters
 * - non covariant return type
 * anything of the above leads to method overloading
 * where method resolution is taken care by compiler
 * which is compile time polymorphism or early binding
 * 
 * its compile time concept hence only C.E occur
 * 
 * loopholes in overloading for single parameter methods:
 * 1) for methods with primitive formal parameter
 *    if compiler doesnt find matching formal parameter type
 *    then it widens the actual parameter type and searches
 *    for the matching method
 *      byte->short,char->int->long->float->double
 * 2) if many implementations are compatible to execute then 
 *    then the one with child formal parameter type will execute
 *      example: Integer extends Number, Number extends Object,Object comes from null
 *      we have implementations of Integer,Number but Object
 *      is given as actual parameter then Integer implementation executes
 * 3) if all compatible implementations have sibling
 *    data types as formal parameters to execute then C.E.ambiguity
 *      example: String and StringBuffer both inherit from Object
 * 4) if parent reference is passed as actual parameter to
 *    method having overloads with child types too, then the
 *    implementation having parent reference as type will execute
 *    because its compile time resolution
 * See the decompiled .class file for 1),2)
 * loopholes for methods with multiple formal parameters
 * 1) such kind of type widening doesnt occur for multiple parameters
 * 2) 3) 4) are not occuring because compiler does stricter checking
 * In case of varargs methods, they are executed only if compiler doesnt
 * find the method with exact required number of parameters, and they can be
 * overloaded only with other vararg methods.
 * 
 * This concept is only for instance methods, not static. 
 * Formal parameter names do not matter here.
 */
class Test1 {
    void m1(long l){
        System.out.println("type widening occured");
    }
    {
        System.out.println("char promoted to long");
        m1('a');
    }
    void m2(Number n){
        System.out.println("Number implementation");
    }
    void m2(Integer i){
        System.out.println("Integer implementation");
    }
    {
        m2(null);
    }
    void m3(String s){
        System.out.println("sibling 1");
    }
    void m3(StringBuffer s){
        System.out.println("sibling 2");
    }
    {
        //m3(new Object()); ambigous reference
    }
    void m4(Object o){
        System.out.println("Object is Parent of String");
    }
    void m4(String s){
        System.out.println("String is child of Object");
    }
    {
        m4(new Object());
    }
    void m5(int i){
        System.out.println("one int");
    }
    void m5(int i,int j,int k){
        System.out.println("three ints");
    }
    void m5(int... ints){
        System.out.println("many ints");
    }
    {
        m5(18);
        m5(18,37);
    }
    public static void main(String[] args) {
        System.out.println("Test of Method Overloading");
        new Test1();
    }
}