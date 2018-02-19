#include "./Rock.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Rock::Rock(){
	strength = 1;
}

Rock::Rock(int x){
	strength = x;
	type = 'r';
}

int Rock::fight(Tool t){
	t.setStrength(result);
}

void Rock::set_result(int x){
	
}