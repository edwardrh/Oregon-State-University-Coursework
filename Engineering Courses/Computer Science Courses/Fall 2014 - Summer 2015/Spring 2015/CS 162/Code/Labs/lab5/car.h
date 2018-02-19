#ifndef C_H
#define C_H
#include "./vehicle.h"

class car : public vehicle{
	private:
	   int seats;
	   int num;
	public:
	   car();
	   car(int);
	   int get_toll(int);
};

#endif