#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Initializing a string
    char greeting[50] = "Hello";
    
    // Finding string length
    int length = strlen(greeting);
    printf("String length: %d\n", length);
    
    // Copying a string
    char copy[50];
    strcpy(copy, greeting);
    printf("String copy: %s\n", copy);
    
    // Concatenating strings
    char name[] = "World";
    strcat(greeting, " ");
    strcat(greeting, name);
    printf("After concatenation: %s\n", greeting);
    
    // Comparing strings
    if (strcmp(greeting, "Hello World") == 0) {
        printf("Strings are equal\n");
    }
    
    // Searching for a character in a string
    if (strchr(greeting, 'W') != NULL) {
        printf("Character 'W' found in the string\n");
    }
    
    // Searching for a substring in a string
    if (strstr(greeting, "World") != NULL) {
        printf("Substring 'World' found\n");
    }
    
    // Splitting a string into tokens
    char str[] = "This is an example of string splitting";
    char *token = strtok(str, " ");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    
    // Formatting a string
    char buffer[50];
    int a = 10;
    float b = 3.14;
    sprintf(buffer, "Integer: %d, Float: %f", a, b);
    printf("%s\n", buffer);
    
    // Converting strings to numbers
    char intStr[] = "123";
    int x = atoi(intStr);
    printf("Integer number: %d\n", x);
    
    char floatStr[] = "3.14";
    float y = atof(floatStr);
    printf("Floating-point number: %f\n", y);
    
    // Limited copy (buffer overflow protection)
    char safeCopy[10];
    strncpy(safeCopy, greeting, sizeof(safeCopy) - 1);
    safeCopy[sizeof(safeCopy) - 1] = '\0'; // Ensuring null-termination
    printf("Limited copy: %s\n", safeCopy);
    
    // Limited concatenation (buffer overflow protection)
    char safeGreeting[20] = "Hello";
    strncat(safeGreeting, " World", sizeof(safeGreeting) - strlen(safeGreeting) - 1);
    printf("Limited concatenation: %s\n", safeGreeting);
    
    // Converting numbers to strings (useful for display or logging)
    char numToStr[20];
    int number = 2024;
    sprintf(numToStr, "%d", number);
    printf("Number to string: %s\n", numToStr);
    
    // Working with fixed-point numbers as strings (useful when floating-point is unavailable)
    int fixedPointValue = 3141; // Represents 3.141
    char fixedStr[20];
    sprintf(fixedStr, "%d.%03d", fixedPointValue / 1000, fixedPointValue % 1000);
    printf("Fixed-point number to string: %s\n", fixedStr);
    
    return 0;
}
