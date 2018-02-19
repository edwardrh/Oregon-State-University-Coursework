#include <iostream>
#include <cstdlib>

using namespace std;

struct mult_div_values{
   int mult;
   float div;
};

bool is_valid_diminsions(char *m, char *n){


   return;
}

mult_div_values** create_table(int m, int n){
   int **table = new int*[m];

   for(int i = 0; i < m; i++)
      table[i] = new int[n];

   return table;
}

void set_mult_values(mult_div_values **table, int m, int n){
   for(int i)
	 

   delete_table();
}

void set_div_values(mult_div_values **table, int m, int n){


   delete_table();
}

void delete_table(mult_div_values ***table, int m){


}

int main(int argc, char *argv[]){
   rows = atoi(argv[1]);
   cols = atoi(argv[2]);
   is_valid_diminsions(rows, cols);
   set_mult_values();
   set_div_values();

   return 0;
}
