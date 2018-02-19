#include <iostream>

using namespace std;

void print_array(int **a, int rows, int cols){

   for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
	 cout << a[i][j] << "   ";
      }
      cout << "  " << endl;
   }
   cout << "---------" << endl;

   return;
}

void towers(int **a, int rows, int cols, int n){

   if(n == 1){
      a[2][0] = 1;
      print_array(a, rows, cols);
      a[2][0] = 0;
      a[2][1] = 1;
      print_array(a, rows, cols);
   }

   if(n == 2){
      a[2][0] = 1;
      a[2][2] = 2;
      print_array(a, rows, cols);
      a[2][2] = 0;
      a[2][1] = 2;
      print_array(a, rows, cols);
      a[2][0] = 0;
      a[1][1] = 1;
      print_array(a, rows, cols);
   }

   if(n == 3){
      a[2][0] = 1;
      a[2][2] = 2;
      a[2][1] = 3;
      print_array(a, rows, cols);
      a[2][2] = 0;
      a[1][1] = 2;
      print_array(a, rows, cols);
      a[2][0] = 0;
      a[0][1] = 1;
      print_array(a, rows, cols);
   }

   return;
}

int main(){

   int cols = 3;
   int rows = 3;

   int **array = new int*[rows];

   for(int i = 0; i < rows; i++)
      array[i] = new int[cols];

   int **a = array;

   int n = 3;

   towers(a, rows, cols, n);

   return 0;
}
