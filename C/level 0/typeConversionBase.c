#include <stdio.h>
#include <stdint.h> // For uint64_t and uint8_t
#include <string.h> // For string functions

int main() {
    // Initialization of variables of different types
    int i = 10;
    float f = 23.5;
    double d = 123.456;
    char c = 'A';
    unsigned int ui = 150;
    long l = 1234567890L;
    long long ll = 1234567890123456789LL;
    unsigned char uc = 255;
    short s = 32767;
    unsigned long ul = 123456789UL;
    uint64_t u64 = 1234567890123456789ULL; // 64-bit unsigned integer
    uint8_t u8 = 255; // 8-bit unsigned integer
    char string[] = "Example"; // String
    int array[5] = {1, 2, 3, 4, 5}; // Integer array

    // Examples of implicit conversion
    d = u64;   // uint64_t to double
    f = u8;    // uint8_t to float

    // Examples of explicit casting (type conversion)
    i = (int)u64; // uint64_t to int (data loss may occur)
    c = (char)u8; // uint8_t to char
    u64 = (uint64_t)l; // long to uint64_t
    u8 = (uint8_t)i; // int to uint8_t (data loss may occur)
    ll = (long long)u64; // uint64_t to long long
    ul = (unsigned long)u8; // uint8_t to unsigned long
    u64 = (uint64_t)d; // double to uint64_t (precision loss may occur)
    u8 = (uint8_t)f; // float to uint8_t (precision loss may occur)

    // Manipulating and interpreting string and array
    size_t stringLength = strlen(string); // Get length of the string
    int firstArrayElement = array[0]; // Access first element of the array
    int lastArrayElement = array[sizeof(array)/sizeof(array[0]) - 1]; // Access last element

    // Output results
    printf("uint64_t to double: %f\n", d);
    printf("uint8_t to float: %f\n", f);
    printf("uint64_t to int: %d\n", i);
    printf("uint8_t to char: %c\n", c);
    printf("long to uint64_t: %llu\n", u64);
    printf("int to uint8_t: %u\n", u8);
    printf("double to uint64_t: %llu\n", u64);
    printf("float to uint8_t: %u\n", u8);
    printf("String length: %zu\n", stringLength);
    printf("First and last elements of array: %d, %d\n", firstArrayElement, lastArrayElement);

    return 0;
}
