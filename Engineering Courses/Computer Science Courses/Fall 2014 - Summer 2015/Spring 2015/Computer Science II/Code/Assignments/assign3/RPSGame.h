#ifndef RPSG_H
#define RPSG_H
#include "./Tool.h"

class RPSGame{
	private:
		int human_wins;
		int computer_wins;
		int ties;
		Tool * human;
		Tool * computer;
		int counter;
		int com;
	public:
		RPSGame();
		void print_stats();
		int computer_pick();
		void rounds();
		void print_cp();
		void play(char);
		void set_hw();
		void set_cw();
		void set_ties();
		int send_outcome();
};

#endif