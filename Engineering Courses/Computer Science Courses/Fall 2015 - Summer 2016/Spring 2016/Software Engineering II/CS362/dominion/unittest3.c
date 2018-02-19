#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int failed = 0;

void myassert(int num){
	if (!num){
		printf("TEST FAILED.\n");
		failed = 1;
	}
}

//compare(const void* a, const void* b)

int main(){
	int result = compare(0, 1);
	myassert(result == (-1));
	result = compare(1, 0);
	myassert(result == 1);
	result = compare();
	myassert(result == 0);
	if (!failed){
		printf("TEST PASSED.\n");
	}
	return 0;
}