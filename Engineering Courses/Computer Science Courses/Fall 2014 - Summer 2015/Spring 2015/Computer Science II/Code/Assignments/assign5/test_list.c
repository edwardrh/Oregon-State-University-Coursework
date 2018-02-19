/*****************************************************************************
** Program: test_list.c
** Author: Rhea Mae Edwards
** Date: 06/07/2015
** Description: Program reads integers from the user and creates a linked list 
	with them either by pushing or appending them, and continues to do so until 
	the user decides to stop, then the program sorts the integers one of two 
	orders depending on the input from the user, then the program asks the user 
	again if they would like to create another list or not.
** Input: Integers, characters
** Output: Guidelines from what the user should enter, List of inputted integers
*****************************************************************************/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
	char ans[2];
	int num;
	struct node *head = NULL;
	struct node *tail;

	do {
		do {
			printf("Enter a number: ");
			scanf("%d", &num);
			head = push(head, num);//Can change to append

			printf("Do you want another num (y or n): ");
			scanf("%1s",ans);
		} while(ans[0] == 'y');
 
		printf("Sort ascending or descending (a or d)? ");
		scanf("%1s",ans);
		
		if(ans[0] == 'a') head=sort_ascending(head);
		else if(ans[0] == 'd') head=sort_descending(head);

		print(head /*, length(head)*/);
		
		printf("Do you want to do this again (y or n)? ");
		scanf("%1s",ans);
		if(ans[0] == 'y') head = clear(head);

	} while(ans[0] == 'y');

	return 0;
}