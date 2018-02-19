#ifndef ROOM_H
#define ROOM_H
#include "./Floor.h"

class Room{
   private:
      Floor f;
      //T *obj; //obj could be a Roomba, Person, etc.
   public:
      //The functionality of a room is to view it, put
      //objects in it, take objects out of it, etc.
	  void clean_room();
	  void set_obj();
	  //T get_obj();
	  void view_floor();
	  void set_floor();
	  //Big 3
	  //set_roomba(*x);
};

#endif