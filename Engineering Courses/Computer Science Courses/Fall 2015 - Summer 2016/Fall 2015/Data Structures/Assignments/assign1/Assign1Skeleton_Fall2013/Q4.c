/* CS261- Assignment 1 - Q.4*/
/* Name: Rhea Mae Edwards
 * Date: October 9th, 2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
     /* Remember, each student must be matched with their original score after sorting */
	 /*int i, j;
	 struct student* s = NULL;
	 for(i = 0; i < n; i++){
		 for(j = i + 1; j < n-1; j++){
		     if(students[i].score < students[j].score){
			    s->id = students[i].id;
				s->score = students[i].score;
			    students[i] = students[j];
				students[j].id = s->id;
				students[j].score = s->score;
			 }
		 }
	 }*/
}

int main(){
    /*Declare an integer n and assign it a value.*/
    struct student* students;
	int n, i, num;
	//int j, again;
	n = 5;
    /*Allocate memory for n students using malloc.*/
    students = malloc(n * sizeof(struct student));
    /*Generate random IDs and scores for the n students, using rand().*/
	 for(i = 0; i < n; i++){
		 //again = 0;
		 //while(again == 0){
			 num = rand() % n + 1;
			 students[i].id = num;
			 /*for(j = 0; j < n; j++){
				 if(students[j].id != students[i].id){
				     //students[i].id = num;
					 again = 1;
				 }
				 else
					 again = 0;
			 }
		 }*/
		 /*again = 0;
		 while(again == 0){*/
			 num = rand() % 100;
			 //for(j = 0; j < n; j++){
				 students[i].score = num;
				 /*if(students[j].score != students[i].score){
				     students[i].score = num;
					 again = 1;
				 }
				 else
					 again = 0;
			 }
		 }*/
	 }
    /*Print the contents of the array of n students.*/
	printf("Students Unsorted:\n");
	for(i = 0; i < n; i++){
		 printf("ID%d ", students[i].id);
		 printf("Score%d\n", students[i].score);
	 }
    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    /*Print the contents of the array of n students.*/
	printf("Students Sorted by Scores:\n");
    for(i = 0; i < n; i++){
		 printf("ID%d ", students[i].id);
		 printf("Score%d\n", students[i].score);
	 }
    return 0;
}
