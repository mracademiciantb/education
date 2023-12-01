#include <iostream>

int main() {
    // Побітове NOT (~)
    unsigned int x = 5;            // 0000 0101 в двійковій системі
    unsigned int notResult = ~x;   // 1111 1010 в двійковій системі
    std::cout << "Pобiтове NOT: " << notResult << std::endl;

    // Побітове AND (&)
    unsigned int a = 12;      // 1100 в двійковій системі
    unsigned int b = 25;      // 11001 в двійковій системі
    unsigned int andResult = a & b; // 1100 в двійковій системі
    std::cout << "Pобiтове AND: " << andResult << std::endl;

    // Побітове OR (|)
    unsigned int orResult = a | b; // 11101 в двійковій системі
    std::cout << "Pобiтове OR: " << orResult << std::endl;

    // Побітове XOR (^)
    unsigned int xorResult = a ^ b; // 11101 в двійковій системі
    std::cout << "Pобiтове XOR: " << xorResult << std::endl;

    return 0;
}
