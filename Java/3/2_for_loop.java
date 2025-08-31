/*
for loop

for(..init..;..term..;..inc..){
	//body
}

inside init and inc sections we can have any valid one java statement.
inside term we need to have single statement or expression which evaluates to boolean.

init statements execute only once during loop start before term conidition evaluates.
term and inc statements execute everytime in each iteration until term evaluates false.

below are two infinite loops

for(;;){

}

for(;;);

we can also have labelled for loops for break and continue statements which offer more flexibility and clarity.
*/
class Test2{
	public static void main(String[] args){
		for(
			int i=0;
			i<10;
			System.out.println(i++)
		);

		outer:for(int i=0;i<5;i++){
			inner:for(int j=0;j<i;j++){
				if(j==3)continue outer;
				else if(j==4)break inner;
			}
			System.out.println("i="+i);
		}
	}
}
