/***************************************************************************************************
 * Program: roman.cpp
 * Author: Rhea Mae Edwards
 * Date: 2/14/2015
 * Discription: This program converts roman numerals into decimals and decimals into roman numerals.
 * Inputs: String of Characters, Integers
 * Outputs: Integers, String of Characters
 **************************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

void get_user_inpu(string &romans, int &dec){

   cout << "Enter a string in roman numerals: ";
   cin >> romans;

   cout << "Enter a number to be converted into a roman numeral: ";
   cin >> dec;

   return;
}

void m(string &romans, int &total){

   int x;

   total = 0;
   for (x = 0; x <= romans.length() - 1; x++){
      if(romans[x] == 'M'){
	 if(romans[x-1] == 'C'){
	    total += 900;
	 }
	 else{
	    total += 1000;
	 }
      }
   }

   return;
}

void d(string &romans, int &total){
   
   m(romans, total);

   int x;

   for (x = 0; x <= romans.length() - 1; x++){
      if(romans[x] == 'D'){
	 if(romans[x-1] == 'C'){
	    total += 400;
	 }
	 else{
	    total += 500;
	 }
      }
   }

   return;
}

void c(string &romans, int &total){

   d(romans, total);
   
   int x;
 
   for (x = 0; x <= romans.length() - 1; x++){
      if(romans[x] == 'C'){
	 if(romans[x-1] == 'X'){
	    total += 90;
	 }
	 else{
	    total += 100;
	 }
      }
   }

   return;
}

void l(string &romans, int &total){

   c(romans, total);
   
   int x;

   for (x = 0; x <= romans.length() - 1; x++){
      if(romans[x] == 'L'){
	 if(romans[x-1] == 'X'){
	    total += 40;
	 }
	 else{
	    total += 50;
	 }
      }
   }

   return;
}

void x(string &romans, int &total){

   l(romans, total);
   
   int x;

   for (x = 0; x <= romans.length() - 1; x++){
      if(romans[x] == 'X'){
	 if(romans[x-1] == 'I'){
	    total += 9;
	 }
	 else{
	    total += 10;
	 }
      }
   }

   return;
}

void v(string &romans, int &total){

   x(romans, total);
   
   int x;

   for (x = 0; x <= romans.length() - 1; x++){
      if(romans[x] == 'V'){
	 if(romans[x-1] == 'I'){
	    total += 4;
	 }
	 else{
	    total += 5;
	 }
      }
   }

   return;
}

void i(string &romans, int &total){

   v(romans, total);
   
   int x;

   for (x = 0; x <= romans.length() - 1; x++){
      if(romans[x] == 'I'){
	 total += 1;
      }
   }

   return;
}

void rom_to_dec(string &romans, int &total){

   i(romans,total);

   cout << total << endl;
   
   return;
}

void z(int &dec){

   while(dec >= 1000){
      dec -= 1000;
      cout << 'M';
   }
   while(dec >= 900){
      dec -= 900;
      cout << 'C';
      cout << 'M';
   }
   return;
}

void y(int &dec){

   z(dec);

   while(dec >= 500){
      dec -= 500;
      cout << 'D';
   }
   while(dec >= 400){
      dec -= 400;
      cout << 'C';
      cout << 'D';
   }
   return;
}

void x(int &dec){

   y(dec);

   while(dec >= 100){
      dec -= 100;
      cout << 'C';
   }
   while(dec >= 90){
      dec -= 90;
      cout << 'X';
      cout << 'C';
   }
   return;
}

void w(int &dec){

   x(dec);

   while(dec >= 50){
      dec -= 50;
      cout << 'L';
   }
   while(dec >= 40){
      dec -= 40;
      cout << 'X';
      cout << 'L';
   }

   return;
}

void v(int &dec){

   w(dec);

   while(dec >= 10){
      dec -= 10;
      cout << 'X';
   }
   while(dec >= 9){
      dec -= 9;
      cout << 'I';
      cout << 'X';
   }

   return;
}

void u(int &dec){

   v(dec);

   while(dec >= 5){
      dec -= 5;
      cout << 'V';
   }
   while(dec >= 4){
      dec -= 4;
      cout << 'I';
      cout << 'V';
   }

   return;
}

void dec_to_rom(int &dec){

   u(dec);

   while(dec >= 1){
      dec -= 1;
      cout << 'I';
   }

   cout << endl;

   return;
}

int main(){

   int dec, total;
   string romans;

   get_user_inpu(romans, dec);

   rom_to_dec(romans, total);
   dec_to_rom(dec);

   return 0;
}
