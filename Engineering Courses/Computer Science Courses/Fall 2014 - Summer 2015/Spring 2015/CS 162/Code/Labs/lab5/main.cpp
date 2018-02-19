#include <iostream>
#include "./vehicle.h"
#include "./bike.h"
#include "./skateboard.h"
#include "./car.h"
#include "./motorcycle.h"
#include "./Date.h"

using std::cout;
using std::endl;

int main(){
	int day, month, year;
	
	vehicle v(4);
	bike b(1);
	skateboard s(0);
	motorcycle m(1);
	car c(2);
	Date d;
	
	cout << "Day: ";
	cin >> day;
	d.set_day(day);
	cout << "Month: ";
	cin >> month;
	d.set_month(month);
	cout << "Year: ";
	cin >> year;
	d.set_year(year);
	
	//vehicle *vptr = &b;
	
	int days = d.get_day_of_week();
	cout << days << endl;
	cout << "Seats in vehicle: " << v.get_seats() << endl;
	cout << "Toll for vehicle: " << v.get_toll() << endl;
	cout << "Seats in bike: " << b.get_seats() << endl;
	cout << "Toll for bike: " << b.get_toll() << endl;
	cout << "Seats in skateboard: " << s.get_seats() << endl;
	cout << "Toll for skateboard: " << s.get_toll() << endl;
	cout << "Seats in motorcycle: " << m.get_seats() << endl;
	cout << "Toll for motorcycle: " << m.get_toll(days) << endl;
	cout << "Seats in car: " << c.get_seats() << endl;
	cout << "Toll for car: " << c.get_toll(days) << endl;
	//cout << vptr -> get_seats() << endl;
	//cout << vptr -> get_toll() << endl;
	
	//v_array = new vehicle[];
	
	vehicle *v_array[2]={new bike(1), new car(4)};
	
	cout << v_array[0] -> get_toll() << endl;
	
	return 0;
}