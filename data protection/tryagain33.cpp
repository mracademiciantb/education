#include <iostream>
#include <string>
using namespace std;

string rotor1, rotor2, rotor3;

// Функція для перетворення літери за заданими роторами
char transformLetter(char letter) {
    if (isalpha(letter)) {
        int index = letter - 'A';
        char transformed = rotor3[rotor2[rotor1[index] - 'A'] - 'A'];

        // Після кожного перетворення літери, ротори повинні зрушуватися
        // наступні літери. Це відбувається згідно зі специфікою Енігми.
        rotor1 = rotor1.substr(1) + rotor1[0];
        if (index % 26 == 0) {
            rotor2 = rotor2.substr(1) + rotor2[0];
            if (index % (26 * 26) == 0) {
                rotor3 = rotor3.substr(1) + rotor3[0];
            }
        }

        return transformed;
    }
    return letter; // Якщо символ не є буквою, повертаємо його без змін.
}

// Функція для кодування тексту
void ENCODE(string &text, int N) {
    N %= 26;

    for (char &letter : text) {
        for (int i = 0; i < N; i++) {
            letter = letter + 1;
        }
        letter = transformLetter(letter);
    }
}

// Функція для декодування тексту
void DECODE(string &text, int N) {
    N %= 26;

    for (char &letter : text) {
        letter = transformLetter(letter);
        for (int i = 0; i < N; i++) {
            letter = letter - 1;
        }
    }
}

int main() {
    string command, text;
    int N;

    cin >> command >> N >> rotor1 >> rotor2 >> rotor3 >> text;

    if (command == "ENCODE") {
        ENCODE(text, N);
    } else if (command == "DECODE") {
        DECODE(text, N);
    }

    cout << text << endl;

    return 0;
}
