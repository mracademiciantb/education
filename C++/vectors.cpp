#include <iostream>
// need turn on libraries
#include <vector>

int main() {

  //nubrer vector
  std::vector<double> subway_adult = {800, 1200, 1500};
  // What's the last element?   std::cout << name [2];
  std::cout << subway_adult[0] << "\n";
  
  std::vector<std::string> employees;

employees.push_back("michael");
employees.push_back("jim");
employees.push_back("pam");
employees.push_back("dwight");

//amout
std::cout << "employees.size: " << employees.size();
  


std::vector<int> grades(3);
  
  grades[0] = 90;
  grades[1] = 86;
  grades[2] = 98;

  return 0;
}

/*#include <iostream>
#include <vector>
  
int main() {
  
  std::vector<double> delivery_order;
  
  delivery_order.push_back(8.99);
  delivery_order.push_back(3.75);
  delivery_order.push_back(0.99);
  delivery_order.push_back(5.99);
  
  // Calculate the total using a for loop:
  
  double total = 0.0;
  
  for (int i = 0; i < delivery_order.size(); i++) {

    total = total + delivery_order[i];
  
  }
  
  std::cout << "Total: $" << total << "\n";
    
}*/