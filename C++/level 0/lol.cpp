#include <iostream>

#define our_super_type float // we can change this type and change the body(швидко міняти тип у всій програмі)
using namespace std;

int main() {

system("clear");

int num = 5;
int& refNum = num;  // оголошуємо посилання refNum, яке посилається на num 

our_super_type firsNumber{}; // define #define our_super_type !!!int/float....!!! 
our_super_type secondNumber{};
our_super_type result{};

char symbol;

char tryAgain = 'n';

do {
cout << "Enter first number: "; 
cin >> firsNumber;
cout << "Enter symbol. Available operation (+,-,*,/)"; 
cin >> symbol;
cout << "Enter second number: "; 
cin >> secondNumber;

if (symbol == '+') {
result = firsNumber + secondNumber;
} else if (symbol == '-') {
result = firsNumber - secondNumber;
} else if (symbol == '*' ) {
result = firsNumber * secondNumber;
} else if (symbol == '/') {
result = firsNumber / secondNumber;
} else {
cout << "You enter wrong symbol. Available symbols (+,~,*,/)";
}
cout.precision(12); // cout.precision(prec:12); точність float

cout << "Result: "<< result << endl; 
cout << "Do you want try again? (y/n)"; 
cin >> tryAgain;
} while (tryAgain == 'y');
/*
цикл do{}while(); буде виконуватись і в кінці перевіряти умову, і можливо повторно виконуватись
*/
return 0;
}