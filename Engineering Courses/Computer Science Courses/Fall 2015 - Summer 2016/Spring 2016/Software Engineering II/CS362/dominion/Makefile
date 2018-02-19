CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	
unittest1: unittest1.c dominion.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)
	
unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 playdom
	./unittest1 >> unittestresults.out
	echo "GCOV AFTER 1 TEST" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest2 >> unittestresults.out
	echo "GCOV AFTER 2 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest3 >> unittestresults.out
	echo "GCOV AFTER 3 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest4 >> unittestresults.out
	echo "GCOV AFTER 4 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest1 >> unittestresults.out
	echo "GCOV AFTER 5 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest2 >> unittestresults.out
	echo "GCOV AFTER 6 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest3 >> unittestresults.out
	echo "GCOV AFTER 7 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest4 >> unittestresults.out
	echo "GCOV AFTER 8 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 3 >> unittestresults.out
	echo "GCOV AFTER PLAYING A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
randomtestcard1: randomtestcard1.c dominion.o
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	
randomtestcard1.out: randomtestcard1 playdom
	./randomtestcard1 >> randomtestcard1.out
	echo "GCOV AFTER 1 RANDOM TEST" >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	./playdom 3 >> randomtestcard1.out
	echo "GCOV AFTER PLAYING A GAME" >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	
randomtestcard2: randomtestcard2.c dominion.o
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	
randomtestcard2.out: randomtestcard2 playdom
	./randomtestcard2 >> randomtestcard2.out
	echo "GCOV AFTER 2 RANDOM TESTS" >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	./playdom 3 >> randomtestcard2.out
	echo "GCOV AFTER PLAYING A GAME" >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	
randomtestadventurer: randomtestadventurer.c dominion.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	
randomtestadventurer.out: randomtestadventurer playdom
	./randomtestadventurer >> randomtestadventurer.out
	echo "GCOV AFTER 3 RANDOM TESTS" >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	./playdom 3 >> randomtestadventurer.out
	echo "GCOV AFTER PLAYING A GAME" >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	
testdominion: testdominion.c dominion.o
	gcc -o testdominion testdominion.c -g dominion.o rngs.o $(CFLAGS)
	
testdominion.out: testdominion playdom
	./testdominion >> testdominion.out
	echo "GCOV AFTER RANDOM TESTER" >> testdominion.out
	gcov dominion.c >> testdominion.out
	./playdom 3 >> testdominion.out
	echo "GCOV AFTER PLAYING A GAME" >> testdominion.out
	gcov dominion.c >> testdominion.out

all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2 randomtestadventurer testdominion player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
