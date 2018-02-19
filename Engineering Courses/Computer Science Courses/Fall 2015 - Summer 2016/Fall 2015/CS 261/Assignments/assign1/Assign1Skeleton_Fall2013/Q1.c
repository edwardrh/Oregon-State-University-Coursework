/* CS261- Assignment 1 - Q.1*/
/* Name: Rhea Mae Edwards
 * Date: October 8th, 2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* s = malloc(10 * sizeof(struct student));
     /*return the pointer*/
	 return s;
}

void generate(struct student* students){
     /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
     int i, num;
	 //int j, again;
	 for(i = 0; i < 10; i++){
		 //again = 0;
		 //while(again == 0){
			 num = rand() % 10 + 1;
			 students[i].id = num;
			 /*for(j = 0; j < 10; j++){
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
			 //for(j = 0; j < 10; j++){
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
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
     int i;
	 for(i = 0; i < 10; i++){
		 printf("ID%d ", students[i].id);
		 printf("Score%d\n", students[i].score);
	 }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int i, max, min, total;
	 max = students[0].score;
	 min = students[0].score;
	 total = 0;
	 for(i = 0; i < 10; i++){
		 if(students[i].score > max){
			 max = students[i].score;
		 }
		 if(students[i].score < min){
			 min = students[i].score;
		 }
		 total += students[i].score;
	 }
	 printf("Minimum Score: %d\nMaximum Score: %d\nAverage Score: %d\n", min, max, total/10);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	 free(stud);
}

int main(){
    struct student* stud = NULL;
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
	deallocate(stud);
    return 0;
}
