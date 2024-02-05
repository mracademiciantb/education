#include <iostream>
#include <string>

int main() {
    // 1. Ініціалізація
    std::string str1 = "Hello";
    std::string str2 = "World";

    // 2. Додавання (конкатенація)
    std::string str3 = str1 + ", " + str2 + "!";

    // 3. Знаходження підрядка
    size_t pos = str3.find("World");

    // 4. Вилучення підрядка
    std::string str4 = str3.substr(0, 5);

    // 5. Заміна підрядка
    str3.replace(pos, 5, "C++");

    // 6. Перетворення у верхній регістр
    for (auto &c : str4) c = toupper(c);

    // 7. Вимірювання довжини
    int length = str3.length();

    // 8. Перевірка на порожнечу
    bool isEmpty = str4.empty();

    // 9. Вставка рядка
    str3.insert(6, "Dear ");

    // 10. Видалення символів
    str3.erase(6, 5);

    // Додаткові операції
    // 1. Перетворення числа в рядок
    int num = 123;
    std::string strNum = std::to_string(num);

    // 2. Перетворення рядка в число
    int parsedNum = std::stoi(strNum);

    // 3. Обрізання пробілів (припустимо, що функція trim() вже реалізована)
    // std::string trimmedStr = trim(str5); // Потребує власної реалізації

    // 4. Перевірка на входження символу
    bool containsChar = str3.find('C') != std::string::npos;

    // Вивід для демонстрації
    std::cout << "Конкатенація: " << str3 << std::endl;
    std::cout << "Верхній регістр: " << str4 << std::endl;
    std::cout << "Довжина: " << length << std::endl;
    std::cout << "Число в рядок: " << strNum << std::endl;
    std::cout << "Рядок в число: " << parsedNum << std::endl;
    // std::cout << "Обрізаний рядок: " << trimmedStr << std::endl;
    std::cout << "Містить 'C': " << containsChar << std::endl;

    return 0;
}


///  std::string greet(const std::string& n) {return "Hello, " + n + " how are you doing today?";}