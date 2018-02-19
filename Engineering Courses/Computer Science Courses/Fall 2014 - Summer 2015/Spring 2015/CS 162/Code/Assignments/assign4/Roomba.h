#ifndef ROOMBA_H
#define ROOMBA_H
#include "./Floor.h"

class Roomba{
   private:
      int battery; //how many moves it can make
      int total_moves; //total moves needed to clean
   public:
      //The Roomba needs to be able to clean a floor, and
      //move left, right, up, down
	  void set_battery();
	  void set_total_move();
	  int get_battery();
	  int get_total();
	  void move_left();
	  void move_right();
	  void move_up();
	  void move_down();
	  virtual void clean_floor(Floor &);
};

#endif