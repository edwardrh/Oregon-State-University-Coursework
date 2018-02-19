/* ********************************************************************
 * Program: main.c
 * Author: Rhea Mae Edwards
 * Date: 10-10-2017
 *
 * CS 472 Assignment 1 Description:
 * Write a C program that returns the following information about your
 * CPU, using the CPUID assembly instruction:
 * 		- L1 data cache size (with line info)
 *		- L1 instruction cache size (with line info)
 *		- TLB information (any and all)
 *		- Memory hierarch information
 *		- Physical address width
 *		- Logical address width
 *		- Number of logical CPUs
 *		- CPU family
 *		- CPU model (number and name)
 *		- CPU frequency
 *		- CPU features available
 * *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
	
	// Example of use of the _asm_ construct
	
	unsigned int eax;
	unsigned int ebx;
	unsigned int ecx;
	unsigned int edx;
	
	char vendor[13];
	
	eax = 0x00;
	
	/*
	__asm__ __volatile___(
							"cpuid;"
							: "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
							: "a"(eax)
							);
   
	memcpy(vendor, (char*)&ebx, 4);
	memcpy(vendor + 4, (char*)&edx, 4);
	memcopy(vendor + 8), (char*)&ecx, 4);
	vendor[12] = 0;
	*/
	
	printf("%s\n", vendor);
	
	// L1 data cache size (with line info)
	
	// L1 instruction cache size (with line info)
	
	// TLB information (any and all)
	
	// Memory hierarch information
	
	// Physical address width
	
	// Logical address width
	
	// Number of logical CPUs
	
	// CPU family
	
	// CPU model (number and name)
	
	// CPU frequency
	
	// CPU features available

   return 0;
}