#include "linkedList.h"
#include "linkedList.c"
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
	struct linkedList *lst;
	lst = createLinkedList();
	
	printf("\n\nTesting addFrontList...\n");
	addFrontList(lst, 10);
	printf("\n\nTesting addFrontList...\n");
	addFrontList(lst, 4);
	printf("\n\nTesting addFrontList...\n");
	addFrontList(lst, 3);
	printf("\n\nTesting addBackList...\n");
	addBackList(lst, 5);
	printf("\n\nTesting addBackList...\n");
	addBackList(lst, 6);
	
	printf("The list's content: [3,4,10,5,6]\n");
	assertTrue(containsList(lst, 3), "Test 1st element == 3");
	assertTrue(containsList(lst, 4), "Test 2nd element == 4");
	assertTrue(containsList(lst, 10), "Test 3rd element == 10");
	assertTrue(containsList(lst, 5), "Test 4th element == 5");
	assertTrue(containsList(lst, 6), "Test 5th element == 6");
	_printList(lst);
	
	printf("\n\nTesting removeList...\nCalling removeList(lst, 3)\n");
	removeList(lst, 3);
	printf("The list's content: [4,10,5,6]\n");
	_printList(lst);
	
	printf("\n\nTesting stack interface...\n");
	printf("The stack's content: [4,10,5,6]\n");
	assertTrue(isEmptyList(lst), "Testing isEmptyList");
	assertTrue(EQ(frontList(lst), 4), "Test frontList == 4");
	assertTrue(EQ(backList(lst), 6), "Test backList == 6");
	removeFrontList(lst);
	assertTrue(EQ(frontList(lst), 10), "Test removeFrontList == 10");
	removeBackList(lst);
	assertTrue(EQ(backList(lst), 5), "Test removeBackList == 5");
	_printList(lst);
	
	freeLinkedList(lst);
	deleteLinkedList(lst);

	printf("Hello from test code!\n");
	return 0;
}


