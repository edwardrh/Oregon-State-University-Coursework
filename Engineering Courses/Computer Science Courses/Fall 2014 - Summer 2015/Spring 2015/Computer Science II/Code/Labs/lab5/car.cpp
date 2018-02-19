#include "./car.h"

car::car(){
}

car::car(int x):vehicle(x){}

int car::get_toll(int num){
	if(num == 5){
		return (20*seats/2)/2;
	}
	return 20*seats;
}