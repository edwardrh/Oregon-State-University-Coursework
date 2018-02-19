/*************************************************************************
 * Program: netflix.cpp
 * Author: Rhea Mae Edwards
 * Date: 3/5/2015
 * Description: This program creates a structure that holds Netflix data provided by the user, and then outputs the data back to the user. The program will continually ask the user if they want to enter another entry which they will be allowed to do until the user decides not to anymore.
 * Input: Name of Movie, Star-Rating, Names of Cast Members, Movie-Rating
 * Output: Inputted Information
*************************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct netflixs {
   string name;
   int stars;
   string *cast;
   string rating;
};

int main(){
   struct netflixs movie;
   int answer, i, n;
   string mem;

   cout << "Do you want to enter a movie to the database? (1 - Yes, 0 - No): ";
   cin >> answer;
   if(cin.fail()){
      cout << "You did not enter a valid answer." << endl;
      exit(0);
   }
   if(answer != 1 && answer != 0){
      cout << "You did not enter a valid answer." << endl;
      exit(0);
   }
   
   while(answer == 1){
      cout << "Enter the name of your movie: ";
      cin.ignore();
      getline(cin, movie.name);
      cout << "How many stars?: ";
      cin >> movie.stars;
      if(cin.fail()){
         cout << "You did not enter a valid input." << endl;
         exit(0);
      }

      cout << "How many cast members?: ";
      cin >> n;
      
      movie.cast = new string[n+1];

      cin.ignore();
      for(i = 0; i < n; i++){
	 cout << "Enter cast member " << (i+1) << ": ";
	 getline(cin, mem);
	 movie.cast[i] = mem;
      }

      cout << "Enter the movie rating: ";
      cin >> movie.rating;

      cout << endl << "Your movie entry is:" << endl;
      cout << "Title: " << movie.name << endl;
      cout << "Stars: " << movie.stars << endl;
      
      cout << "Cast: ";
      for(i = 0; i < n - 1; i++){
         cout << movie.cast[i] << ", ";
      }
      cout <<  movie.cast[n-1] << endl;

      cout << "Rating: " << movie.rating << endl << endl;

      cout << "Do you want to enter another movie to the database? (1 - Yes, 2 - No): ";
      cin >> answer;
      if(cin.fail()){
         cout << "You did not enter a valid answer." << endl;
         exit(0);
      }
      if(answer != 1 && answer != 0){
         cout << "You did not enter a valid answer." << endl;
         exit(0);
      }
   }

   return 0;
}
