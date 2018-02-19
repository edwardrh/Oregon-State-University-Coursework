#ifndef B_H
#define B_H
#include "./vehicle.h"

class bike : public vehicle{
	public:
	   bike();
	   bike(int);
	   int get_toll();
};

#endif