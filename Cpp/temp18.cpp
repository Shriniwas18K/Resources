#include<iostream>
// optimisation using data layout
class GameState{
	bool checkpoint; // 1byte
	float score;	 // 4byte
	short numberOfPlayers;//2byte
};// we expect above class object size to be 7 bytes
// but it is 12 bytes as compiler adds padding and
// make to total memory taken by class as multiple of 4 bytes

// the memory occupied by object is always multiple of the
// size of largest data type in it, and the compiler tries
// to push whatever it can into those blocks of bytes in/
// order of declaration of variables

// the size of each block can be checked using alignof builtin function
class GameState1{
	float score; // 4byte
	short numberOfPlayers; // 2byte
	bool checkpoint; // 1byte
};// above class object will actually weigh 8 bytes as
// the compiler assigns 2 blocks of 4byte wherein
// in first block score(4byte) resides,and in second block
// numberOfPlayers(2byte) and checkpoint(1byte) reside,and
// the remaining 1byte is vacant but reserved for the further.

// thus it is always preferred to declare the variables
// in the class from top to bottom as highest to lowest
// in terms of data type size thus the resulting object

int main(){
	GameState gs;
	std::cout<< sizeof gs<<" "<<alignof(gs)<<"\n";
	GameState1 gs1;
	std::cout<< sizeof gs1<<" "<<alignof(gs1);
}