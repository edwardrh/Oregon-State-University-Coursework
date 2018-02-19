/****************************
** Program: main.cpp
** Author: Rhea Mae Edwards
** Date: 04/29/2015
** Description: Allows user to search or enter in a movie of/into a database.
** Input: Requests, Movie Information
** Output: Movie Information
****************************/

#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "./netflix.h"

using std::fstream;
using std::ios;
using std::endl;
using std::cout;
using std::cin;
using std::string;

int main(){
   int ans, find, stars, rating, on;
   string name, member;
   on = 1;
   netflix net;
   while(on == 1){
	   cout << endl;
      cout << "Do you want to enter a movie to the database or find a movie to rent? (1 - enter, 2 - find, or 0 - exit) ";
      cin >> ans;
      cout << endl;
      if(ans == 1){
            net.input_movie();
         }
	 else if(ans == 2){
	    cout << "Do you want to find movies based on: (1 - name, 2 - number of stars, 3 - specific cast member, or 4 rating)? ";
	    cin >> find;
	    cout << endl;
	    if(find == 1){
	       cout << "What is the title? ";
	       cin >> name;
	       cout << endl;
	       net.name(name);
	    }
	    else if(find == 2){
	       cout << "How many stars? ";
	       cin >> stars;
	       cout << endl;
	       net.stars(stars);
	    }
	    else if(find == 3){
	       cout << "What is the name of the cast member? ";
	       cin >> member;
	       cout << endl;
	       net.cast(member);
	    }
	    else if(find == 4){
	       cout << "What is the rating? ";
	       cin >> rating;
	       cout << endl;
	       net.rating(rating);
	    }
	 }
      else if(ans == 0){
	     on = 0;
		 exit(1);
      }
   }

   return 0;
}
