#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

void assertTrue(int predicate, char *message) 
{
	printf("%s: ", message);
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}

int main(int argc, char* argv[]) {
	struct cirListDeque *lst;
	lst = createCirListDeque();
	printf("\n\nTesting addFrontCirListDeque...\n");
	addFrontCirListDeque(lst, 10);
	printf("\n\nTesting addFrontCirListDeque...\n");
	addFrontCirListDeque(lst, 4);
	printf("\n\nTesting addFrontCirListDeque...\n");
	addFrontCirListDeque(lst, 3);
	printf("\n\nTesting addBackCirListDeque...\n");
	addBackCirListDeque(lst, 5);
	printf("\n\nTesting addBackCirListDeque...\n");
	addBackCirListDeque(lst, 6);
	printf("The list's content: [3,4,10,5,6]\n");
	printCirListDeque(lst);
	
	assertTrue(!isEmptyCirListDeque(lst), "Testing isEmptyList");
	assertTrue(EQ(frontCirListDeque(lst), 3), "Test frontCirListDeque == 3");
	assertTrue(EQ(backCirListDeque(lst), 6), "Test backCirListDeque == 6");
	removeFrontCirListDeque(lst);
	assertTrue(EQ(frontCirListDeque(lst), 4), "Test removeFrontList == 4");
	removeBackCirListDeque(lst);
	assertTrue(EQ(backCirListDeque(lst), 5), "Test removeBackList == 5");
	printCirListDeque(lst);

	printf("\n\nTesting reverseCirListDeque...\n");

	reverseCirListDeque(lst);
	printCirListDeque(lst);

	freeCirListDeque(lst);
//	deleteCirListDeque(lst);
	
	printf("Hello from test code!\n");
	return 0;
}


