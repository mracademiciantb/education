#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

std::string xorHexStrings(const std::string& str1, const std::string& str2) {
    std::string result;
    for (std::size_t i = 0; i < str1.size(); i += 2) {
        // Convert hexadecimal characters to integers
        std::istringstream iss1(str1.substr(i, 2));
        std::istringstream iss2(str2.substr(i, 2));
        int num1, num2;

        // Error checking: Handle invalid input
        if (!(iss1 >> std::hex >> num1) || !(iss2 >> std::hex >> num2)) {
            std::cerr << "Error converting hexadecimal to integer." << std::endl;
            exit(EXIT_FAILURE);
        }

        // XOR the integers and convert the result back to hexadecimal
        int xorResult = num1 ^ num2;
        std::stringstream ss;
        ss << std::hex << std::setw(2) << std::setfill('0') << xorResult;
        result += ss.str();
    }
    return result;
}

int main() {
    // Input
    std::string message1, message2, message3;
    if (!(std::cin >> message1 >> message2 >> message3)) {
        std::cerr << "Error reading input." << std::endl;
        exit(EXIT_FAILURE);
    }

    // XOR the messages
    std::string xorResult1 = xorHexStrings(message1, message2);
    std::string xorResult2 = xorHexStrings(xorResult1, message3);

    // Output the clear text message
    for (std::size_t i = 0; i < xorResult2.size(); i += 2) {
        // Convert hexadecimal characters to integers and output as ASCII characters
        int num = std::stoi(xorResult2.substr(i, 2), nullptr, 16);
        std::cout << static_cast<char>(num);
    }
    std::cout << std::endl;

    return 0;
}
