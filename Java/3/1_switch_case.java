/*
switch case statement

switch(...arg...){
	case label1:
		stmts...
		stmts...
		break; // optional
	case label2:
		.
		.
		.
	default:
		.
		.
}

case and default are optional and within them break statement is optional again.
arguement can be any variable of type int,short,char,byte,and thier boxed versions,
and string,and Enum.

it is mostly used with Enum.

duplicate case labels not allowed.

; is empty java statement is fully valid.

case labels need to be compile time constants and in range of argument type.

default case can be only one and is executed only if any case doesnt match.

within the switch statement block if any case is matched then execution will start
and continue until break statement occurs. this way multiple cases can be executed.
This is known as falling in switch which allows code reusability.

*/
import java.util.Scanner;

class Test1{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.printf("Enter your input: ");
		String x = scanner.nextLine();
		switch(x){
			case "First":
				System.out.println("First Quarter begins");
			case "Jan,Feb":
				System.out.println("January,February");
			case "Mar,Apr":
				System.out.println("March,April");
				break;
			case "Second":
				System.out.println("Second Quarter begins");
				break;
			default:
				System.out.println("Default case");
		}
	}
}
