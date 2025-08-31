/*
 * final methods means cannot be overriden or method hidden
 * 
 * final classes means that class cannot be extended and all
 * its methods will be implicitely considered as final methods,
 * but the variables stay as non final methods
 * 
 * final variables mean diffirent based on kind of variable
 * 1) local variable : initialize and set its value only once before use
 * 2) formal method parameters : same as local variables above
 * 3) instance variables : initialize them only once during instance control flow
 * 4) static variables : initialize them only once during static control flow
 * 
 * abstract and final cannot be used together because final means not changeable
 * and abstract means child class should change that thing
 * 
 * this example shows Test2Inner class isnt loaded nor executed unless it 
 * is used, though it was compiled, and when it was loaded and executed manually
 * using command "java Test2$Test2Inner" then it prints out parent Test2 PSVM
*/
class Test2{
    final class Test2Inner extends Test2{
        final static String name;
        static{
            name = "Test2Inner";
            System.out.println(name);
        }
    }
    final public static void main(String[] args) {
        System.out.println("PSVM of Test 2");
    }
}
