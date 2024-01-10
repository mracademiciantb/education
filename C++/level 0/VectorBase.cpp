#include <iostream>
#include <vector>
#include <algorithm> // для std::sort

int main() {
    // Створення векторів
    std::vector<int> vectorA = {3, 1, 4, 1, 5, 9, 2, 6};
    std::vector<int> vectorB = {2, 7, 1, 8, 2, 8, 1, 8};

    // Сортування вектора A
    std::sort(vectorA.begin(), vectorA.end());

    // Виведення вектора A після сортування
    std::cout << "Sorted Vector A: ";
    for (int element : vectorA) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Додавання елементу до вектора B
    int newElement = 42;
    vectorB.push_back(newElement);

    // Виведення вектора B після додавання елементу
    std::cout << "Vector B after adding element: ";
    for (int element : vectorB) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Видалення елементу з вектора A (наприклад, першого елементу)
    vectorA.erase(vectorA.begin());

    // Виведення вектора A після видалення елементу
    std::cout << "Vector A after removing element: ";
    for (int element : vectorA) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Присвоєння значень одного вектора іншому
    vectorA = vectorB;

    // Видалення елемента за індексом (наприклад, елементу з індексом 2)
     vectorA.erase( vectorA.begin() + 2);

    // Видалення елементів у певному діапазоні (наприклад, від другого до четвертого елемента)
     vectorA.erase( vectorA.begin() + 1,  vectorA.begin() + 4);

     // Видалення останнього елемента
    vectorA.pop_back();

    // Виведення вектора A після присвоєння
    std::cout << "Vector A after assignment from B: ";
    for (int element : vectorA) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
