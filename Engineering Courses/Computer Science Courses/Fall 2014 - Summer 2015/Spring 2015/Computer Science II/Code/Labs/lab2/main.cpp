#include "./Date.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
   int month, day, year;
   cout<<"Input numeric month: ";
   cin>>month;
   cout<<"Input day: ";
   cin>>day;
   cout<<"Input year: ";
   cin>>year;
   Date x(month, day, year);
   x.format1();
   x.format2();
   x.format3();
   return 0;
}
