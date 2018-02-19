#ifndef PAPER_H
#define PAPER_H
#include "./Tool.h"

class Paper : public Tool{
	private:
		int strength;
		char type;
		int result;
	public:
		Paper();
		Paper(int);
		int fight(Tool);
		void set_result(int);
};

#endif