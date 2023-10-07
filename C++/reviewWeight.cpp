#include <iostream>

int main() {
  // Add variable and user assigns them value 
double weight;

std::cout << "Enter your weight in kg: ";
std::cin >> weight;

//Add new variable to calculation
double marsWeight = weight * 0.3;
std::cout << "Your weight on Mars would be: " << marsWeight << " kg" << std::endl;

/*g++ "name file"  - for compilation
./a.out  - for launch*/

return 0;
}