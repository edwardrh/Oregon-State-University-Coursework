#include "./Scissors.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Scissors::Scissors(){
	strength = 1;
}

Scissors::Scissors(int x){
	strength = x;
	type = 's';
}

int Scissors::fight(Tool t){
	t.setStrength(result);
}

void Scissors::set_result(){
	
}