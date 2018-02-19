#include "./Tool.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Tool::Tool(){
}

void Tool::setStrength(int x){
	if(x == 1){ //Lost
		strength = strength/2;
	}
	if(x == 2){ //Win
		strength = strength*2;
	}
	if(x == 0){ //Tie
	}
}