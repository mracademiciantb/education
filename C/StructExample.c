#include <stdio.h>
#include <string.h>

// Оголошення структури Book
struct Book {
    char title[100];
    char author[100];
    int year;
};

int main() {
    // Ініціалізація екземпляра структури Book
    struct Book book1;

    // Встановлення даних для book1
    strcpy(book1.title, "The C Programming Language");
    strcpy(book1.author, "Brian W. Kernighan and Dennis M. Ritchie");
    book1.year = 1978;

    // Вивід інформації про книгу
    printf("Книга: %s\n", book1.title);
    printf("Автор: %s\n", book1.author);
    printf("Рік видання: %d\n", book1.year);

    // Створення та ініціалізація екземпляра структури Book в одному рядку
    struct Book book2 = {"1984", "George Orwell", 1949};

    // Вивід інформації про другу книгу
    printf("\nКнига: %s\n", book2.title);
    printf("Автор: %s\n", book2.author);
    printf("Рік видання: %d\n", book2.year);

    return 0;
}
