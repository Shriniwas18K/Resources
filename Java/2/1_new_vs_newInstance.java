/*
Both are used to create objects of class.

new : operator works as start of instance control flow
1) object creation
2) object initialization and execute instance intializers blocks
3) consttructor invocation
But type is decided at compile time itself

newInstance : it is method to create objects whose type is decided at runtime, it is part of reflection API.Class is used to represent the class at runtime.This is part of lang package java.lang.reflect.Compulsory those three exceptions need to be handled when using newInstance().
*/
package temp;
import java.util.Scanner;

class Test{
	{
		System.out.println("instance initializer block of Test");
	}
	Test(String name){
		System.out.println(name);
	}
	public static void main(String[] args){
		Test t = new Test("Test class decided at compile time");
		System.out.printf("Choose b/w classes A and B : ");
		Scanner scan = new Scanner(System.in);
		String className = scan.nextLine();
		try{
			Object o = Class.forName(className).newInstance();
			System.out.println(o.getClass().getName());
		}catch(
			InstantiationException | ClassNotFoundException | IllegalAccessException e
		){}
	}
}
// JVM supplies default constructor here
class A{
	{
		System.out.println("instance initializer of A");
	}
}
class B{
	{
		System.out.println("instance initializer of B");
	}
}
