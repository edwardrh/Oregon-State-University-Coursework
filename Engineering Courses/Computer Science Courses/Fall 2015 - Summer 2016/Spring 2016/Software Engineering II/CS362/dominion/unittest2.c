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

//initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)

int main(){
	struct gameState* game = newGame();
	int* k = malloc(10 * sizeof(int));
	initializeGame(0, k, 0, game);
	myassert(game->numPlayers == 0);
	if (!failed){
		printf("TEST PASSED.\n");
	}
	return 0;
}