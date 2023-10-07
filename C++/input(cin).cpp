#include <iostream>

int main() {
  

  /* 2 variables, 
  the first acquires the value entered by the user*/
  double tempf;
  double tempc;
  
  // how to ask a question to a user
  std::cout << "Enter the temperature in Fahrenheit: ";
  std::cin >> tempf;
  
  
  tempc = (tempf - 32) / 1.8;
  
  std::cout << "The temp is " << tempc << " degrees Celsius.\n";
  
return 0;

}