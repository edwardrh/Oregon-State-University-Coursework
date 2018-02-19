/*****************************************************************
** Program: numbers.cpp
** Author: Rhea Mae Edwards
** Date: 2/4/2015
** Discription: This program prints out values of created variables, and returns ASCII values of inputted characters by the user.
** Inputs: Characters, Binary Values
** Outputs: Number Values, ASCII Values, Characters, Binary Values
******************************************************************/

#include <iostream>
#include <climits>
#include <cmath>
#include <string>
#include <bitset>
#include <stdlib.h>

using namespace std;

void bin_to_ascii(string &base){
   int y, result, i;

   cout << "The inputted (" << base << ")'s string of characters: ";

   for(y = 0; y <= base.length() - 1; y += 8){
      result = 0;
      for(i = 0; i <= 7; i++){
	 if(base.at(i+y) == '1'){
	    result += pow(2,(7-i));
	 }
      }
      cout << (char) result;
   }
   cout << endl;

   return;
}

void ascii_to_bin(string &mssg){
   int x;
   
   cout << "The inputted (" << mssg << ")'s string of ASCII values in base 2: ";

   x = 0;
   for(x = 0; x <= mssg.length() - 1; x++){
      cout << bitset<8>(mssg.c_str()[x]);
   }
   cout << endl;

   return;

}

void get_user_inpu(string &mssg, string &base){

   cout << "Enter a string of characters: ";
   cin >> mssg;

   cout << "Enter a string of ASCII values in base 2: ";
   cin >> base;

   return;
}

void check_bin_number(string &base){
   int x;

   for(x = base.length() - 1; x > 0; --x){
      if(base.at(x) != '1' && base.at(x) != '0'){
	 cout << "You did not enter a valid string of binary values." << endl << endl;
         exit(0);
      }
   }

   return;   
}

int main(int argc, char *argv[]){

	unsigned int umin;
	int imin;
	int imax;
	unsigned int uimax;

	short smin;
	short smax;
	unsigned short usmax;

	long lmin;
	long lmax;
	unsigned long ulmax;

	char character;
	int num;
	int a, b, c, d, e, f, g, h;

	string mssg, base;

	cout << endl << "Values created by using macros of the climits library: " << endl << "Minimum Signed Integer: " << INT_MIN << endl << "Maximum Signed Integer: " << INT_MAX << endl << "Minimum Unsigned Integer: 0" << endl << "Maximum Unsigned Integer: " << UINT_MAX << endl << "Minimum Signed Short: " << SHRT_MIN << endl << "Maximum Signed Short: " << SHRT_MAX << endl << "Minimum Unsigned Short: 0" << endl << "Maximum Unsigned Short: " << USHRT_MAX << endl << "Minimum Signed Long: " << LONG_MIN << endl << "Maximum Signed Long: " << LONG_MAX << endl << "Minimum Unsigned Long: 0" << endl << "Maximum Unsigned Long: " << ULONG_MAX << endl;

	cout << endl << "Values manually created: " << endl;

	umin = 0;

	imin = (int) (-pow(2, sizeof(int)*16-1));
	imax = (int) pow(2, sizeof(int)*16-1)-1;
	uimax = (unsigned int) pow(2, sizeof(int)*8)-1;

	cout << "Minimum Signed Integer: " <<  imin << endl;
	cout << "Maximum Signed Integer: " <<  imax << endl;
	cout << "Minimum Unsigned Integer: " << umin  << endl;
	cout << "Maximum Unsigned Integer: " << uimax << endl;

	smin = (short) -(pow(2, sizeof(short)*8-1));
	smax = (short)(pow(2, sizeof(short)*8-1)-1);
	usmax = (unsigned short)(pow(2, sizeof(short)*8)-1);

	cout << "Minimum Signed Short: " << smin << endl;
	cout << "Maximum Signed Short: " << smax << endl;
	cout << "Minimum Unsigned Short: " << umin  << endl;
	cout << "Maximum Unsigned Short: " << usmax << endl;

	lmin = (long) -(pow(2, sizeof(long)*8-1));
	lmax = (long) pow(2, sizeof(long)*8-1)-1;
	ulmax = (unsigned long) pow(2, sizeof(long)*8)-1;

	cout << "Minimum Signed Long: " << lmin << endl;
	cout << "Maximum Signed Long: " << lmax << endl;
	cout << "Minimum Unsigned Long: " << umin  << endl;
	cout << "Maximum Unsigned Long: " << ulmax << endl;

	cout << endl << "Addition of one to each Signed and Unsigned Maximums: " << endl;

	cout << "Maximum Signed Integer: " << imax + 1 << endl;
	cout << "Maximum Unsigned Integer: " << uimax + 1 << endl;
	cout << "Maximum Signed Short: " << smax + 1 << endl;
	cout << "Maximum Unsigned Short: " << usmax + 1 << endl;
	cout << "Maximum Signed Long: " << lmax + 1 << endl;
	cout << "Maximum Unsigned Long: " << ulmax + 1 << endl;

	cout << "What I Noticed: I noticed that now when I add one to the maximums, the singed maximums are equal and opposited signed from their corresponding minimums, whereas the unsigned maximums are equal to their corresponding minimums of zero, with the exception of the unsigned short maximum which just simply increased by one." << endl;

	cout << endl <<  "Enter a character: ";
	cin >> character;

	cout << "The ASCII value of your inputted value in decimal form  is " << (int) character << "." << endl;

	num = (int) character;

	a = num/pow(2,7);
	num = num-pow(2,7)*a;

	b = num/pow(2,6);
	num = num-pow(2,6)*b;

	c = num/pow(2,5);
	num = num-pow(2,5)*c;

	d = num/pow(2,4);
	num = num-pow(2,4)*d;

	e = num/pow(2,3);
	num = num-pow(2,3)*e;

	f = num/pow(2,2);
	num = num-pow(2,2)*f;

	g = num/pow(2,1);
	num = num-pow(2,1)*g;

	h = num/2;
	num = num-2*h;

	cout << "The ASCII value of your inputted value in binary form is " << a <<  b << c << d <<  e << f << g << h << "." << endl;

	cout << "The ASCII value of your inputted value in hexadecimal form is " << hex << (int) character << "." << endl <<  endl;

	if(argc != 5){
	   cout << "You did not enter the correct number of options and/or arguments correctly." << endl << endl;
	   exit(0);
	}

	//get_user_inpu(mssg, base);
	mssg = argv[4];
	base = argv[2];
	
	check_bin_number(base);
	ascii_to_bin(mssg);
	bin_to_ascii(base);

	cout << endl;

	return 0;
}
