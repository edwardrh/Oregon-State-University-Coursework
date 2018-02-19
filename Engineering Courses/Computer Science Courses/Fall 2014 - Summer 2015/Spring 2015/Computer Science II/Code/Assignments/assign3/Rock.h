#ifndef ROCK_H
#define ROCK_H
#include "./Tool.h"

class Rock : public Tool{
	private:
		int strength;
		char type;
		int result;
	public:
		Rock();
		Rock(int);
		int fight(Tool);
		void set_result(int);
};

#endif