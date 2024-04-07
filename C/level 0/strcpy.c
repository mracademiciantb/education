#include <stdio.h>
#include <string.h>

int main() {
    char src[50], dest[50];

    // strcpy example
    strcpy(src, "This is source");
    strcpy(dest, "This is destination");
    printf("strcpy example: %s\\n", dest);

    // strncpy example
    strncpy(dest, src, 15);
    printf("strncpy example: %s\\n", dest);

    // strcat example
    strcat(dest, " and concatenated string");
    printf("strcat example: %s\\n", dest);

    // strncat example
    strncat(dest, " with strncat", 5); // Only first 5 characters will be concatenated
    printf("strncat example: %s\\n", dest);

    // strlen example
    printf("strlen example: %lu\\n", strlen(dest));

    // strncmp example
    if(strncmp(src, dest, 5) == 0)
        printf("strncmp example: The first 5 characters of src and dest are the same.\\n");
    else
        printf("strncmp example: The first 5 characters of src and dest are different.\\n");

    return 0;
}