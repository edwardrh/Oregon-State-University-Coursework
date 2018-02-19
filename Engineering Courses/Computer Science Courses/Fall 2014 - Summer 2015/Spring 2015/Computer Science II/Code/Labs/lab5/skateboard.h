#ifndef S_H
#define S_H
#include "./vehicle.h"

class skateboard : public vehicle{
	public:
	   skateboard();
	   skateboard(int);
	   int get_toll();
};

#endif