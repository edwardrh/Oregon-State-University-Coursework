/******************************
* Program: simulate_roomba.cpp
* Author: Rhea Mae Edwards
* Date: 5/26/2015
* Description: Simulates a Roomba to clean a completely dirty floor till it's all clean.
* Inputs: Filename, Battery Life, Moves before Viewing, Starting Row, Starting Column, Choice of Roomba
* Outputs: Floor Plan, Moves of Roomba, Overall Number of Moves of Roomba
******************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
/*#include “./Room.hpp”
#include “./RandomRoomba.h”
#include “./AverageRoomba.h”
#include “./SmartRoomba.h”*/

using namespace std;

/*void choose_roomba(Room <Roomba> &r){
   int choice;
   cout << "Which Roomba (1 – Random, 2 - Average, 3 - Smart)? ";
   cin >> choice;

   if(choice == 1)
      r.set_roomba(new RandomRoomba);
   else if(choice == 2)
	  r.set_roomba(new AverageRoomba);
   else if(choice == 3)
	  r.set_roomba(new SmartRoomba);
}

void simulate_roomba(){
   Room <Roomba> r;

   choose_roomba(r);
   //More setup is needed for the Room
   
   r.clean_room(); //Now clean it after everything is setup
   
}*/

int main(int argc, char *argv[]){
	string check;
	int check2;
	
	if(argc != 11){
		cout << "You're missing arguments in your command line." << endl;
		exit(0);
	}
	check = argv[1];
	if(check != "-f"){
		cout << "Your command line is incorrect." << endl;
		exit(0);
	}
	else if(check == "-f"){
		
	}
	check = argv[3];
	if(check != "-b"){
		cout << "Your command line is incorrect." << endl;
		exit(0);
	}
	else if(check == "-b"){
		cout << "Battery Life: " << argv[4] << endl;
	}
	check = argv[5];
	if(check != "-r"){
		cout << "Your command line is incorrect." << endl;
		exit(0);
	}
	else if(check == "-r"){
		cout << "Starting Row: " << argv[6] << endl;
	}
	check = argv[7];
	if(check != "-c"){
		cout << "Your command line is incorrect." << endl;
		exit(0);
	}
	else if(check == "-c"){
		cout << "Starting Column: " << argv[8] << endl;
	}
	check = argv[9];
	if(check != "-v"){
		cout << "Your command line is incorrect." << endl;
		exit(0);
	}
	else if(check == "-v"){
		cout << "Moves Before Viewing: " << argv[10] << endl;
	}
	
	cout << endl << "Note from the Writer: " << endl;
	cout << "This is the end of my program. It just reads and checks the command line the user's inputs. There is code present in this program to run a simulation of some sort, but the program doesn't work properly with it, so  I commented it out for this program to at least compile. You are welcomed to look at my commented-out code. I am aware I just failed this assignment. Thank you for your understanding." << endl << endl;
	
	//simulate_roomba();
	
	return 0;
}
