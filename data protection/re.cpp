#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    string wordDecod;
    unsigned int choice;
    unsigned int shift;

    std::cout << "Please choose ENCODE(1) or DECODE(2): ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Please enter number: ";
        std::cin >> shift;

        if (shift <= 0 || shift > 26){
            std::cout << "Please enter number 0 ≤ N < 26";
            return 1;
        }

        std::cout << "Please enter word: ";
        cin.ignore();  // clear buffer
        getline(cin, word);

        string rotor0 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        string rotor1 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        string rotor2 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";

        for (char& letter : word) {
            if (isalpha(letter)) {
                letter = rotor0[letter - 'A' + shift];
            }
        }

        for (char& letter : word) {
            if (isalpha(letter)) {
                letter = rotor1[letter - 'A' + shift + 1];
            }
        }

        for (char& letter : word) {
            if (isalpha(letter)) {
                letter = rotor2[letter - 'A' + shift + 1 + 1];
            }
        }
        std::cout << "encoded message: " << word << endl;
        //std::cout << "message: " << word << endl;
    } else if (choice == 2) {
        // Code to decode the message
    } else {
        std::cout << "Invalid input";
        return 1;
    }

    

    return 0;
}