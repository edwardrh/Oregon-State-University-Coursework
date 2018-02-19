/*******************************
 * Program: connect_four.cpp
 * Author: Rhea Mae Edwards
 * Date: 04/07/2015
 * Description:
 * Input:
 * Output:
*******************************/

#include "./connect_four.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool is_valid_arguments(char *info[]){
   for(int i = 1; i < 7; i + 2){
      string inf = string(info[i]);
      if(inf == "-r"){
	 int in = atoi(info[i+1]);
	 if(in < 1){
	    cout << "You cannot have " << info[i+1] << " for the number of rows." << endl;
	    cout << "Please enter a positive, non-zero integer for the number of rows: ";
	    cin >> info[i+1];
	 }
      }
      if(inf == "-c"){
	 int in = atoi(info[i+1]);
	 if(in < 1){
	    cout << "You cannot have " << info[i+1] << " for the number of columns." << endl;
	    cout << "Please enter a positive, non-zero integer for the number of columns: ";
	    cin >> info[i+1];
	 }
      }
      if(inf == "-p"){
	 int in = atoi(info[i+1]);
	 if(in < 1){
	    cout << "You cannot have " << info[i+1] << " pieces to connect." << endl;
	    cout << "Please enter a positive, non-zero integer for the number of pieces to connect: ";
	    cin >> info[i+1];
	 }
      }
      else if(inf != "-r" && inf != "-c" && inf != "-p"){
	 cout << "Invalid command-line." << endl;
	 return 0;
      }
   }
   return 1;
}

void set_game_info(game *, char *info[]){
   game cf;

   for(int i = 2; i < 8; i + 2){
      string inf = info[i];
      if(inf == "-r"){
	 cf.r = atoi(info[i+1]);
      }
      if(inf == "-c"){
	 cf.c = atoi(info[i+1]);
      }
      if(inf == "-p"){
	 cf.p = atoi(info[i+1]);
      }
   }

   cf.board = create_table(cf.r, cf.c);

   cout << "Player one, do you wnat red or yellow (r or y)? ";
   cin >> cf.p1;
   if(cf.p1 == 'r'){
      cf.p2 = 'y';
   }
   if(cf.p1 == 'y'){
      cf.p2 = 'r';
   }
}

char** create_table(int r, int c){
   char **layout = new char*[r];
   for(int i = 0; i < r; i++){
      layout[i] = new char[c];
   }
   return layout;
}

void play_game(game *){
   game cf;
   int col;
   bool play = 1;

   while(play = 1){
      cout << "Player 1, what column do you want to put your piece? ";
      cin >> col;
      if(cin.fail()){
	 cout << "Please enter a valid column number: ";
	 cin >> col;
      }
      if(col >= cf.c){
	 cout << "Please enter a valid column number: ";
	 cin >> col;
      }
      int check = 1;
      while(check == 1){
         for(int i = cf.r - 1; i >= 0; i--){
            if(cf.board[i][col-1] != 'r' || cf.board[i][col-1] != 'y'){
	       cf.board[i][col-1] = cf.p1;
	       check = 0;
            }
	 }
         if(cf.board[0][col-1] == 'r' || cf.board[0][col-1] == 'y'){
	    cout << "You cannot put a piece in that column." << endl;
	    cout << "Please enter another column you would like to put your piece in: ";
	    cin >> col;
         }
      }
      for(int i = 0; i < cf.r; i++){
         cout << "|";
         for(int j = 0; j < cf.c; j++){
	    cout << " " << cf.board[i][j] << " |";
         }
         cout << endl;
         for(int j = 0; j < cf.c; j++){
            cout << "---";
         }
         cout << endl;
      }

      play = check_winner(cf);

      cout << "Player 2, what column do you want to put your piece? ";
      cin >> col;
      if(cin.fail()){
	 cout << "Please enter a valid column number: ";
	 cin >> col;
      }
      if(col >= cf.c){
	 cout << "Please enter a valid column number: ";
	 cin >> col;
      }
      check = 1;
      while(check == 1){
         for(int i = cf.r - 1; i >= 0; i--){
            if(cf.board[i][col-1] != 'r' || cf.board[i][col-1] != 'y'){
	       cf.board[i][col-1] = cf.p2;
	       check = 0;
            }
	 }
         if(cf.board[0][col-1] == 'r' || cf.board[0][col-1] == 'y'){
	    cout << "You cannot put a piece in that column." << endl;
	    cout << "Please enter another column you would like to put your piece in: ";
	    cin >> col;
         }
      }
      for(int i = 0; i < cf.r; i++){
         cout << "|";
         for(int j = 0; j < cf.c; j++){
	    cout << " " << cf.board[i][j] << " |";
         }
         cout << endl;
         for(int j = 0; j < cf.c; j++){
            cout << "---";
         }
         cout << endl;
      }

      play = check_winner(cf);

   }
}

bool check_winner(game){
   game cf;
   for(int i = 0; i < cf.r; i++){
      for(int j = 0; j < cf.c; j++){
	 if(cf.board[i][j] == cf.p1){
	    int check = 1;
	    while(check == 1){
	       for(int z = 0; z < cf.p; z++){
	          if(cf.board[i][j+z] == cf.p1){
		     check = 1;
	          }
	          if(cf.board[i+z][j] == cf.p1){
		     check = 1;
	          }
	          if(cf.board[i+z][j+z] == cf.p1){
		     check = 1;
	          }
	          if(cf.board[i-z][j+z] == cf.p1){
		     check = 1;
	          }
	          if(cf.board[i-z][j+z] != cf.p1 && cf.board[i+z][j+z] != cf.p1 && cf.board[i+z][j] != cf.p1 && cf.board[i][j+z] != cf.p1){
		     return 1;
	          }
	       }
	       check = 0;
	    }
	    cout << "Player 1 wins the game!" << endl;
	    return 0;
	 }
	 if(cf.board[i][j] == cf.p2){
	    int check = 1;
	    while(check == 1){
	       for(int z = 0; z < cf.p; z++){
	          if(cf.board[i][j+z] == cf.p2){
		     check = 1;
	          }
	          if(cf.board[i+z][j] == cf.p2){
		     check = 1;
	          }
	          if(cf.board[i+z][j+z] == cf.p2){
		     check = 1;
	          }
	          if(cf.board[i-z][j+z] == cf.p2){
		     check = 1;
	          }
	          if(cf.board[i-z][j+z] != cf.p2 && cf.board[i+z][j+z] != cf.p2 && cf.board[i+z][j] != cf.p2 && cf.board[i][j+z] != cf.p2){
		     return 1;
	          }
	       }
	       check = 0;
	    }
	    cout << "Player 2 wins the game!" << endl;
	    return 0;
	 }
      }
   }
   return 1;
}

void delete_table(game *){
   game cf;
   for(int i = 0; i < cf.c; i++){
      delete[] cf.board[i];
   }
   delete [] cf.board;
   cf.board = NULL;
}
