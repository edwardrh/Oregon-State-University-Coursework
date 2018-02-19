#include "./RPSGame.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

RPSGame::RPSGame(){
	human_wins = 0;
	computer_wins = 0;
	ties = 0;
	counter = 0;
}

void RPSGame::print_stats(){
	cout << "Human Wins: " << human_wins << endl;
	cout << "Computer Wins: " << computer_wins << endl;
	cout << "Ties: " << ties << endl;
}

void RPSGame::rounds(){
	counter++;
	if(counter > 18){
		counter = 1;
	}
}

void RPSGame::play(char y){
	int outcome;
	char pick;
	pick = y;
	RPSGame::rounds();
	RPSGame::print_cp();
	if(pick == 'r'){
		if(com == 0){
			cout << "Tie." << endl;
			outcome = 0;
		}
		else if(com == 1){
			cout << "Computer Wins!" << endl;
			outcome = 1;
		}
		else if(com == 2){
			cout << "You Win!!!" << endl;
			outcome = 2;
		}
	}
	else if(pick == 'p'){
		if(com == 0){
			cout << "You Win!!!" << endl;
			outcome = 2;
		}
		else if(com == 1){
			cout << "Tie." << endl;
			outcome = 0;
		}
		else if(com == 2){
			cout << "Computer Wins!" << endl;
			outcome = 1;
		}
	}
	else if(pick == 's'){
		if(com == 0){
			cout << "Computer Wins!" << endl;
			outcome = 1;
		}
		else if(com == 1){
			cout << "You Win!!!" << endl;
			outcome = 2;
		}
		else if(com == 2){
			cout << "Tie." << endl;
			outcome = 0;
		}
	}
	if(outcome == 0){
		RPSGame::set_ties();
	}
	else if(outcome == 1){
		RPSGame::set_cw();
	}
	else if(outcome == 2){
		RPSGame::set_hw();
	}
}

void RPSGame::set_hw(){
	human_wins++;
}

void RPSGame::set_cw(){
	computer_wins++;
}

void RPSGame::set_ties(){
	ties++;
}

int RPSGame::computer_pick(){
	if(counter == 1 || counter == 7 || counter == 8 || counter == 13 || counter == 14 || counter == 15){
		return 0; //rock
	}
	else if(counter == 2 || counter == 3 || counter == 9 || counter == 10 || counter == 11 || counter == 16){
		return 1; //paper
	}
	else if(counter == 4 || counter == 5 || counter == 6 || counter == 12 || counter == 17 || counter == 18){
		return 2; //scissors
	}
}

void RPSGame::print_cp(){
	int x = RPSGame::computer_pick();
	com = x;
	if(x == 0){
		cout << "Computer chose rock." << endl;
	}
	else if(x == 1){
		cout << "Computer chose paper." << endl;
	}
	else if(x == 2){
		cout << "Computer chose scissors." << endl;
	}
}