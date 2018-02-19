#include "merge.h"
#include <stdio.h>
#include <stdlib.h>
#define nullptr NULL

void printList(struct node *n){
	while(n != NULL){
		printf("%d ", n -> info);
		n = n -> next;
	}
	printf("\n");
}

int main (){
	char ans;
	int num;
	struct node *head = NULL;
	struct node *other = NULL;
	
	do{
		printf("Enter a number: ");
		scanf("%d", &num);
		
		struct node *new = malloc(sizeof(struct node));
		new -> info = num;
		new -> next = head;
		head = new;
	
		printf("Do you want another num (y or n): ");
		scanf("%1s",&ans);
	} while(ans == 'y');
	
	printf("Linked List Before Using mergeSort: \n");
	printList(head);
	
	mergeSort(&head, &other);
	
	printf("Linked List After Using mergeSort: \n");
	printList(head);
	
	return 0;
}