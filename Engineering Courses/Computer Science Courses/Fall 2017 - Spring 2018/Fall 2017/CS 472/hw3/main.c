/* ********************************************************************
 * Program: main.c
 * Author: Rhea Mae Edwards
 * Date: 11/20/2017
 *
 * CS 472 Assignment 3 Description:
 * This assignment consists of three parts regarding this code, 
 * which are the following...
 * 
 * Part 3: Implement frexp Function
 * Part 4: Floating Point Operations
 * Part 5: Feature Extraction
 * 
 * See pdf/LaTex document in regards to further explainations for 
 * each indicated part of the code for the assignment.
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
	
	short val;
	char *p_val;
	p_val = (char *) &val;
	
	/*
	  The following two lines assume big-endian
	  Architecture to initialize the variable Val
	  to 0x1234.
	*/
	
	p_val[0] = 0x12;
	p_val[1] = 0x34;
	printf("%x\n", val);

   return 0;
}

/**

Further assitance provided by following source:
https://www.ibm.com/developerworks/library/l-port-linux-on-x86-application/

**/
