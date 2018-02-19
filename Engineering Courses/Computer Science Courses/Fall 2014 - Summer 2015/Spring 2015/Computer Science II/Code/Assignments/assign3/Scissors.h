#ifndef SCISSORS_H
#define SCISSORS_H
#include "./Tool.h"
#include "./RPSGame.h"

class Scissors : public Tool{
	private:
		int strength;
		char type;
		int result;
		Tool t;
	public:
		Scissors();
		Scissors(int);
		int fight(Tool);
		void set_result();
};

#endif