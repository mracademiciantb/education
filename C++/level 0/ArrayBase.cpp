#include <iostream>
#include <algorithm> // Для std::swap, std::random_shuffle, std::replace
#include <numeric>   // Для std::accumulate
#include <cstdlib>   // Для std::rand і std::srand
#include <ctime>     // Для std::time

// Функція для виведення масиву
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Функція сортування бульбашкою
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функція лінійного пошуку
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Функція бінарного пошуку
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Функція перемішування масиву
void shuffleArray(int arr[], int size) {
    std::srand(std::time(0)); // Ініціалізація генератора випадкових чисел
    for (int i = size - 1; i > 0; i--) {
        int j = std::rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}

// Функція обчислення середнього значення елементів масиву
double averageArray(int arr[], int size) {
    int sum = std::accumulate(arr, arr + size, 0);
    return static_cast<double>(sum) / size;
}

// Функція заміни елементів у масиві
void replaceElements(int arr[], int size, int oldValue, int newValue) {
    std::replace(arr, arr + size, oldValue, newValue);
}

int main() {
    // Створення та ініціалізація масиву
    int array[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    // Демонстрація різних операцій з масивом у логічному порядку
    printArray(array, 10); // Виведення масиву

    shuffleArray(array, 10); // Перемішування
    std::cout << "Перемішаний масив: ";
    printArray(array, 10);

    bubbleSort(array, 10); // Сортування
    std::cout << "Відсортований масив: ";
    printArray(array, 10);

    int key = 5;
    int index = binarySearch(array, 0, 9, key); // Бінарний пошук
    std::cout << "Елемент " << key << " знайдено на позиції (бінарний пошук): " << index << std::endl;

    double average = averageArray(array, 10); // Обчислення середнього значення
    std::cout << "Середнє значення елементів масиву: " << average << std::endl;

    replaceElements(array, 10, 5, 99); // Заміна елементів
    std::cout << "Масив після заміни '5' на '99': ";
    printArray(array, 10);


    return 0;
}
