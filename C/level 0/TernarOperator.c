#include <stdio.h>

// Declaration of the paperwork function
int paperwork(int n, int m) {
    return (n < 0 || m < 0) ? 0 : n * m;
}

int main() {
    int n, m;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);
    printf("Enter the number of pages per student: ");
    scanf("%d", &m);

    int total_pages = paperwork(n, m);
    printf("Total number of pages to be filled: %d\n", total_pages);

    return 0;
}