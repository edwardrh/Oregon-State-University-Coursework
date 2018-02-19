#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string.h>

using std::string;

class movie{
   public:
      movie();
      string* movies(int); //This will set num_cast and create cast array
      movie(const string &); //copy constructor
      ~movie(); //destructor
      void operator = (const string &); //assignment operator overload
      void input_info(int);
   private:
      string name;
      int stars;
      int num_cast;
      string *cast; //This is a dynamic array of strings
      string rating;
      int copies;
};

#endif
