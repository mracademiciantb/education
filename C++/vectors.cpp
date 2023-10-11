#include <iostream>
// need turn on libraries
#include <vector>

int main() {

  //nubrer vector
  std::vector<double> subway_adult = {800, 1200, 1500};
  std::vector<std::string> employees;

employees.push_back("michael");
employees.push_back("jim");
employees.push_back("pam");
employees.push_back("dwight");

//amout
std::cout << "employees.size: " << employees.size();
  
// What's the last element?   std::cout << name [2];
  std::cout << "\n" << subway_adult[0];
  return 0;
}