/************************************************************************************************************************************************
** Program: main.cpp
** Author: Rhea Mae Edwards
** Date: 05/08/2015
** Description: This program initializes strengths for each tool played in the game, conducts the traditional game of Rock, Paper, Scissors with a single user and a programmed opponent.
** Input: Integer values for the initial strengths of the tools, user's choice based off characters
** Output: Strengths of tools, Outcomes of the current round, Current stats of the overall game, Error messages, Welcome message, Ending Message
************************************************************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include "./RPSGame.h"
#include "./Tool.h"
#include "./Scissors.h"
#include "./Paper.h"
#include "./Rock.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
	int x, y, z, now;
	char start, play;
	RPSGame game;
	Tool t;
	
	cout << "Welcome to Rock, Paper, Scissors!" << endl;
	cout << "Do you want to choose different strengths for the tools? (y - yes, n - no) ";
	cin >> start;
	
	if(start == 'y'){
		cout << "What strength would you like for rock? ";
		cin >> x;
		Rock r(x);
		cout << "What strength would you like for paper? ";
		cin >> y;
		Paper p(y);
		cout << "What strength would you like for scissors? ";
		cin >> z;
		Scissors s(z);
		cout << "Your chosen initial strengths:" << endl;
		cout << "Rock: " << x << endl;
		cout << "Paper: " << y << endl;
		cout << "Scissors: " << z << endl;
	}
	else if(start == 'n'){
		Rock r(1);
		Paper p(1);
		Scissors s(1);
	}
	else if(start != 'y' && start != 'n'){
		cout << "You did not enter a valid answer." << endl;
		exit(0);
	}
	
	now = 1;
	while(now == 1){
		cout << "Choose your tool (r - rock, p - paper, s - scissors, e - exit): ";
		cin >> play;
		if(play == 'e'){
			cout << "Thank you for playing!" << endl;
			now = 0;
		}
		else if(play != 'r' && play != 'p' && play != 's' && play != 'e'){
			cout << "You did not enter a valid answer" << endl;
			now = 0;
		}
		else if(play == 'r'){
			game.play('r');
			game.print_stats();
		}
		else if(play == 'p'){
			game.play('p');
			game.print_stats();
		}
		else if(play == 's'){
			game.play('s');
			game.print_stats();
		}
	}
	
	return 0;
}