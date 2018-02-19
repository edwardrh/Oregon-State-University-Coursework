/*******************************
 * Program: play_cf.cpp
 * Author: Rhea Mae Edwards
 * Date: 04/07/2015
 * Description:
 * Input:
 * Output:
*******************************/

#include "./connect_four.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *info[]){
   cout << "lame";
   int again;
   game cf;

   if(argc != 7){
      cout << "Invalid command-line." << endl;
      return 0;
   }
   is_valid_arguments(info);
   set_game_info(&cf, info);
   play_game(&cf);
   delete_table(&cf);

   cout << "Do you want to play again (0-no, 1-yes)? ";
   cin >> again;

   while(again == 1){
      cout << "Enter the amount of rows: ";
      cin >> cf.r;
      cout << "Enter the amount of columns: ";
      cin >> cf.c;
      cout << "Enter the amount of pieces to connect: ";
      cin >> cf.p;

      set_game_info(&cf, info);
      play_game(&cf);
      delete_table(&cf);
      
      cout << "Do you want to play again (0-no, 1-yes)? ";
      cin >> again;
   }

   return 0;
}
