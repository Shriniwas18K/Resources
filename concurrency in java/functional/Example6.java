import java.util.function.*;
/*if we want to two arguements to function and produce result then we BiFunction
builtin but if we need to add multiple arguements and produce some result in that
case we need Vavr library which provides  Function3,Function4,upto 8 args Functions. 
*/
public class Example6{
	static BiFunction<Integer,Integer,Integer> add=(i,j)->i+j;
	public static void main(String[] args){
		System.out.println(add.apply(3,5));
	}
}
