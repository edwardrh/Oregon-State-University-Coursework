#include "./Paper.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Paper::Paper(){
	strength = 1;
}

Paper::Paper(int x){
	strength = x;
	type = 'p';
}

int Paper::fight(Tool t){
	t.setStrength(result);
}

void Paper::set_result(int x){
	
}