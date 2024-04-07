#include <iostream>
#include <map>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <unordered_set>

class MyData {
public:
    double percentage;
    MyData(double p) : percentage(p) {}
};

std::map<char, int> countLetters(const std::string& message, double& totalLetters) {
    std::map<char, int> frequencyMap;
    totalLetters = 0;

    for (char c : message) {
        if (std::isalpha(c)) {
            c = std::toupper(c);
            frequencyMap[c]++;
            totalLetters++;
        }
    }

    return frequencyMap;
}

std::map<char, double> calculatePercentages(const std::map<char, int>& frequencyMap, double totalLetters) {
    std::map<char, double> percentageMap;

    for (const auto& pair : frequencyMap) {
        char letter = pair.first;
        int count = pair.second;
        double percentage = (static_cast<double>(count) / totalLetters) * 100.0;
        percentageMap[letter] = percentage;
    }

    return percentageMap;
}

void replaceWithClosestMatch(std::string& message, const std::map<char, MyData>& data) {
    double totalLetters;
    std::map<char, int> frequencyMap = countLetters(message, totalLetters);
    std::map<char, double> percentageMap = calculatePercentages(frequencyMap, totalLetters);
   std::unordered_set<char> replacedLetters;

    for (size_t i = 0; i < message.size(); ++i) {
        char letter = message[i];
        if (std::isalpha(letter) && replacedLetters.find(letter) == replacedLetters.end()) {
            char originalLetter = std::toupper(letter);
            auto it = data.find(originalLetter);
            if (it != data.end()) {
                double minDiff = std::abs(percentageMap[originalLetter] - it->second.percentage);
                char closestMatch = it->first;

                for (++it; it != data.end(); ++it) {
                    double diff = std::abs(percentageMap[originalLetter] - it->second.percentage);
                    if (diff < minDiff) {
                        minDiff = diff;
                        closestMatch = it->first;
                    }
                }

                // Заміна букви у повідомленні тільки, якщо знаходимо збіг в словнику
                message[i] = isupper(letter) ? std::toupper(closestMatch) : std::tolower(closestMatch);

                // Додавання літери до списку замінених
                replacedLetters.insert(message[i]);
            }
        }
    }
}

int main() {
    using namespace std;

    string message;
    cout << "Введіть повідомлення: ";
    getline(cin, message);

    map<char, MyData> data = {
        {'A', {8.08}},
        {'B', {1.67}},
        {'C', {3.18}},
        {'D', {3.99}},
        {'E', {12.56}},
        {'F', {2.17}},
        {'G', {1.80}},
        {'H', {5.27}},
        {'I', {7.24}},
        {'J', {0.14}},
        {'K', {0.63}},
        {'L', {4.04}},
        {'M', {2.60}},
        {'N', {7.38}},
        {'O', {7.47}},
        {'P', {1.91}},
        {'Q', {0.09}},
        {'R', {6.42}},
        {'S', {6.59}},
        {'T', {9.15}},
        {'U', {2.79}},
        {'V', {1.00}},
        {'W', {1.89}},
        {'X', {0.21}},
        {'Y', {1.65}},
        {'Z', {0.07}}
    };


    replaceWithClosestMatch(message, data);

    cout << "Змінене повідомлення: " << message << endl;

    return 0;
}
