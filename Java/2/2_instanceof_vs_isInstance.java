/*
isInstance method works for runtime type checking of object. It returns true when
object is checked with its actual type and parent types from inheritance hierarchy.
It is part of relfection API.

instanceof operator is compile time type checking of same above work.
*/
import java.util.Scanner;

class Test1{
	public static void main(String[] args) throws ClassNotFoundException,InstantiationException,IllegalAccessException{
		Scanner scan = new Scanner(System.in);
		System.out.printf("Which class object A or B :");
		String className = scan.nextLine();
		Object o = Class.forName(className).newInstance();
		System.out.println("Compile time checking of instanceof");
		System.out.println(o instanceof A);
		System.out.println("Runtime type checking of isInstance using dynamic decided className");
		System.out.println(Class.forName(className).isInstance(o));
	}
}
class A{};
class B{};
