#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);
  TYPE task;
  char desc[128];
  int pri;
  char ran[128];
  FILE * myfile = fopen("todo.txt", "r");

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');
      // FIXED
      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
		  if(cmd == 'l'){
			  printf("Please enter the filename: ");
			  scanf("%s", ran);
			  loadList(mainList, myfile);
			  printf("The list has been loaded from file successfully.\n");
		  }
		  else if(cmd == 's'){
			  printf("Please enter the filename: ");
			  scanf("%s", ran);
			  saveList(mainList, myfile);
			  printf("The list has been saved into the file successfully.\n");
		  }
		  else if(cmd == 'a'){
			  printf("Please enter the task description: ");
			  scanf("%s", desc);
			  printf("Please enter the task priority (0-999): ");
			  scanf("%d", &pri);
			  
			  task = createTask(pri, desc);
			  addHeap(mainList, task, compare);
			  
			  printf("The task '%s' has been added to your to-do list.\n", desc);
		  }
		  else if(cmd == 'g'){
			  if(getMinHeap(mainList) == NULL){
				  printf("Your to-do list is empty!\n");
			  }
			  else{
				  printf("Your first task is: %p\n", getMinHeap(mainList));
			  }
		  }
		  else if(cmd == 'r'){
			  printf("Your first task '%p' has been removed from the list.\n", getMinHeap(mainList));
			  removeMinHeap(mainList, compare);
		  }
		  else if(cmd == 'p'){
			  printList(mainList);
		  }
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);
  printf("Bye!\n");

  return 0;
}
