/*solution https://www.codecademy.com/courses/learn-c-plus-plus/lessons/cpp-conditionals-and-logic/exercises/review
(B)*/
// include Bard's recommendation and round to tenths

#include <cmath>
#include <iostream>

int main() {
  // **Enter your weight on Earth**
  float earth_weight;
  std::cout << "Enter your weight on Earth: ";
  std::cin >> earth_weight;

  // **Choose a planet**
  int planet;
  std::cout << "Enter the number of the planet you want to fight on: \n"
            << "1. Mercury\n"
            << "2. Venus\n"
            << "3. Mars\n"
            << "4. Jupiter\n"
            << "5. Saturn\n"
            << "6. Uranus\n"
            << "7. Neptune\n";
  std::cin >> planet;

  // **Calculate weight on other planet**
  const float gravity_coefficients[] = {
      0.38, 0.91, 0.38, 2.34, 1.06, 0.92, 1.19};
  float weight_on_planet = earth_weight * gravity_coefficients[planet - 1];

  // **Output the result**
  std::cout << "Your weight on " << planet << " is " << std::fixed << std::setprecision(2) << weight_on_planet << " kilograms.\n";

  return 0;
}

