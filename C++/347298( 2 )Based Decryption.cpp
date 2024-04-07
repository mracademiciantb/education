#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string shiftLetters(const std::string& input, int shift) {
    std::string code = input;

    for (char& ch : code) {
        if (std::isalpha(ch)) {
            char base = std::isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base);
        }
    }

    return code;
}

int findBestShift(const std::string& input) {
    std::vector<int> letterFrequency(26, 0);

    for (char ch : input) {
        if (std::isalpha(ch)) {
            char base = std::isupper(ch) ? 'A' : 'a';
            ++letterFrequency[ch - base];
        }
    }

    int maxFrequencyIndex = std::distance(letterFrequency.begin(), std::max_element(letterFrequency.begin(), letterFrequency.end()));
    int shift = maxFrequencyIndex - ('E' - 'A');

    return shift;
}

int main() {
    using namespace std;

    string encodedMessage;
    getline(cin, encodedMessage);

    int bestShift = findBestShift(encodedMessage);
    string decodedMessage = shiftLetters(encodedMessage, -bestShift);

    cout << decodedMessage << endl;

    return 0;
}
