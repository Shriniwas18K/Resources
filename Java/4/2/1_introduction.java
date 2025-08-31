/*
whenever we want to use any class defined outside current package or source file then we 
use Fully Qualified Name (FQN) to access it. But it increases code redudancy so we use 
import statement as typing shortcut.
*/
import java.util.HashMap;

class Test1{
	public static void main(String[] args){
		java.util.ArrayList<Integer> arr=new java.util.ArrayList<>();
		// Fully Qualified Name usage
		arr.add(314);
		arr.add(369);
		System.out.println(arr);
		HashMap<Integer,String> map=new HashMap<>();
		map.put(314,"Mhalunge");
		map.put(369,"Vasoli");
		System.out.println(map);
	}
}
