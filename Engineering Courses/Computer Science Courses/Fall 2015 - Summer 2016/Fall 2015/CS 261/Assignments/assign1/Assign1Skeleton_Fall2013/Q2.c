/* CS261- Assignment 1 - Q.2*/
/* Name: Rhea Mae Edwards
 * Date: October 9th, 2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = (*a)*2;
    /*Set b to half its original value*/
    *b = (*b)/2;
    /*Assign a+b to c*/
    c = (*a) + (*b);
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x, y, z, val;
	x = 7;
	y = 8;
	z = 9;
    /*Print the values of x, y and z*/
    printf("Value of x: %d\n", x);
	printf("Value of y: %d\n", y);
	printf("Value of z: %d\n", z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    val = foo(&x, &y, z);
    /*Print the value returned by foo*/
    printf("Value Returned by foo: %d\n", val);
    /*Print the values of x, y and z again*/
	printf("Value of x: %d\n", x);
	printf("Value of y: %d\n", y);
	printf("Value of z: %d\n", z);
    /*Is the return value different than the value of z?  Why?*/
	//No, because the the initial variable of z was not permanently manipulated since
	//its address was not passed by the function.
    return 0;
}
    
    
