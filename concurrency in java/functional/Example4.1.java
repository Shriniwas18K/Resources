import java.util.function.*;

public class Example4{
	public static void main(String[] args){
		Function<Integer,Integer> add3=i->i+3;
		Function<Integer,Integer> mul3=i->i*3;
		int n=5;
		System.out.println(
			add3.andThen(mul3).apply(5)
     		);//24 = (5+3) * 3
	}
}
