import java.util.function.*;
public class Example5{
	public static void main(String[] args){
		Function<Integer, Integer> add3 = i -> i + 3; 
		Function<Integer, Integer> mul3 = i -> i * 3; 
		Predicate<Integer> greaterThanTwo = i -> i > 2; 
		int n = 5; 
		int finalResult = add3 
			.andThen(i -> { 
				System.out.println("Result after applying add3: " + i); return i; 
			 })
			.andThen(i -> { 
				if (greaterThanTwo.test(i)) {
					 System.out.println(i + " is greater than 2"); return mul3.apply(i); 
				} else { System.out.println(i + " is not greater than 2"); return i; }
			 }) 
			.apply(n);
		System.out.println(finalResult);
	}
}
