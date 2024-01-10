// determines the squares of the numbers the user enters and outputs them, except for the numbers 13 and 666.
#include <iostream>

int main() {
    using namespace std; 
    int N, x;

    cin >> N;
    /*
    for (int i=0; i < N; ++i) {
        cout << "enter number:";
        cin >> x;
        if (x == 13 || x == 666)
            continue;
        
        cout << "the square of a number " << x*x << '\n';
    }
    */
    // по закону де Моргана
    for (int i=0; i < N; ++i) {
        cout << "enter number:";
        cin >> x;
        if (x != 13 && x != 666)
           
        cout << "the square of a number " << x*x << '\n';
    }

    return 0;
}