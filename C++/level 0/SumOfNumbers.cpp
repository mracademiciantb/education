
#include <iostream>

int get_sum(int a, int b)
{
  int n = (a < b ? b - a : a - b) + 1;
  return n *(a + b)/ 2;
}

int main() {
    std::cout << "get_sum(1, 0) = " << get_sum(1, 0) << std::endl;
    std::cout << "get_sum(1, 2) = " << get_sum(1, 2) << std::endl;
    std::cout << "get_sum(0, 1) = " << get_sum(0, 1) << std::endl;
    std::cout << "get_sum(1, 1) = " << get_sum(1, 1) << std::endl;
    std::cout << "get_sum(-1, 0) = " << get_sum(-1, 0) << std::endl;
    std::cout << "get_sum(-1, 2) = " << get_sum(-1, 2) << std::endl;

    return 0;
}


/*
int get_sum(int a, int b) {

    int sum, large, less = 0;

    if (a > b) {
        large = a;
        less = b;
    } else {
        large = b;
        less = a;
    }

    if (a == b) {
        return a;
    } else {
        for (int i = less; i <= large; i++) {
            sum += i;
        }
        return sum;
    }
}

*/