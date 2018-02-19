#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int length(struct node *n){
	struct node *new = n;
	int count = 0;
	
	while(new != NULL){
		count++;
		new = new -> next;
	}
	
	return count;
}

void print(struct node *n /*, int v*/){
	printf("Your linked list is: \n");
	while(n != NULL){
		printf("%d ", n -> val);
		n = n -> next;
	}
	printf("\n");
}

struct node * push(struct node *n, int v){
	struct node *new = malloc(sizeof(struct node));
	
	new -> val = v;
	new -> next = n;
	
	return new;
}

struct node * append(struct node *n, int v){
	struct node* idea = n;
	struct node* new;

	new = malloc(sizeof(struct node));
	new -> val = v;
	new -> next = NULL;

	// special case for length 0
	if (idea == NULL) {
		idea = new;
	}
	else {
		// Locate the last node
		while (idea -> next != NULL) {
			idea = idea -> next;
		}
		idea -> next = new;
	}
	
	return idea;
	
	//The code that would support a tail. **Addition Code**
	/*struct node* idea = n;
	struct node* new;
	
	new = malloc(sizeof(struct node));
	new -> val = v;
	new -> next = tail;
	
	idea -> tail = new;
	
	return idea;*/
}

struct node * clear(struct node *n){
	struct node* idea = n;
	struct node* new;
	
	while(idea != NULL){
		new = idea -> next;
		free(idea);
		idea = new;
	}
	
	return idea;
}

struct node * remove1(struct node *n, int v){
	//Have it be able to remove something.
	//You'll be sending the head, then checking an int value inputted,
	//Then removing nodes, or changing pointers that point to node that hold that value,
	//To point to the next node, somehow removing the node that holds that value,
	//From the linked list completely.
	struct node* idea = n;
	struct node* new;
	
	while(idea != NULL){
		if(idea -> val == v){
			new = idea -> next;
			free(idea);
			idea = new;
		}
		else{
			idea = idea -> next;
		}
	}
	
	return idea;
}

struct node * sort_ascending(struct node *n){
	//You can just change vals.
	struct node* first = n;
	struct node* second = n -> next;
	int i;
	
	while(first != NULL && second != NULL){
		while(second != first){
			if(second -> val < first -> val){
				i = first -> val;
				first -> val =  second -> val;
				second -> val = i;
			}
			first = first -> next;
		}
		first = n;
		second = second -> next;
	}
	
	return first;
}

struct node * sort_descending(struct node *n){
	//You can just change vals.
	struct node* first = n;
	struct node* second = n -> next;
	int i;
	
	while(first != NULL && second != NULL){
		while(second != first){
			if(second -> val > first -> val){
				i = first -> val;
				first -> val =  second -> val;
				second -> val = i;
			}
			first = first -> next;
		}
		first = n;
		second = second -> next;
	}
	
	return first;
}

struct node * insert_middle(struct node *n, int i /*index*/, int j /*data*/){
	struct node* idea;
	int k;
	
	if(i == 0){ //position 1 is a special case...
		idea = push(n, j);
	}
	else{
		idea = n;
		for(k = 0; k < i-1; k++){
			assert(idea != NULL);
			idea = idea -> next;
		}
		assert(idea != NULL);
		push(idea -> next, j); //OR push(&(idea -> next), j);
	}
	
	return idea;
}