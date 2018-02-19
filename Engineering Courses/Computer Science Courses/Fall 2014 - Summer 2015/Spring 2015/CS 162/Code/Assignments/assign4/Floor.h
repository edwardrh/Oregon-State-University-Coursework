#ifndef F_H
#define F_H
#include "Room.hpp"

class Floor{
   private:
      //vector < vector <char> > v;
      int obj_row; //Holds an object’s current row position
      int obj_col; //Holds an object’s current col position
   public:
      //The functionality of a floor is to create the floor
      //plan, as well as determining if an object’s
      //position is at the edge of the room
	  Floor();
	  Floor(int, int);
	  void set_v();
	  //vector get_v();
	  void set_obj_row();
	  void set_obj_col();
	  int get_obj_row();
	  int get_obj_col();
	  int check_pos();
};

#endif