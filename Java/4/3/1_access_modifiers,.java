/*
 * abstract,final
 * public,private,protected,default
 * strictfp,synchronized,transient,volatile,native
 * 
 * these all are access modifiers. 
 * In C++ public private protected are access specifiers but here
 * all are called access modifiers.
 * 
 * default is written for 
 * 
 * There are two levels:
 * 1) top level modifiers : can be applied to top level classes
 * 2) member level modifiers : can be applied to anything inside top level classes
 * 
 * 1) top_level_modifiers : public , strictfp , abstract , final , default
 * 2) member level modifiers : (above all,private,protected --> inner classes),abstract(methods),volatile transient(variables only),synchronized(methods blocks)
 */
strictfp final class Test1{
    private strictfp final static class InnerClass{
        static void print(){
            System.out.println("Inner class");
        }
    }
    public static void main(String[] args) {
        System.out.println("Test 1");
        InnerClass.print();
    }
}