#include "./motorcycle.h"

motorcycle::motorcycle(){
}

motorcycle::motorcycle(int x):vehicle(x){}

int motorcycle::get_toll(int num){
	if(num == 0){
		return (20*seats)/2;
	}
	return 20*seats;
}