#include <stdio.h>

int main() {
    // 1. Array initialization
    int array[10]; // Declaring an array of 10 integer elements

    // 2. Array initialization with zeros
    int zeroArray[10] = {0}; // All elements will be initialized to 0

    // 3. Array initialization with specific values
    int initializedArray[5] = {1, 2, 3, 4, 5}; // Initialization with specific values

    // 4. Accessing an array element
    int firstElement = initializedArray[0]; // Accessing the first element of the array

    // 5. Modifying an array element
    initializedArray[2] = 10; // Assigning the value 10 to the third element of the array

    // Operations specific for embedded engineering:

    // 16. Working with bit masks for setting registers
    unsigned int registerValue = 0b10101010;
    unsigned int mask = 0b00000100;
    registerValue |= mask; // Setting a bit

    // 17. Reading a specific bit
    int bitStatus = (registerValue & mask) ? 1 : 0;

    // 18. Clearing a specific bit
    registerValue &= ~mask;

    // 19. Toggling (toggle) a specific bit
    registerValue ^= mask;

    // 20. Bit shifting for multiplying or dividing by powers of two
    int value = 2; // 00000010 in binary
    int multipliedByFour = value << 2; // Shift left by 2 bits (multiplication by 4)
    int dividedByFour = value >> 2; // Shift right by 2 bits (division by 4)

    return 0;
}
