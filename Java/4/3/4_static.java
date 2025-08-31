/*
 * static can be used on members of all top level classes
 * and these things declared static when the .class file
 * loads into the memory, i.e. whenever someone calls 
 * static method or memeber variable
 * 
 * 1) static methods can be overriden as non static, but
 *    its actually creating new instance method with same
 *    name as the static method, hence static methods 
 *    dont have this overriding concept
 * 2) static methods can be overloaded
 * 3) static methods can be method hidden, i.e. if the 
 *    method is implemented again with same signature
 *    by child class then if child class reference calls
 *    that method then child implementation gets executed
 */
class Test4 {
    
}
