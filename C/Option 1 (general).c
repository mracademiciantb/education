#include <stdio.h>

typedef enum month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
typedef struct date { month m; int d; } date;

// Function for determining the next day
date nextday(date current) {
    switch (current.m) {
        case feb:
            if (current.d == 28) {
                current.m = mar; // Transition to the next month
                current.d = 1;
            } else {
                current.d++;
            }
            break;
        case apr: case jun: case sep: case nov:
            if (current.d == 30) {
                current.m += 1; // Transition to the next month
                current.d = 1;
            } else {
                current.d++;
            }
            break;
        case jan: case mar: case may: case jul: case aug: case oct:
            if (current.d == 31) {
                current.m += 1; // Transition to the next month
                current.d = 1;
            } else {
                current.d++;
            }
            break;
        case dec:
            if (current.d == 31) {
                current.m = jan; // New Year
                current.d = 1;
            } else {
                current.d++;
            }
            break;
    }
    return current;
}

// Function for printing the date
void printdate(date d) {
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("%d %s\n", d.d, months[d.m]);
}

int main() {
    date dates[] = {{jan, 1}, {feb, 28}, {mar, 14}, {oct, 31}, {dec, 31}};
    for (int i = 0; i < sizeof(dates)/sizeof(dates[0]); i++) {
        printdate(dates[i]);
        date next = nextday(dates[i]);
        printdate(next);
        printf("\n");
    }
    return 0;
}
