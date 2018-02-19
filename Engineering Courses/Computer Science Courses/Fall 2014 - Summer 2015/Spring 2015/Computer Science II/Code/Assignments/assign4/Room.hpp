/*template <typename T>
class Floor{
   private:
      //char vector < vector <char> > v;
      int obj_row; //Holds an object’s current row position
      int obj_col; //Holds an object’s current col position
   public:
      //The functionality of a floor is to create the floor
      //plan, as well as determining if an object’s
      //position is at the edge of the room
	  Floor();
	  Floor(int, int);
	  void set_v();
	  void vector get_v();
	  void set_obj_row();
	  void set_obj_col();
	  int get_obj_row();
	  int get_obj_col();
	  int check_pos();

};

class Room{
   private:
      Floor f;
      T *obj; //obj could be a Roomba, Person, etc.
   public:
      //The functionality of a room is to view it, put
      //objects in it, take objects out of it, etc.
	  void clean_room();
	  void set_obj();
	  T get_obj();
	  void view_floor();
	  void set_floor();
	  //Big 3
	  //set_roomba(*x){
		  //obj = x;
	  //}
      void clean_room(){
         if(obj != NULL)
         obj->clean_floor(f);
      }
};

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
	  virtual void clean_floor(&floor);
};

class RandomRoomba : public Roomba{
   private:
      
   public:
      void clean_floor(Floor&);
};

class AverageRoomba : public Roomba{ //for first AI Roomba
   private:
      
   public:
      void clean_floor(Floor&);
};

class SmartRoomba : public Roomba{ //for second AI Roomba
   private:
      
   public:
      void clean_floor(Floor&);
};*/