#include <stdlib.h>
#include <stdio.h>
#include "./merge.h"
#define nullptr NULL

void divideList(struct node* first1, struct node** first2){
	struct node* middle;
	struct node* current;
	
	if(first1 == NULL) //list is empty
		*first2 = NULL;
	else if(first1 -> next == NULL) //list has only one node
		*first2 = NULL;
	else{
		middle = first1;
		current = first1 -> next;
		if(current != NULL) //list has more than two nodes
			current = current -> next;
		while(current != NULL){
			middle = middle -> next;
			current = current -> next;
			if(current != NULL)
				current = current -> next;
		} //end while
		*first2 = middle -> next;
		middle -> next = NULL;
	} //end else
} //end divideList

struct node* mergeList(struct node* first1, struct node* first2){
	struct node *lastSmall; //pointer to the last node
	struct node *newHead; //pointer to the merged list
	
	if(first1 == NULL) //the first sublist is empty
		return first2;
	else if (first2 == NULL) //the second sublist is empty
		return first1;
	else{
		if(first1 -> info < first2 -> info){ //compare the first nodes
			newHead = first1;
			first1 = first1 -> next;
			lastSmall = newHead;
		}
		else{
			newHead = first2;
			first2 = first2 -> next;
			lastSmall = newHead;
		}
		while(first1 != NULL && first2 != NULL){ 
			if(first1 -> info < first2 -> info){
				lastSmall -> next = first1;
				lastSmall = lastSmall -> next;
				first1 = first1 -> next;
			}
			else{ 
				lastSmall -> next = first2;
				lastSmall = lastSmall -> next;
				first2 = first2 -> next;
			}
		} //end while
		if(first1 == NULL) //first sublist is exhausted first
			lastSmall -> next = first2;
		else //second sublist is exhausted first
			lastSmall -> next = first1;
		return newHead;
	}
}//end mergeList

void recMergeSort(struct node** head){
	struct node* otherHead;

	if(*head != NULL) //if the list is not empty
		if((*head) -> next != NULL){ //if list has more than one
			divideList(*head, &otherHead);
			recMergeSort(head);
			recMergeSort(&otherHead);
			*head = mergeList(*head, otherHead);
		}
} //end recMergeSort

void mergeSort(struct node **first, struct node **last){
	recMergeSort(first);
	
	if(*first == NULL)
		*last = NULL;
	else{
		*last = *first;
		while((*last) -> next != NULL)
			*last = (*last) -> next;
	}
} //end mergeSort