#include <iostream>
#include <cmath>

#define WATER_WEIGHT 62.4 //Defines the specific weight of water
#define PI 3.14

using namespace std;

int main() {
   //Variables needed to calculate buoyancy
   float weight, radius, b_force, volume;

   //Prompt user for weight and radius of sphere
   cout << "Please enter the weight (lbs): ";
   cin >> weight;

   cout << "Please eneter the radius: ";
   cin >> radius;

   //Calculate the colume and buoyancy force
   volume = 4/3 * PI * pow(radius, 3);
   b_force = volume * WATER_WEIGHT;

   //Determine if the sphere will sink or float
   if(b_force >= weight) {
      cout << "The sphere will float!\n";
   }
   else {
      cout << "The sphere will sink!\n";
   }
   return 0;
}
