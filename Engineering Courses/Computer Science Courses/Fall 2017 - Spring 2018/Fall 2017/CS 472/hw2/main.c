/* ********************************************************************
 * Program: main.c
 * Author: Rhea Mae Edwards
 * Date: 10/30/2017
 *
 * CS 472 Assignment 2 Description:
 * This assignment consists of three parts, which are the following...
 * 
 * Part 1: Implement frexp Function
 * Part 2: Floating Point Operations
 * Part 3: Feature Extraction
 * *******************************************************************/

#define F64_EXP_MAX

#define F64_EXP_MASK 
#define F64_EXP_SHIFT
#define F64_GET_EXP(fp)

#define F64_MANT_MASK
#define F64_MANT_SHIFT
#define F64_GET_MANT_HIGH(fp)
#define F64_GET_MANT_LOW(fp)

#define F64_EXP_BIAS
#define F64_SET_EXP 
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <float.h>
#include <string.h>

int main(int argc, char **argv) {
	
	double numx, numa;
	int numn;
	
	float add, sub, mult, div, sqrt, num1, num2;
		
	// Part 1: Implement frexp Function
	/* 
	- Implement double form of frexp
		- See man pages for details of implementation
		- Your version of funcion, should work identically to supplied version
		- Feel free to use example program from man page as a test case
	- Must use bitshifts and masking to do this
	- Should define macros that defines masks and shifts you'll need,
	  and macros which extract the exponent,
	                   the order bits of the mantissa,
					   and the low order bits of the mantissa
	*/
	
	printf("\nfrexp = Returns memolized decimal\n");
	
	//double numx, numa;
	//int numn; 
	
	numx = 2;
	numa = frexp(numx, &numn);
	
	printf("\nFraction: %lf\nExponent: %d\n", numa, numn);
	
	/* Implement double */
	/* -lm cc -sd = c99 */
	
	/*
	- Multiply by 2 and to 1 off exponent in implementation
	- F64_SET_EXP: Sets all 0's or all 1's if NoN or int
	*/	
	
	// for(volatile int i = 0) // timing
	
	// Part 2: Floating Point Operations
	/* 
	- Implement following floating point operations in software:
		- Addition
		- Subtraction
		- Multiplication
		- Division
		- Square Root
	- For each operation...
		- Compare run time in cycles to the FPU based implementation (in writing)
			- Likely need ~rdtsc instruction
				- Timing discussed in class
	*/
	
	//float add, sub, mult, div, sqrt, num1, num2;
	
	num1 = 2;
	num2 = 5;
	
	add = num1 + num2;
	printf("\nAddition Result: %d\n", add);
	
	sub = num1 - num2;
	printf("Subtraction Result: %d\n", sub);
	
	mult = num1 * num2;
	printf("Multiplication Result: %d\n", mult);
	
	div = num1 / num2;
	printf("Division Result: %d\n", div);
	
	sqrt = sqrtf(num1);
	printf("Square Root Result: %d\n\n", sqrt);
	
	// Part 3: Feature Extraction
	/* 
	- Bit patterns have no meaning until assigned by programmer
		- A bit pattern can be an integer, floating point value, 
		  4 or 8 character string, etc.
	- Write code to treat a given value as each of these things
	- For a given bit pattern, write code capable of answering following questions:
		- If the value is treated as a double, what is the mantissa?
		- If the value is treated as a double, what is the sign?
		- If the value is treated as a double, what is the exponent?
		- If the value is treated as a long, what is the value?
		- If the value is treated as a long, what is the sign?
		- If the value is treated as 8 characters, what are they?
	- Write code that would print out answers to all above questions.
	  Include enough information to determine which question being answered,
	  and ensure answer easily interpreted
	- For each of these, need to treat a single value as if multiple values
		- One way, is to type cast a struct that has same amount of storage
		  as type interested in
		- Another approach is to make use of a union
	*/
	
	printf("If the value is treated as a double, what is the mantissa?\n");
	printf("If the value is treated as a double, what is the sign?\n");
	printf("If the value is treated as a double, what is the exponent?\n");
	printf("If the value is treated as a long, what is the value?\n");
	printf("If the value is treated as a long, what is the sign?\n");
	printf("If the value is treated as 8 characters, what are they?\n\n");
	
	/*
	Row Major:
	- Stride
	- array[Stride * row + column] OR array[row][column]
	*/
	
	/*
	Column Major:
	- array[row + stride * column]
	*/
	
	//printf("%s\n", vendor);

   return 0;
}

/*
// Example of use of the _asm_ construct
	
	unsigned int eax;
	unsigned int ebx;
	unsigned int ecx;
	unsigned int edx;
	
	char vendor[13];
	
	eax = 0x00;
	
	//
	__asm__ __volatile___(
							"cpuid;"
							: "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
							: "a"(eax)
							);
   
	memcpy(vendor, (char*)&ebx, 4);
	memcpy(vendor + 4, (char*)&edx, 4);
	memcopy(vendor + 8), (char*)&ecx, 4);
	vendor[12] = 0;
	//
*/
