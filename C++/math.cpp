// check Leap year
#include <iostream>

int main() {
  
  short int year;

  std::cout << "Pleas, enter year!\n";
  std::cin >> year;

  if (year > 999){
   
   int res = year % 4;
   if (res == 0){
      std::cout << "Leap year!\n";
   }
    else {
    std::cout << "not Leap year!\n";  
    }
  }
  else {
    std::cout << "Not correct year!\n";
  }
  return 0; 
}

/*std::cout << "Pleas, enter year!\n";
  std::cin >> year;
// Instead of the % operator, you can use the != operator to check for a leap year. This will avoid an unnecessary division operation.
  if (year > 999) {
    if (year % 4 != 0) {
      std::cout << "not Leap year!\n";
    } else {
      std::cout << "Leap year!\n";
    }
  } else {
    std::cout << "Not correct year!\n";
  }*/