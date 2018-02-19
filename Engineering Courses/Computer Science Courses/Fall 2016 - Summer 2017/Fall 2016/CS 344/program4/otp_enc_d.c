/******************************************************************
 * Program: otp_enc_d.c
 * Author: Rhea Mae Edwards
 * Date: 12/2/2016
 * Overview:
 * - Run in background as a daemon
 * - Output an error if cannot be run due to network error,
 *   such ports being unavailable
 * - Perform actual encoding
*******************************************************************/

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

/*******************************************************************
 * Program Notes:
 * - Listens on particular port/socket that was assigned
 * - When connection to otp_enc_d is made,
 *   calls accept() to generate socket for actual communication,
 *   uses separate process to handle rast of transaction,
 *   occures on newly accepted socket
 *
 * - In child process, first checks make sure 
 *   communicating with otp_enc
 * - After verification, child receives plaintext and a key
 *   via communication socket
 * - Child then writes back ciphertext to otp_enc process
 *   connected via same communication socket
 * - Key passed in must be at least as big as the plaintext
 *
 * - Supports up to 5 concurrent socket connections
 * - Only in child process actual encryption takes place,
 *   and ciphertext written back
 *
 * - Either can create child with fork(),
 *   new process every time a connection is made,
 *   or set up a pool of 5 processes at beginnign of program,
 *   before connections are allowed to handle encryption tasks
 * - Able to do 5 separate encryptions at once,
 *   using either method you choose
 *
 * Syntax:
 *
 * otp_enc_d [listening_port]
 *
 * - listening_port = port should listen on
 *
 * Example: 
 * 
 * otp_enc_d 57171 &
 *
 * - All error situations must output errors appropriately,
 *   should not crash or othereise exit
 * - All error text outputs to stderr
 *
 * - All 4 network programs use "localhost"
 *   as the target IP address/host,
 *   to make use actual computer they all share
 *   as the target for the networking connections
********************************************************************/
