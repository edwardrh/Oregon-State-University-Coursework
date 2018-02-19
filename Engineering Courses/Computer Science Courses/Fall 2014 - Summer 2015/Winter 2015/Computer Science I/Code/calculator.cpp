#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int x = 0;

	while(x == 0) {

		char operation;
		int num1;
		int num2;

		cout << "Enter a number operation (+, -, /, *, ^, %): ";
		cin >> operation;

		cout << "Enter your first number: ";
		cin >> num1;

		cout << "Enter your second number: ";
		cin >> num2;

		if(operation == '+') {
			cout << num1 + num2 << endl;
		}

		else if(operation == '-') {
			cout << num1 - num2 << endl;
		}

		else if(operation == '/') {
			cout << num1 / num2 << endl;
		}

		else if(operation == '*') {
			cout << num1 * num2 << endl;
		}

		else if(operation == '^') {
			cout << pow(num1, num2) << endl;
		}

		else if(operation == '%') {
			cout << num1 % num2 << endl;
		}

		int again;

		cout << "Do you want to play again? (0-no, 1-yes): ";
		cin >> again;

		if(again == 0) {
			break;
		}

		else if(again == 1) {
			
		}
	}

	return 0;
}
