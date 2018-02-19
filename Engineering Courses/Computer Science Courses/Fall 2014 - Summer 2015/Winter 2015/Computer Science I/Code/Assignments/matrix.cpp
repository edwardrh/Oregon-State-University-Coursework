/**************************************************************
 * Program: matrix.cpp
 * Author: Rhea Mae Edwards
 * Date: 3/5/2015
 * Discription: This program creates matrices and then find the greatest product of four adjacent numbers within the created matrix.
 * Inputs: Rows, Columns
 * Outputs: Matrix, Greatest Product, Starting Position, Shape
**************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int **create_array1(int rows, int cols){
   int i;

   int **matrix = new int*[rows];

   for(i = 0; i < rows; i++)
      matrix[i] = new int[cols];

   return matrix;
}

int **initialize_array1(int **m, int rows, int cols){

   int i, j, num;

   srand(time(NULL));

   for(i = 0; i < rows; i++)
      for(j = 0; j < cols; j++){
	 num = rand() % 50 + 1;
	 m[i][j] = num;
      }

   return m;
}

int **initialize_array2(int **m, int rows, int cols){

   for(int i = 0; i < rows; i++)
      for(int j = 0; j < cols; j++)
	 cin >> m[i][j];

   return m;
}

void print_array(int **m, int rows, int cols){

   int i, j;

   cout << "Your matrix is:" << endl;

   for(i = 0; i < rows; i++){
      for(j = 0; j < cols; j++){
	 if(m[i][j] < 10){
	    cout << m[i][j] << "   ";
	 }
	 else{
	    cout << m[i][j] << "  ";
	 }
      }
      cout << "  " << endl;
   }

   return;
}

int ldd(int **m, int rows, int cols, int max_ldd){
   max_ldd = 0;
   int num_ldd = 0;
   for(int i = 0; i < rows - 3; i++){
      for(int j = 0; j < cols - 3; j++){
	 int product = m[i][j]*m[i+1][j+1]*m[i+2][j+2]*m[i+3][j+3];
	 if(product > num_ldd){
            num_ldd = product;
	    max_ldd = num_ldd;
	 }
      }
   }

   return max_ldd;
}

void ldd(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_ldd = 0;
   for(int i = 0; i < rows - 3; i++){
      for(int j = 0; j < cols - 3; j++){
	 int product = m[i][j]*m[i+1][j+1]*m[i+2][j+2]*m[i+3][j+3];
	 if(product > num_ldd){
            num_ldd = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int lud(int **m, int rows, int cols, int max_lud){
   max_lud = 0;
   int num_lud = 0;
   for(int i = rows - 1; i > 2; i--){
      for(int j = 0; j < cols - 3; j++){
	 int product = m[i][j]*m[i-1][j+1]*m[i-2][j+2]*m[i-3][j+3];
	 if(product > num_lud){
	    num_lud = product;
	    max_lud = num_lud;
	 }
      }
   }

   return max_lud;
}

void lud(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_lud = 0;
   for(int i = rows - 1; i > 2; i--){
      for(int j = 0; j < cols - 3; j++){
	 int product = m[i][j]*m[i-1][j+1]*m[i-2][j+2]*m[i-3][j+3];
	 if(product > num_lud){
	    num_lud = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int rdd(int **m, int rows, int cols, int max_rdd){
   max_rdd = 0;
   int num_rdd = 0;
   for(int i = 0; i < rows - 3; i++){
      for(int j = cols - 1; j > 2; j--){
	 int product = m[i][j]*m[i+1][j-1]*m[i+2][j-2]*m[i+3][j-3];
	 if(product > num_rdd){
	    num_rdd = product;
	    max_rdd = num_rdd;
	 }
      }
   }

   return max_rdd;
}

void rdd(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_rdd = 0;
   for(int i = 0; i < rows - 3; i++){
      for(int j = cols - 1; j > 2; j--){
	 int product = m[i][j]*m[i+1][j-1]*m[i+2][j-2]*m[i+3][j-3];
	 if(product > num_rdd){
	    num_rdd = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int rud(int **m, int rows, int cols, int max_rud){
   max_rud = 0;
   int num_rud = 0;
   for(int i = rows - 1; i > 2; i--){
      for(int j = cols - 1; j > 2; j--){
	 int product = m[i][j]*m[i-1][j-1]*m[i-2][j-2]*m[i-3][j-3];
	 if(product > num_rud){
	    num_rud = product;
	    max_rud = num_rud;
	 }
      }
   }

   return max_rud;
}

void rud(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_rud = 0;
   for(int i = rows - 1; i > 2; i--){
      for(int j = cols - 1; j > 2; j--){
	 int product = m[i][j]*m[i-1][j-1]*m[i-2][j-2]*m[i-3][j-3];
	 if(product > num_rud){
	    num_rud = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int rl(int **m, int rows, int cols, int max_rl){
   max_rl = 0;
   int num_rl = 0;
   for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols - 3; j++){
	 int product = m[i][j]*m[i][j+1]*m[i][j+2]*m[i][j+3];
	 if(product > num_rl){
	    num_rl = product;
	    max_rl = num_rl;
	 }
      }
   }

   return max_rl;
}

void rl(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_rl = 0;
   for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols - 3; j++){
	 int product = m[i][j]*m[i][j+1]*m[i][j+2]*m[i][j+3];
	 if(product > num_rl){
	    num_rl = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int ud(int **m, int rows, int cols, int max_ud){
   max_ud = 0;
   int num_ud = 0;
   for(int i = 0; i < rows - 3; i++){
      for(int j = 0; j < cols; j++){
	 int product = m[i][j]*m[i+1][j]*m[i+2][j]*m[i+3][j];
	 if(product > num_ud){
	    num_ud = product;
	    max_ud = num_ud;
	 }
      }
   }

   return max_ud;
}

void ud(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_ud = 0;
   for(int i = 0; i < rows - 3; i++){
      for(int j = 0; j < cols; j++){
	 int product = m[i][j]*m[i+1][j]*m[i+2][j]*m[i+3][j];
	 if(product > num_ud){
	    num_ud = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int box(int **m, int rows, int cols, int max_box){
   max_box = 0;
   int num_box = 0;
   for(int i = 0; i < rows - 1; i++){
      for(int j = 0; j < cols - 1; j++){
	 int product = m[i][j]*m[i][j+1]*m[i+1][j]*m[i+1][j+1];
	 if(product > num_box){
	    num_box = product;
	    max_box = num_box;
	 }
      }
   }

   return max_box;
}

void box(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_box = 0;
   for(int i = 0; i < rows - 1; i++){
      for(int j = 0; j < cols - 1; j++){
	 int product = m[i][j]*m[i][j+1]*m[i+1][j]*m[i+1][j+1];
	 if(product > num_box){
	    num_box = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int lzz(int **m, int rows, int cols, int max_lzz){
   max_lzz = 0;
   int num_lzz = 0;
   for(int i = 0; i < rows - 3; i++){
      for(int j = 0; j < cols - 1; j++){
	 int product = m[i][j]*m[i+1][j+1]*m[i+2][j]*m[i+3][j+1];
	 if(product > num_lzz){
	    num_lzz = product;
	    max_lzz = num_lzz;
	 }
      }
   }

   return max_lzz;
}

void lzz(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_lzz = 0;
   for(int i = 0; i < rows - 3; i++){
      for(int j = 0; j < cols - 1; j++){
	 int product = m[i][j]*m[i+1][j+1]*m[i+2][j]*m[i+3][j+1];
	 if(product > num_lzz){
	    num_lzz = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int rzz(int **m, int rows, int cols, int max_rzz){
   max_rzz = 0;
   int num_rzz = 0;
   for(int i = 0; i < rows - 3; i++){
      for(int j = cols - 1; j > 0; j--){
	 int product = m[i][j]*m[i+1][j+1]*m[i+2][j]*m[i+3][j-1];
	 if(product > num_rzz){
	    num_rzz = product;
	    max_rzz = num_rzz;
	 }
      }
   }

   return max_rzz;
}

void rzz(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_rzz = 0;
   for(int i = 0; i < rows - 3; i++){
      for(int j = cols - 1; j > 0; j--){
	 int product = m[i][j]*m[i+1][j+1]*m[i+2][j]*m[i+3][j-1];
	 if(product > num_rzz){
	    num_rzz = product;
	    row = i;
	    row = j;
	 }
      }
   }

   return;
}

int l1(int **m, int rows, int cols, int max_l1){
   max_l1 = 0;
   int num_l1 = 0;
   for(int i = 0; i < rows - 2; i++){
      for(int j = 0; j < cols - 1; j++){
	 int product = m[i][j]*m[i+1][j]*m[i+2][j]*m[i+2][j+1];
	 if(product > num_l1){
	    num_l1 = product;
	    max_l1 = num_l1;
	 }
      }
   }

   return max_l1;
}

void l1(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_l1 = 0;
   for(int i = 0; i < rows - 2; i++){
      for(int j = 0; j < cols - 1; j++){
	 int product = m[i][j]*m[i+1][j]*m[i+2][j]*m[i+2][j+1];
	 if(product > num_l1){
	    num_l1 = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int l2(int **m, int rows, int cols, int max_l2){
   max_l2 = 0;
   int num_l2 = 0;
   for(int i = 0; i < rows - 2; i++){
      for(int j = cols - 1; j > 0; j--){
	 int product = m[i][j]*m[i+1][j]*m[i+2][j]*m[i+2][j-1];
	 if(product > num_l2){
	    num_l2 = product;
	    max_l2 = num_l2;
	 }
      }
   }

   return max_l2;
}

void l2(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_l2 = 0;
   for(int i = 0; i < rows - 2; i++){
      for(int j = cols - 1; j > 0; j--){
	 int product = m[i][j]*m[i+1][j]*m[i+2][j]*m[i+2][j-1];
	 if(product > num_l2){
	    num_l2 = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int l3(int **m, int rows, int cols, int max_l3){
   max_l3 = 0;
   int num_l3 = 0;
   for(int i = 0; i < rows - 3; i++){
      for(int j = cols - 1; j > 0; j--){
	 int product = m[i][j]*m[i][j-1]*m[i+1][j-1]*m[i+2][j-1];
	 if(product > num_l3){
	    num_l3 = product;
	    max_l3 = num_l3;
	 }
      }
   }

   return max_l3;
}

void l3(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_l3 = 0;
   for(int i = 0; i < rows - 2; i++){
      for(int j = cols - 1; j > 0; j--){
	 int product = m[i][j]*m[i][j-1]*m[i+1][j-1]*m[i+2][j-1];
	 if(product > num_l3){
	    num_l3 = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int l4(int **m, int rows, int cols, int max_l4){
   max_l4 = 0;
   int num_l4 = 0;
   for(int i = rows - 1; i > 2; i--){
      for(int j = cols - 1; j > 0; j--){
	 int product = m[i][j]*m[i-1][j]*m[i-2][j]*m[i-2][j-1];
	 if(product > num_l4){
	    num_l4 = product;
	    max_l4 = num_l4;
	 }
      }
   }

   return max_l4;
}

void l4(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_l4 = 0;
   for(int i = rows - 1; i > 2; i--){
      for(int j = cols - 1; j > 0; j--){
	 int product = m[i][j]*m[i-1][j]*m[i-2][j]*m[i-2][j-1];
	 if(product > num_l4){
	    num_l4 = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int l5(int **m, int rows, int cols, int max_l5){
   max_l5 = 0;
   int num_l5 = 0;
   for(int i = 0; i < rows - 1; i++){
      for(int j = cols - 1; j > 2; j--){
	 int product = m[i][j]*m[i][j-1]*m[i][j-2]*m[i+1][j-2];
	 if(product > num_l5){
	    num_l5 = product;
	    max_l5 = num_l5;
	 }
      }
   }

   return max_l5;
}

void l5(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_l5 = 0;
   for(int i = 0; i < rows - 1; i++){
      for(int j = cols - 1; j > 2; j--){
	 int product = m[i][j]*m[i][j-1]*m[i][j-2]*m[i+1][j-2];
	 if(product > num_l5){
	    num_l5 = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int l6(int **m, int rows, int cols, int max_l6){
   max_l6 = 0;
   int num_l6 = 0;
   for(int i = rows - 1; i > 0; i--){
      for(int j = cols - 1; j > 2; j--){
	 int product = m[i][j]*m[i+1][j]*m[i+1][j+1]*m[i+1][j+2];
	 if(product > num_l6){
	    num_l6 = product;
	    max_l6 = num_l6;
	 }
      }
   }

   return max_l6;
}

void l6(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_l6 = 0;
   for(int i = rows - 1; i > 0; i--){
      for(int j = cols - 1; j > 2; j--){
	 int product = m[i][j]*m[i][j-1]*m[i][j-2]*m[i-1][j-2];
	 if(product > num_l6){
	    num_l6 = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int l7(int **m, int rows, int cols, int max_l7){
   max_l7 = 0;
   int num_l7 = 0;
   for(int i = 0; i < rows - 1; i++){
      for(int j = 0; j < cols - 2; j++){
	 int product = m[i][j]*m[i][j+1]*m[i][j+2]*m[i+1][j+2];
	 if(product > num_l7){
	    num_l7 = product;
	    max_l7 = num_l7;
	 }
      }
   }

   return max_l7;
}

void l7(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_l7 = 0;
   for(int i = 0; i < rows - 1; i++){
      for(int j = 0; j < cols - 2; j++){
	 int product = m[i][j]*m[i][j+1]*m[i][j+2]*m[i+1][j+2];
	 if(product > num_l7){
	    num_l7 = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

int l8(int **m, int rows, int cols, int max_l8){
   max_l8 = 0;
   int num_l8 = 0;
   for(int i = rows; i > 0; i--){
      for(int j = 0; j < cols - 2; j++){
	 int product = m[i][j]*m[i][j+1]*m[i][j+2]*m[i-1][j+2];
	 if(product > num_l8){
	    num_l8 = product;
	    max_l8 = num_l8;
	 }
      }
   }

   return max_l8;
}

void l8(int **m, int rows, int cols, int &row, int &col){
   row = 0;
   col = 0;
   int num_l8 = 0;
   for(int i = rows - 1; i > 0; i--){
      for(int j = 0; j < cols - 2; j++){
	 int product = m[i][j]*m[i][j+1]*m[i][j+2]*m[i-1][j+2];
	 if(product > num_l8){
	    num_l8 = product;
	    row = i;
	    col = j;
	 }
      }
   }

   return;
}

void maxs1(int mldd, int mlud, int mrdd, int mrud, int mrl, int mud, int mbox, int mlzz, int mrzz){
   int **m, rows, cols, max_ldd, max_lud, max_rdd, max_rud, max_rl, max_ud, max_box, max_lzz, max_rzz;

   mldd = ldd(m, rows, cols, max_ldd);
   mlud = lud(m, rows, cols, max_lud);
   mrdd = rdd(m, rows, cols, max_rdd);
   mrud = rud(m, rows, cols, max_rud);
   mrl = rl(m, rows, cols, max_rl);
   mud = ud(m, rows, cols, max_ud);
   mbox = box(m, rows, cols, max_box);
   mlzz = lzz(m, rows, cols, max_lzz);
   mrzz = rzz(m, rows, cols, max_rzz);

   return;
}

void maxs2(int ml1, int ml2, int ml3, int ml4, int ml5, int ml6, int ml7, int ml8){
   int **m, rows, cols, max_l1, max_l2, max_l3, max_l4, max_l5, max_l6, max_l7, max_l8;

   ml1 = l1(m, rows, cols, max_l1);
   ml2 = l2(m, rows, cols, max_l2);
   ml3 = l3(m, rows, cols, max_l3);
   ml4 = l4(m, rows, cols, max_l4);
   ml5 = l5(m, rows, cols, max_l5);
   ml6 = l6(m, rows, cols, max_l6);
   ml7 = l7(m, rows, cols, max_l7);
   ml8 = l8(m, rows, cols, max_l8);

   return;
}

void find_greatest_product1(){
   int mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz, ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8, **m, rows, cols, row, col;

   maxs1(mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz);
   maxs2(ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8);

   if(mldd > mlud && mldd > mrdd && mldd > mrud && mldd > mrl && mldd > mud && mldd > mbox && mldd > mlzz && mldd > mrzz && mldd > ml1 && mldd > ml2 && mldd > ml3 && mldd > ml4 && mldd > ml5 && mldd > ml6 && mldd > ml7 && mldd > ml8){
      ldd(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << mldd << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: Diagonal with a Negative Slope" << endl;
   }

   if(mlud > mldd && mlud > mrdd && mlud > mrud && mlud > mrl && mlud > mud && mlud > mbox && mlud > mlzz && mlud > mrzz && mlud > ml1 && mlud > ml2 && mlud > ml3 && mlud > ml4 && mlud > ml5 && mlud > ml6 && mlud > ml7 && mlud > ml8){
      lud(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << mlud << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: Diagonal with a Positive Slope" << endl;
   }

   return;
}

void find_greatest_product2(){
   int mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz, ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8, **m, rows, cols, row, col;

   maxs1(mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz);
   maxs2(ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8);

   if(mrdd > mlud && mrdd > mldd && mrdd > mrud && mrdd > mrl && mrdd > mud && mrdd > mbox && mrdd > mlzz && mrdd > mrzz && mrdd > ml1 && mrdd > ml2 && mrdd > ml3 && mrdd > ml4 && mrdd > ml5 && mrdd > ml6 && mrdd > ml7 && mrdd > ml8){
      rdd(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << mrdd << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: Diagonal with a Positive Slope" << endl;
   }

   if(mrud > mlud && mrud > mrdd && mrud > mldd && mrud > mrl && mrud > mud && mrud > mbox && mrud > mlzz && mrud > mrzz && mrud > ml1 && mrud > ml2 && mrud > ml3 && mrud > ml4 && mrud > ml5 && mrud > ml6 && mrud > ml7 && mrud > ml8){
      rud(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << mrud << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: Diagonal with a Negative Slope" << endl;
   }

   return;
}

void find_greatest_product3(){
   int mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz, ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8, **m, rows, cols, row, col;

   maxs1(mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz);
   maxs2(ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8);

   if(mrl > mlud && mrl > mrdd && mrl > mrud && mrl > mldd && mrl> mud && mrl > mbox && mrl > mlzz && mrl > mrzz && mrl > ml1 && mrl > ml2 && mrl > ml3 && mrl > ml4 && mrl > ml5 && mrl > ml6 && mrl > ml7 && mrl > ml8){
      rl(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << mrl << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: Left to Right" << endl;
   }

   if(mud > mlud && mud > mrdd && mud > mrud && mud > mrl && mud > mldd && mud > mbox && mud > mlzz && mud > mrzz && mud > ml1 && mud > ml2 && mud > ml3 && mud > ml4 && mud > ml5 && mud > ml6 && mud > ml7 && mud > ml8){
      ud(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << mud << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: Top to Bottom" << endl;
   }

   return;
}

void find_greatest_product4(){
   int mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz, ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8, **m, rows, cols, row, col;

   maxs1(mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz);
   maxs2(ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8);

   if(mbox > mlud && mbox > mrdd && mbox > mrud && mbox > mrl && mbox > mud && mbox > mldd && mbox > mlzz && mbox > mrzz && mbox > ml1 && mbox > ml2 && mbox > ml3 && mbox > ml4 && mbox > ml5 && mbox > ml6 && mbox > ml7 && mbox > ml8){
      box(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << mbox << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: Box" << endl;
   }

   if(mlzz > mlud && mlzz > mrdd && mlzz > mrud && mlzz > mrl && mlzz > mud && mlzz > mbox && mlzz > mldd && mlzz > mrzz && mlzz > ml1 && mlzz > ml2 && mlzz > ml3 && mlzz > ml4 && mlzz > ml5 && mlzz > ml6 && mlzz > ml7 && mlzz > ml8){
      lzz(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << mlzz << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: Zig-Zag Starting from the Top Left" << endl;
   }

   return;
}

void find_greatest_product5(){
   int mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz, ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8, **m, rows, cols, row, col;

   maxs1(mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz);
   maxs2(ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8);

   if(mrzz > mlud && mrzz > mrdd && mrzz > mrud && mrzz > mrl && mrzz > mud && mrzz > mbox && mrzz > mlzz && mrzz > mldd && mrzz > ml1 && mrzz > ml2 && mrzz > ml3 && mrzz > ml4 && mrzz > ml5 && mrzz > ml6 && mrzz > ml7 && mrzz > ml8){
      rzz(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << mrzz << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: Zig-Zag Starting from the Top Right" << endl;
   }

   if(ml1 > mlud && ml1 > mrdd && ml1 > mrud && ml1 > mrl && ml1 > mud && ml1 > mbox && ml1 > mlzz && ml1 > mrzz && ml1 > mldd && ml1 > ml2 && ml1 > ml3 && ml1 > ml4 && ml1 > ml5 && ml1 > ml6 && ml1 > ml7 && ml1 > ml8){
      l1(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << ml1 << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: L-Shape (L)" << endl;
   }

   return;
}

void find_greatest_product6(){
   int mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz, ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8, **m, rows, cols, row, col;

   maxs1(mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz);
   maxs2(ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8);

   if(ml2 > mlud && ml2 > mrdd && ml2 > mrud && ml2 > mrl && ml2 > mud && ml2 > mbox && ml2 > mlzz && ml2 > mrzz && ml2 > ml1 && ml2 > mldd && ml2 > ml3 && ml2 > ml4 && ml2 > ml5 && ml2 > ml6 && ml2 > ml7 && ml2 > ml8){
      l2(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << ml2 << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: L-Shape ( _| )" << endl;
   }

   if(ml3 > mlud && ml3 > mrdd && ml3 > mrud && ml3 > mrl && ml3 > mud && ml3 > mbox && ml3 > mlzz && ml3 > mrzz && ml3 > ml1 && ml3 > ml2 && ml3 > mldd && ml3 > ml4 && ml3 > ml5 && ml3 > ml6 && ml3 > ml7 && ml3 > ml8){
      l3(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << ml3 << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: L-Shape ( |- )" << endl;
   }

   return;
}

void find_greatest_product7(){
   int mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz, ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8, **m, rows, cols, row, col;

   maxs1(mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz);
   maxs2(ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8);
 
   if(ml4 > mlud && ml4 > mrdd && ml4 > mrud && ml4 > mrl && ml4 > mud && ml4 > mbox && ml4 > mlzz && ml4 > mrzz && ml4 > ml1 && ml4 > ml2 && ml4 > ml3 && ml4 > mldd && ml4 > ml5 && ml4 > ml6 && ml4 > ml7 && ml4 > ml8){
      l4(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << ml4 << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: L-Shape ( -| )" << endl;
   }

   if(ml5 > mlud && ml5 > mrdd && ml5 > mrud && ml5 > mrl && ml5 > mud && ml5 > mbox && ml5 > mlzz && ml5 > mrzz && ml5 > ml1 && ml5 > ml2 && ml5 > ml3 && ml5 > ml4 && ml5 > mldd && ml5 > ml6 && ml5 > ml7 && ml5 > ml8){
      l5(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << ml5 << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: L-Shape ( |-- )" << endl;
   }

   return;
}

void find_greatest_product8(){
   int mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz, ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8, **m, rows, cols, row, col;

   maxs1(mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz);
   maxs2(ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8);

   if(ml6 > mlud && ml6 > mrdd && ml6 > mrud && ml6 > mrl && ml6 > mud && ml6 > mbox && ml6 > mlzz && ml6 > mrzz && ml6 > ml1 && ml6 > ml2 && ml6 > ml3 && ml6 > ml4 && ml6 > ml5 && ml6 > mldd && ml6 > ml7 && ml6 > ml8){
      l6(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << ml6 << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: L-Shape ( |__ )" << endl;
   }

   if(ml7 > mlud && ml7 > mrdd && ml7 > mrud && ml7 > mrl && ml7 > mud && ml7 > mbox && ml7 > mlzz && ml7 > mrzz && ml7 > ml1 && ml7 > ml2 && ml7 > ml3 && ml7 > ml4 && ml7 > ml5 && ml7 > ml6 && ml7 > mldd && ml7 > ml8){
      l7(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << ml7 << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: L-Shape ( --| )" << endl;
   }

   return;
}

void find_greatest_product9(){
   int mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz, ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8, **m, rows, cols, row, col;

   maxs1(mldd, mlud, mrdd, mrud, mrl, mud, mbox, mlzz, mrzz);
   maxs2(ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8);

   if(ml8 > mlud && ml8 > mrdd && ml8 > mrud && ml8 > mrl && ml8 > mud && ml8 > mbox && ml8 > mlzz && ml8 > mrzz && ml8 > ml1 && ml8 > ml2 && ml8 > ml3 && ml8 > ml4 && ml8 > ml5 && ml8 > ml6 && ml8 > ml7 && ml8 > mldd){
      l8(m, rows, cols, row, col);
      cout << "Max Product of 4 Adjacent Numbers: " << ml8 << endl;
      cout << "Starting Position: Row " << row << ", Col " << col << endl;
      cout << "Shape: L-Shape ( __| )" << endl;
   }

   return;
}

void find_greatest_product(){
   find_greatest_product1();
   find_greatest_product2();
   find_greatest_product3();
   find_greatest_product4();
   find_greatest_product5();
   find_greatest_product6();
   find_greatest_product7();
   find_greatest_product8();
   find_greatest_product9();

   return;
}

int main(int argc, char *argv[]){

   int rows, cols, **m, x;
   string input;

   if(argc == 1){
      cout << "Enter the number of rows: ";
      cin >> rows;
      if(cin.fail()){
	 cout << "You did not enter a valid input." << endl;
	 exit(0);
      }
      cout << "Enter the number of columns: ";
      cin >> cols;
      if(cin.fail()){
	 cout << "You did not enter a valid input." << endl;
	 exit(0);
      }

      m = create_array1(rows, cols);
      initialize_array1(m, rows, cols);
      print_array(m, rows, cols);
      find_greatest_product();

   }

   if(argc == 2){
      input = "-test";
      if(argv[1] != input){
	 cout << "Invalid command line." << endl;
	 exit(0);
      }

      cin >> rows;
      cin >> cols;

      m = create_array1(rows, cols);
      initialize_array2(m, rows, cols);
      print_array(m, rows, cols);
      find_greatest_product();
      
   }

   if(argc != 1 && argc != 2){
      cout << "Invaild command line." << endl;
      exit(0);
   }

   return 0;
}
