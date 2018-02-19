/********************************************************************
 * Program: otp_enc.c
 * Author: Rhea Mae Edwards
 * Date: 12/2/2016
 * Overview:
 * - Connects to otp_enc_d,
 *   and asks to perform a one-time pad style encryption
 * - Does not do the encryption
********************************************************************/

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
 * Syntax:
 *
 * otp_enc [plaintext] [key] [port]
 *
 * - plaintext = name of file in current directory
 *               that contains plaintext wish to encrypt
 * - key = contains encryption key wish to encrypt the text
 * - port = port otp_enc should attempt to connect to otp_enc_d on
 *
 * - When ciphertext receives, outputs to stdout
 * - Sends output appropriately, 
 *   by being launched by any following methods:
 *
 *   otp_enc myplaintext mykey 57171
 *   otp_enc myplaintext mykey 57171 > myciphertext
 *   otp_enc myplaintext mykey 57171 > myciphertext &
 *
 * - If receieves key or plaintext files with bad characters,
 *   or key file is shorter than plaintext,
 *   should exit with an error, and set exit value to 1
 * - Character validation happen either
 *   otp_enc or otp_enc_d, your choice
 * - If otp_enc cannot find the port,
 *   should report this error to the screen with bad port,
 *   and set exit value to 2
 * - Otherwise on successfully running, set exit value to 0
 *
 * - Not able to connect to otp_dec_d,
 *   even if tries to connect on correct port
 *   - Need programs reject each other
 * - If this happens, reports rejection, then terminate itself
 *
 * - All error text output to stderr
*******************************************************************/
