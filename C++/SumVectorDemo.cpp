#include <iostream>
#include <vector>

void sum(int* p, int n, const std::vector<int>& d) {
    *p = 0;
    for(int i = 0; i < n; ++i) {
        *p = *p + d[i];
    }
}

void printResult(int result) {
    std::cout << "The sum is " << result << std::endl;
}

int main() {
    constexpr int N = 40; // Use constexpr instead of a global variable
    auto accum = 0; // Use auto for automatic type deduction
    std::vector<int> data(N);

    for(auto i = 0; i < N; ++i) { // Use auto for the loop iterator
        data[i] = i;
    }

    sum(&accum, N, data);

    printResult(accum);

    return 0;
}
