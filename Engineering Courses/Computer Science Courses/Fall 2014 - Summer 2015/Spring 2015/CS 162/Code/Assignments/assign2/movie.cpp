/****************************
** Program: movie.cpp
** Author: Rhea Mae Edwards
** Date: 04/29/2015
** Description: Allows user to search or enter in a movie of/into a database.
** Input: Requests, Movie Information
** Output: Movie Information
****************************/

#include "./movie.h"
#include <string.h>
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ios;
using std::string;

movie::movie(){
}

string* movie::movies(int num_cast){
   cast = new string[num_cast];
   return cast;
}

movie::movie(const string &c){
   num_cast = c.length();
   if(num_cast == 0) cast = NULL;
   else{
      cast = new string[num_cast];
      for(int i = 0; i < num_cast; i++)
	 cast[i] = c.at(i);
   }
}

void movie::operator = (const string &c){
   if(cast != NULL) delete [] cast;
   num_cast = c.length();
   if(num_cast == 0) cast = NULL;
   else{
      cast = new string[num_cast];
      for(int i = 0; i < num_cast; i++)
	 cast[i] = c.at(i);
   }
}

movie::~movie(){
   delete [] cast;
   cast = NULL;
}

void movie::input_info(int i){
   fstream iofile;
   iofile.open("netflix.dat", ios::app);
   i = i+4;
   cout << "Enter the name of your movie: ";
   cin >> name;
   cout << "How many stars? ";
   cin >> stars;
   cout << "How many cast members? ";
   cin >> num_cast;
   movies(num_cast);
   for(int j = 0; j < num_cast; j++){
      cout << "Enter cast member " << j+1 << ": ";
      cin >> cast[j];
   }
   cout << "Enter the movie rating: ";
   cin >> rating;
   cout << "How many copies of this movie: ";
   cin >> copies;
   iofile << i << "|" << name << "|" << stars << "|";
   for(int k = 0; k < num_cast; k++){
	   iofile << cast[k] << "|";
   }
   iofile << rating << "|" << copies << "|0";
   iofile.close();

   cout << endl << "Added to the database!" << endl << endl;
}
