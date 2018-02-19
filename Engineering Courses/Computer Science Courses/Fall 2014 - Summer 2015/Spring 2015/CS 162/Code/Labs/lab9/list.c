#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int length(struct node *n){
	struct node *new = n;
	int count = 0;
	
	while(new != NULL){
		count++;
		new = new -> next;
	}
	
	return count;
}

void push(struct node **n, int v){
	struct node *new = malloc(sizeof(struct node));
	
	new -> val = v;
	new -> next = *n;
	*n = new;
}

void append(struct node **n, int v){
	/*struct node *new = *n;
	
	new = malloc(sizeof(struct node));
	new -> val = v;
	new -> next = NULL;*/
	
	struct node* idea = *n;
	struct node* new;

	new = malloc(sizeof(struct node));
	new -> val = v;
	new -> next = NULL;

	// special case for length 0
	if (idea == NULL) {
		*n = new;
	}
	else {
		// Locate the last node
		while (idea -> next != NULL) {
			idea = idea -> next;
		}
		idea -> next = new;
	}
}

void print(struct node *n, int v){
	while(n != NULL){
		printf("%d\n", n -> val);
		n = n -> next;
	}
}