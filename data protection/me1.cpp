#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    string wordDecod;
    unsigned int in;
    unsigned int lon;

    std::cout << "Please choose ENCODE(1) or DECODE(2): ";
    std::cin >> in;

    if (in == 1) {
        std::cout << "Please enter number: ";
        std::cin >> lon;

        if (lon <= 0 || lon > 26){
            std::cout << "Please enter number 0 ≤ N < 26";
            return 1;
        }

        std::cout << "Please enter word: ";
        cin.ignore();  // clear buffer
        getline(cin, word);

        string rotor1 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        string rotor2 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        string rotor3 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";

        for (char& letter : word) {
            if (isalpha(letter)) {
                letter = rotor1[letter - 'A' + lon];
            }
        }

        for (char& letter : word) {
            if (isalpha(letter)) {
                letter = rotor2[letter - 'A' + lon + 1];
            }
        }

        for (char& letter : word) {
            if (isalpha(letter)) {
                letter = rotor3[letter - 'A' + lon + 1 + 1];
            }
        }
        std::cout << "encoded message: " << word << endl;
        //std::cout << "message: " << word << endl;
    } else if (in == 2) {
        // Code to decode the message
    } else {
        std::cout << "Invalid input";
        return 1;
    }

    

    return 0;
}