/*
The sine function for the input value x between (0, 1)
*/
#include <stdio.h>
#include <math.h>

int main(void) 
{
    double x;
    printf("Enter the value of x between 0 and 1: ");
    scanf("%lf", &x);

    // Checking if x is in the correct range
    if (x > 0 && x < 1) {
        double sinValue = sin(x);
        printf("The sine of %f is equal to %f\n", x, sinValue);
    } else {
        printf("The value of x is not in the range between 0 and 1\n");
    }

    return 0;
}