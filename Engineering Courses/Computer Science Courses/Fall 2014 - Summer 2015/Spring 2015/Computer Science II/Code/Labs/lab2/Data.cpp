#include <iostream>
#include "./Date.h"

using std::cout;
using std::cin;
using std::endl;

Date::Date(){
   month = 1;
   day = 1;
   year = 2001;
}

Date::Date(const int i, const int j, const int k){
   month = i;
   day = j;
   year = k;
}

void Date::print_month() const{
   if(month==1)
      cout<<"January";
   if(month==2)
      cout<<"February";
   if(month==3)
      cout<<"March";
   if(month==4)
      cout<<"April";
   if(month==5)
      cout<<"May";
   if(month==6)
      cout<<"June";
   if(month==7)
      cout<<"July";
   if(month==8)
      cout<<"August";
   if(month==9)
      cout<<"September";
   if(month==10)
      cout<<"October";
   if(month==11)
      cout<<"November";
   if(month==12)
      cout<<"December";
}

bool Date::check_date(int month, int day) const{
   if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
      if(day<=31)
	 return 1;
      else
	 return 0;}
   if(month==4||month==6||month==9||month==11){
      if(day<=30)
	 return 1;
      else
	 return 0;}
   if(month==2){
      if(day<=28)
	 return 1;
      else
	 return 0;}
}

void Date::format1() const{
   cout<<month<<"/"<<day<<"/"<<year-2000<<endl;
}

void Date::format2() const{
   print_month();
   cout<<" "<<day<<", "<<year<<endl;
}

void Date::format3() const{
   cout<<day<<" ";
   print_month();
   cout<<" "<<year<<endl;
}
