/* CS261- Assignment 1 - Q.3*/
/* Name: Rhea Mae Edwards
 * Date: October 9th, 2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
	 int i, j, num;
	 for(i = 1; i < n; i++){
		 for(j = i - 1; j < n; j++){
			 num = number[i];
			 if(number[i] < number[j]){
				 number[i] = number[j];
				 number[j] = num;
			 }
		 }
	 }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n, i;
	int* arr;
	n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    arr = malloc(n * sizeof(int));
    /*Fill this array with random numbers between 0 and n, using rand().*/
    for(i = 0; i < n; i++){
		arr[i] = rand() % n;
	}
    /*Print the contents of the array.*/
	printf("Unsorted Array of Integers:\n");
	for(i = 0; i < n; i++){
		printf("%d\n", arr[i]);
	}
    /*Pass this array along with n to the sort() function.*/
    sort(arr, n);
    /*Print the contents of the array.*/	
    printf("Sorted Array of Integers:\n");
	for(i = 0; i < n; i++){
		printf("%d\n", arr[i]);
	}
    return 0;
}
