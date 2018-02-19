#include <iostream>

using namespace std;

int main() {
	float cereal_weight, lifespan, boxes, metric_weight, ton_boxes, boxes_lifetime;

	cout << "Enter the weight (in ounces) of a box of cereal: ";
	cin >> cereal_weight;

	cout << "Enter your expected lifespan in years: ";
	cin >> lifespan;

	cout << "Enter the number of boxes of cereal you eat in a week: ";
	cin >> boxes;

	metric_weight = cereal_weight/35273.92;

	cout << "The weight of cereal in a box is " << metric_weight << " metric tons." << endl;

	ton_boxes = 35273.92/metric_weight;

	cout << "The number of boxes needed to yield one metric ton is " << ton_boxes << " boxes." << endl;

	boxes_lifetime = boxes*52*lifespan;

	cout << "The number of boxes you'll eat your lifetime will be " << boxes_lifetime << " boxes." << endl;

	return 0;
}
