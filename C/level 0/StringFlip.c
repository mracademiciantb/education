#include <stdio.h>
#include <string.h>

// Функція для перевертання рядка
char *strrev(char *string) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(string) - 1; i < j; i++, j--) {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
    return string;
}

// Головна функція
int main() {
    char string[] = "Hello, World!";
    printf("Оригінальний рядок: %s\n", string);
    
    // Викликаємо strrev і виводимо результат
    printf("Перевернутий рядок: %s\n", strrev(string));
    
    return 0;
}