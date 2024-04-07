#include <stdio.h>
#include <stdlib.h>

int main() {
    // Виділення пам'яті
    // Виділення пам'яті для одного елемента
    int *ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Пам'ять не виділена.\n");
        exit(1); // Завершення програми з кодом помилки
    }

    // Виділення пам'яті для масиву елементів
    int n = 5; // Кількість елементів масиву
    int *arr = (int*)calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Пам'ять не виділена.\n");
        free(ptr); // Звільнення пам'яті, виділеної для ptr
        exit(1);
    }

    // Використання виділеної пам'яті
    *ptr = 10; // Присвоєння значення вказівнику
    for (int i = 0; i < n; i++) {
        arr[i] = i * i; // Ініціалізація масиву
    }

    // Вивід значень
    printf("Значення ptr: %d\n", *ptr);
    printf("Значення масиву: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Перевиділення пам'яті (зміна розміру масиву)
    int new_n = 10;
    arr = (int*)realloc(arr, new_n * sizeof(int));
    if (arr == NULL) {
        printf("Пам'ять не перевиділена.\n");
        free(ptr);
        // Не потрібно звільняти arr, оскільки realloc автоматично звільняє стару пам'ять, якщо нова не виділена
        exit(1);
    }

    // Ініціалізація нових елементів
    for (int i = n; i < new_n; i++) {
        arr[i] = i * i;
    }

    // Вивід нових значень масиву
    printf("Нові значення масиву: ");
    for (int i = 0; i < new_n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Звільнення пам'яті
    free(ptr);
    free(arr);

    return 0;
}
