#ifndef NETFLIX_H
#define NETFLIX_H
#include "./movie.h"
#include <iostream>
#include <string.h>

using std::string;

class netflix {
   public:
      netflix();
      movie* netflixs(int);
      netflix(const netflix &); //copy constructor
      ~netflix(); //destructor
      void operator = (const netflix &); //assignment operator overload
      void input_movie();
      void name(string);
      void stars(int);
      void cast(string);
      void rating(int);
   private:
      movie *m; //This is a dynamic array of movies
      int num_movies;
};

#endif
