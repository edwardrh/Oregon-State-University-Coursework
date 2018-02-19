/****************************
** Program: netflix.cpp
** Author: Rhea Mae Edwards
** Date: 04/29/2015
** Description: Allows user to search or enter in a movie of/into a database.
** Input: Requests, Movie Information
** Output: Movie Information
****************************/

#include "./netflix.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ios;
using std::string;

netflix::netflix(){
}

movie* netflix::netflixs(int num_movies){
   m = new movie[num_movies];
   return m;
}

netflix::netflix(const netflix &mov){
   num_movies = mov.num_movies;
   if(num_movies == 0) m = NULL;
   else{
      m = new movie[num_movies];
      for(int i = 0; i < num_movies; i++)
	 m[i] = mov.m[i];
   }
}

void netflix::operator = (const netflix &mov){
   if(m != NULL) delete [] m;
   num_movies = mov.num_movies;
   if(num_movies == 0) m = NULL;
   else{
      m = new movie[num_movies];
      for(int i = 0; i < num_movies; i++)
	 m[i] = mov.m[i];
   }
}

netflix::~netflix(){
   delete [] m;
   m = NULL;
}

void netflix::input_movie(){
   cout << "How many movies do you want to enter to the database? ";
   cin >> num_movies;
   cout << endl;
   netflix n;
   n.netflixs(num_movies);
   for(int i = 0; i < num_movies; i++){
      movie m;
      m.input_info(i);
   }
}

void netflix::name(string name){
   char c[256];
   fstream iofile;
   iofile.open("netflix.dat", ios:: in);
   /*while(!iofile.eof()){
	   iofile.peek();
   }*/
   /*char oldname[] = "netflix.dat";
   char newname[] = "netflix2.dat";
   rename(oldname, newname);*/
   iofile.close();
   
}

void netflix::stars(int stars){
   char c[256];
   fstream iofile;
   iofile.open("netflix.dat", ios:: in);
   iofile.close();
}

void netflix::cast(string member){
   char c[256];
   fstream iofile;
   iofile.open("netflix.dat", ios:: in);
   iofile.close();
}

void netflix::rating(int rating){
   char c[256];
   fstream iofile;
   iofile.open("netflix.dat", ios:: in);
   iofile.close();
}
