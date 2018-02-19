all: prog tests

prog: main.c cart.c cart.h
	gcc -g -Wall -std=c99 -o prog main.c cart.c

tests: tests.c cart.c cart.h
	gcc -g -Wall -std=c99 -o tests tests.c cart.c
clean:
	rm -rf *.o prog tests