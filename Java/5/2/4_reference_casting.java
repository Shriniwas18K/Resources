/*
 * Polymorphism is the act of taking more than one form and it is implemented using
 * - method overloading
 * - method overridding
 * - reference casting
 * 
 * OOP provides 
 * - security by encapsulation
 * - reusability by IS-A,HAS-A
 * - flexiblity by polymorphism
 * 
 * The degree of dependency between the interacting components
 * is called coupling. It is preferred to have loosely coupled objects,
 * which allows more easily enhancement of objects
 * The degree of clarity and well defined functionality of
 * components is called cohesion.It is preferred to have higly 
 * cohesive objects.
 * 
 * Loosely coupled highly cohesive objects.
 * 
 * Reference type casting usually people say object type casting.
 * Once object is created it cannot be type casted or converted to
 * anther object, only itsd references can be casted in order to 
 * take advantage of method hiding, and access the methods tied to
 * the diffirent reference types. Thus we can use interface reference
 * to hold the objects of the class implementing that interface.
 * 
 * Rules of reference type casting. It compile time purely hence only C.E.
 * A b = (C) d;
 * - C and d must be in same class hierarchy
 * - C must be A or derived type of A
 * - runtime object must be of C or derived type of C
 * 
 * In short we are using ancestor references to hold the child object
 */
class Test4 {
    public static void main(String[] args) {
        Object n = Integer.valueOf(18);
        Number ref = (Integer)n;
    }    
}
