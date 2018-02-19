/******************************************************************
 * Program: keygen.c
 * Author: Rhea Mae Edwards
 * Date: 12/2/2016
 * Overview:
 * - Creates a key file of specified length
 * - Characters will be any of 27 allowed characters,
 *   generated using standard UNIX randomization methods
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {


   return 0;
}

/*****************************************************************
 * Program Notes:
 * - Do not create spaces every five characters
 * - Do not have to do any fancy random number generation
 *   rand() is just fine
 * - Last character keygen outputs newline
 * - All error text outputs to stderr, if any
 *
 * - Syntax for keygen:
 *   keygen [keylength]
 *
 * - keylength = length of key file in characters
 * - keygen outputs to stdout
 *
 * Example:
 * - Redirects stdout to a key file of 256 characters called "mykey"
 *   
 *   keygen 256 > mykey
 *
 * Hints:
 * - Accepts the 26 capital letters of the alphabet
 *   and the "space" character for encryption/decryption
 * - When a program reads an input file,
 *   strip off the newline character
 * - When send result to stdout, or save results into a file,
 *   tack a newline character to the end (for length reasons)
 * - Newline character affects lengths reported by wc command
*****************************************************************/
