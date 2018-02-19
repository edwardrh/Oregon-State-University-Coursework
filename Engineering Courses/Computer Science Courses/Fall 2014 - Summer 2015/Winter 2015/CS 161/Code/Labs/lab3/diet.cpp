/*******************************
** Program: diet.cpp
** Author: Rhea Mae Edwards
** Date: 1/19/2015
** Description: 
** Input: 
** Output:
*******************************/

#include <iostream>

using namespace std;

int main(){

	float kill, mouse, dieter, life, death, total, percent;
	int drinks;

	cout << "What is the amount of sweetener needed to kill a mouse?: ";
	cin >> kill;

	cout << "What is the weight of the mouse?: ";
	cin >> mouse;

	cout << "What is the weight of the dieter?: ";
	cin >> dieter;

	cout << "After the dieter stops dieting, how years will they live?: ";
	cin >> life;

	cout << "How many diet sodas does the dieter drinks in a week?: ";
	cin >> drinks;

	percent = 0.001;

	death = dieter/(mouse/kill);

	total = drinks*52*life*percent;

	cout << "The amount of artificial sweetener needed to kill the dieter is " << death << "." << endl;
	cout << "The amount of artificial sweetener consumed by the dieter in their lifetime is " << total << "." << endl;

	cout << "Will the dieter consume enough artificial sweetener to cause death?: ";
	if (death >= total){
		cout << "No." << endl;
	}
	else if (death < total){
		cout << "Yes." << endl;
	}

	return 0;
}
