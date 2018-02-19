/*******************************************************************
 * Program: otp_dec.c
 * Author: Rhea Mae Edwards
 * Date: 12/2/2016
 * Overview:
 * - Connects to otp_dec_d, and asks to decrypt ciphertext
 *   using a passed-in ciphertext and key
 * - Performs exactly like otp_enc,
 *   and runnable in same three ways
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

/******************************************************************
 * Program Notes:
 * - Not able to connect to otp_enc_d,
 *   even if tries to connect on correct port
 *   - Need have programs reject each other,
 *     as described in otp_enc
******************************************************************/
