/* тернарний оператор утворюється за таким зразком:
условие ? значение_если_истина : значение_если_ложь

*/
#include <iostream>
#include <string>

std::string evenOrOdd(int num) {
    return (num % 2 == 0) ? "Even" : "Odd";
}

int main() {
    int number;
    std::cout << "Введіть число: ";
    std::cin >> number;

    std::string result = evenOrOdd(number);
    std::cout << "Це число є: " << result << std::endl;

    return 0;
}

