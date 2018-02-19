/**************************
 ** Program: test.cpp
 ** Author: Rhea Mae Edwards
 ** Date: 1/19/2015
 ** Description:
 ** Input:
 ** Output:
 **************************/

#include <iostream>

using namespace std;

int main(){

	int response;

	cout << "Do you like vi as an editor? (no-0) (yes-1): ";
	cin >> response;

	if(response == 0){
		cout << "You hate vi!" << endl;
	}
	else if(response == 1){
		cout << "You love vi!" << endl;
	}

	return 0;
}
