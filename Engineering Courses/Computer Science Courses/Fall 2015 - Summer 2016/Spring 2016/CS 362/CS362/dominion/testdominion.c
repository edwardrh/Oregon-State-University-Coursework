#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  
  //Have an array with all variables
  //Make a for loop that randomly assigns array
  
  int k1[] = {adventurer, council_room, feast, gardens, mine, remodel, smithy,
              village, baron, great_hall, minion, steward, tribute, ambassador,
              cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
  int k[10];
  //= {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  int num;
  for(num = 0; num < 10; num++){
	  k[num] = k1[rand() % 19];
  }

  printf ("Starting game.\n");
  
  int nump = (rand() % 3) + 1;
  
  initializeGame(nump, k, atoi(argv[1]), p);
  
  int money = 0;
  int adventurerPos = -1;
  int councilPos = -1;
  int feastPos = -1;
  int gardensPos = -1;
  int minePos = -1;
  int remodelPos = -1;
  int smithyPos = -1;
  int villagePos = -1;
  int baronPos = -1;
  int greatPos = -1;
  int minionPos = -1;
  int stewardPos = -1;
  int tributePos = -1;
  int ambassadorPos = -1;
  int cutpursePos = -1;
  int embargoPos = -1;
  int outpostPos = -1;
  int salvagerPos = -1;
  int seaPos = -1;
  int treasurePos = -1;
  int i = 0;
  
  int numAdventurers = 0;
  int numCouncils = 0;
  int numFeasts = 0;
  int numGardens = 0;
  int numMines = 0;
  int numRemodels = 0;
  int numSmithies = 0;
  int numVillages = 0;
  int numBarons = 0;
  int numGreats = 0;
  int numMinions = 0;
  int numStewards = 0;
  int numTributes = 0;
  int numAmbassadors = 0;
  int numCutpurses = 0;
  int numEmbargos = 0;
  int numOutposts = 0;
  int numSalvagers = 0;
  int numSeas = 0;
  int numTreasures = 0;
  
  while (!isGameOver(p)){
	  money = 0;
	  int adventurerPos = -1;
	  int councilPos = -1;
	  int feastPos = -1;
	  int gardensPos = -1;
	  int minePos = -1;
	  int remodelPos = -1;
	  int smithyPos = -1;
	  int villagePos = -1;
	  int baronPos = -1;
	  int greatPos = -1;
	  int minionPos = -1;
	  int stewardPos = -1;
	  int tributePos = -1;
	  int ambassadorPos = -1;
	  int cutpursePos = -1;
	  int embargoPos = -1;
	  int outpostPos = -1;
	  int salvagerPos = -1;
	  int seaPos = -1;
	  int treasurePos = -1;
	  
	  for (i = 0; i < numHandCards(p); i++){
		if (handCard(i, p) == copper)
			money++;
		else if (handCard(i, p) == silver)
			money += 2;
		else if (handCard(i, p) == gold)
			money += 3;
		else if (handCard(i, p) == adventurer)
			adventurerPos = i;
		else if (handCard(i, p) == council_room)
			councilPos = i;
		else if (handCard(i, p) == feast)
			feastPos = i;
		else if (handCard(i, p) == gardens)
			gardensPos = i;
		else if (handCard(i, p) == mine)
			minePos = i;
		else if (handCard(i, p) == remodel)
			remodelPos = i;
		else if (handCard(i, p) == smithy)
			smithyPos = i;
		else if (handCard(i, p) == village)
			villagePos = i;
		else if (handCard(i, p) == baron)
			baronPos = i;
		else if (handCard(i, p) == great_hall)
			greatPos = i;
		else if (handCard(i, p) == minion)
			minionPos = i;
		else if (handCard(i, p) == steward)
			stewardPos = i;
		else if (handCard(i, p) == tribute)
			tributePos = i;
		else if (handCard(i, p) == ambassador)
			ambassadorPos = i;
		else if (handCard(i, p) == cutpurse)
			cutpursePos = i;
		else if (handCard(i, p) == embargo)
			embargoPos = i;
		else if (handCard(i, p) == outpost)
			outpostPos = i;
		else if (handCard(i, p) == salvager)
			salvagerPos = i;
		else if (handCard(i, p) == sea_hag)
			seaPos = i;
		else if (handCard(i, p) == treasure_map)
			treasurePos = i;
	   }
	  
	if (whoseTurn(p) == 0) {
	//adventurer
	if (adventurerPos != -1) {
        printf("1: adventurer played from position %d\n", adventurerPos);
		playCard(adventurerPos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
      else if ((money >= 6) && (numAdventurers < 2)) {
        printf("1: bought adventurer\n");
		buyCard(adventurer, p);
		numAdventurers++;
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//council_room
	if (councilPos != -1) {
        printf("1: council_room played from position %d\n", councilPos);
		playCard(councilPos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 5) && (numCouncils < 2)) {
        printf("1: bought council_room\n");
		buyCard(council_room, p);
		numCouncils++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//feast
	if (feastPos != -1) {
        printf("1: feast played from position %d\n", feastPos);
		playCard(feastPos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 4) && (numFeasts < 2)) {
        printf("1: bought feast\n");
		buyCard(feast, p);
		numFeasts++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//gardens
	if (gardensPos != -1) {
        printf("1: gardens played from position %d\n", gardensPos);
		playCard(gardensPos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 4) && (numGardens < 2)) {
        printf("1: bought gardens\n");
		buyCard(gardens, p);
		numGardens++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//mine
	if (minePos != -1) {
        printf("1: mine played from position %d\n", minePos);
		playCard(minePos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 5) && (numMines < 2)) {
        printf("1: bought mine\n");
		buyCard(mine, p);
		numMines++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//remodel
	if (remodelPos != -1) {
        printf("1: remodel played from position %d\n", remodelPos);
		playCard(remodelPos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 4) && (numRemodels < 2)) {
        printf("1: bought remodel\n");
		buyCard(remodel, p);
		numRemodels++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//smithy
	if (smithyPos != -1) {
        printf("0: smithy played from position %d\n", smithyPos); 
		playCard(smithyPos, -1, -1, -1, p); 
		printf("smithy played.\n");
		money = 0;
		i = 0;
	while(i<numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("0: bought province\n"); 
        buyCard(province, p);
      }
      else if (money >= 6) {
        printf("0: bought gold\n"); 
        buyCard(gold, p);
      }
      else if ((money >= 4) && (numSmithies < 2)) {
        printf("0: bought smithy\n"); 
        buyCard(smithy, p);
        numSmithies++;
      }
      else if (money >= 3) {
        printf("0: bought silver\n"); 
        buyCard(silver, p);
      }
	}
	//village
	if (villagePos != -1) {
        printf("1: village played from position %d\n", villagePos);
		playCard(villagePos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 3) && (numVillages < 2)) {
        printf("1: bought village\n");
		buyCard(village, p);
		numVillages++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//baron
	if (baronPos != -1) {
        printf("1: baron played from position %d\n", baronPos);
		playCard(baronPos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 4) && (numBarons < 2)) {
        printf("1: bought baron\n");
		buyCard(baron, p);
		numBarons++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//great_hall
	if (greatPos != -1) {
        printf("1: great_hall played from position %d\n", greatPos);
		playCard(greatPos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 3) && (numGreats < 2)) {
        printf("1: bought great_hall\n");
		buyCard(great_hall, p);
		numGreats++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//minion
	if (minionPos != -1) {
        printf("1: minion played from position %d\n", minionPos);
		playCard(minionPos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 5) && (numMinions < 2)) {
        printf("1: bought minion\n");
		buyCard(minion, p);
		numMinions++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//steward
	if (stewardPos != -1) {
        printf("1: steward played from position %d\n", stewardPos);
		playCard(stewardPos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 3) && (numStewards < 2)) {
        printf("1: bought steward\n");
		buyCard(steward, p);
		numStewards++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//tribute
	if (tributePos != -1) {
        printf("1: tribute played from position %d\n", tributePos);
		playCard(tributePos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 5) && (numTributes < 2)) {
        printf("1: bought tribute\n");
		buyCard(tribute, p);
		numTributes++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//ambassador
	if (ambassadorPos != -1) {
        printf("1: ambassador played from position %d\n", ambassadorPos);
		playCard(ambassadorPos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 3) && (numAmbassadors < 2)) {
        printf("1: bought ambassador\n");
		buyCard(ambassador, p);
		numAmbassadors++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//cutpurse
	if (cutpursePos != -1) {
        printf("1: cutpurse played from position %d\n", cutpursePos);
		playCard(cutpursePos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 4) && (numCutpurses < 2)) {
        printf("1: bought cutpurse\n");
		buyCard(cutpurse, p);
		numCutpurses++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//embargo
	if (embargoPos != -1) {
        printf("1: embargo played from position %d\n", embargoPos);
		playCard(embargoPos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
	  else if ((money >= 2) && (numEmbargos < 2)) {
        printf("1: bought embargo\n");
		buyCard(embargo, p);
		numEmbargos++;
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//outpost
	if (outpostPos != -1) {
        printf("1: outpost played from position %d\n", outpostPos);
		playCard(outpostPos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 5) && (numOutposts < 2)) {
        printf("1: bought outpost\n");
		buyCard(outpost, p);
		numOutposts++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//salvager
	if (salvagerPos != -1) {
        printf("1: salvager played from position %d\n", salvagerPos);
		playCard(salvagerPos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 4) && (numSalvagers < 2)) {
        printf("1: bought salvager\n");
		buyCard(salvager, p);
		numSalvagers++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//sea_hag
	if (seaPos != -1) {
        printf("1: sea_hag played from position %d\n", seaPos);
		playCard(seaPos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 4) && (numSeas < 2)) {
        printf("1: bought sea_hag\n");
		buyCard(sea_hag, p);
		numSeas++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	//treasure_map
	if (treasurePos != -1) {
        printf("1: treasure_map played from position %d\n", treasurePos);
		playCard(treasurePos, -1, -1, -1, p); 
		money = 0;
		i = 0;
	while(i < numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
	  else if ((money >= 4) && (numTreasures < 2)) {
        printf("1: bought treasure_map\n");
		buyCard(treasure_map, p);
		numTreasures++;
      }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("0: end turn\n");
      endTurn(p);
    }
	
	for(i = 1; i < (nump + 1); i++){
		printf("Player %d: %d\n", i, scoreFor(i, p));
	}
  } //end of While

	printf ("Finished game.\n");
	for(i = 1; i < (nump + 1); i++){
		  printf("Player %d: %d\n", i, scoreFor(i, p));
	}

  return 0;
}