/*
int summation(int num) {

  int sum = 0;
  int i = 1;
  for(num; num > 0; i-num){
    sum += num--;
  }
  return sum;
}
is designed to calculate the sum of all integers from 1 to a user-defined number num
*/
#include <stdio.h>

int summation(int num) {
  int sum = 0;
  int i = 1;
  for(num; num > 0; i-num){
    sum += num--;
  }
  return sum;
}

int main() {
    int num = 8; // Out = 36
    int result = summation(num);
    printf("The summation from 1 to %d is: %d\n", num, result);
    return 0;
}
