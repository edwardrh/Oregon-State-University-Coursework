#include <iostream>
#include <cmath>

using namespace std;

void rect(float &x, float &width, float &rtotal, int &a, int &b, int &n){

  // rtotal = (pow(x,5)+10)*width;

   for(x=a; x<b; x+=width){
      rtotal += (pow(x,5)+10)*width;
   }
   cout << "(Rectangle Method) The area under the curve calculated recursively is " << rtotal << endl;

   return;
}

void trape(float &x1, float &x2, float &width, float &ttotal, int &a, int &b, int &n){

//   ttotal = (((pow(x1,5)+10)+(pow(x2,5)+10))/2)*width;

   for(x1=a, x2=a+((b-a)/n); x1<=b-((b-a)/n), x2<=b; x1+=width, x2+=width){
      ttotal += (((pow(x1,5)+10)+(pow(x2,5)+10))/2)*width;
   }
   cout << "(Trapezoid Method) The area under the curve calculated recursively is " << ttotal << endl;

   return;
}

int main(){

   int type, a, b, n;
   float width, rec, trap, x, x1, x2, rtotal, ttotal;

   cout << "What method would you like to use? (rectangle - 0, trapezoid - 1): ";
   cin >> type;

   cout << "What is your starting point?: ";
   cin >> a;

   cout << "What is your ending point?: ";
   cin >> b;

   cout << "How many trapezoids/rectangles would you like?: ";
   cin >> n;

   width = (b-a)/n;

   if(type == 0){
      for(x=a; x<b; x+=width){
         rec += (pow(x,5)+10)*width;
      }
      cout << "(Rectangle Method) The area under the curve calculated iteratively is " << rec << endl;

      rect(rtotal, x, width, a, b, n);

   }
   
   if(type == 1){
      for(x1=a, x2=a+((b-a)/n); x1<=b-((b-a)/n), x2<=b; x1+=width, x2+=width){
         trap += (((pow(x1,5)+10)+(pow(x2,5)+10))/2)*width;
      }
      cout << "(Trapezoid Method) The area under the curve calculated iteratively is " << trap << endl;

      trape(x1, x2, width, ttotal, a, b, n);

   }

   return 0;
}
