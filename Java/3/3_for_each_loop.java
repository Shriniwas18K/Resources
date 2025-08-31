/*
for each loop 

Specially designed for iterating arrays and collections.

for(type variable:iterable_collection_or_array){

}

uses implicit iterators underhood hidden from programmer

Iterator : used to retreive elements of collection.
1) It part of java.util package.
2) It has three methods: 
	boolean hasNext()
	Object next()
	void remove()
3) only forward direction traversal purpose.
4) it is the only way to remove object from collection while iterating it else 
   ConcurrentModificationException is thrown.

for each loop can be used only to iterate arrays and collections which implement
Iterable interface which has only method Iterator iterator() which returns
Iterator object to iterate that collection.
*/
import java.util.ArrayList;
import java.util.Iterator;

class Test3{
	public static void main(String[] args){
		int[] temp = {32,56,768};
		for(int i:temp){
			System.out.println(i);
		}
		ArrayList<Integer> arr = new ArrayList<>();
		arr.add(999);
		arr.add(1000);
		arr.add(1001);
		arr.add(1002);
		for(int i:arr){
			System.out.println(i);
		}
		Iterator itr=arr.iterator();
		while(itr.hasNext()){
			Integer e = (Integer)itr.next();
			if(e==1000)itr.remove();
		}
		System.out.println(arr);
	}
}

