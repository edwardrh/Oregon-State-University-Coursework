#ifndef V_H
#define V_H

class vehicle{
	private: 
	   int seats;
	public:
	   vehicle();
	   vehicle(int);
	   int get_seats();
	   virtual int get_toll();
};

#endif