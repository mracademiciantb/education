#include <iostream>
#include <vector>

int main() {
    // Використовуйте один раз typedef для оголошення типу.
    typedef unsigned int STRICTLY_POSITIVE_INTEGER;
    STRICTLY_POSITIVE_INTEGER PosNumber = 4532;

    // Оголошення та ініціалізація вектора
    std::vector<int> MyNumbers = {1, 2, 3};

    // Виведення вектора за допомогою ітератора
    for (std::vector<int>::const_iterator Iterator = MyNumbers.begin(); Iterator < MyNumbers.end(); ++Iterator)
        std::cout << *Iterator << " ";
        
        std::cout << std::endl;

    // Виведення вектора за допомогою auto ітератора
    for (auto Iterator = MyNumbers.begin(); Iterator < MyNumbers.end(); ++Iterator)
        std::cout << *Iterator << " ";

    return 0;
}