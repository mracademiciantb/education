#include <iostream>

// Перерахування для представлення днів тижня
enum DaysOfWeek {
    Sunday = 0,    // Неділя починається з 0
    Monday,        // Понеділок буде мати значення 1
    Tuesday,       // Вівторок буде мати значення 2
    Wednesday,     // Середа буде мати значення 3
    Thursday,      // Четвер буде мати значення 4
    Friday,        // П'ятниця буде мати значення 5
    Saturday       // Субота буде мати значення 6
};

int main() {
    // Ініціалізація змінної today значенням Wednesday
    DaysOfWeek today = Wednesday;

    // Виведення значення today, що представляє день тижня
    std::cout << "Today is day number: " << today << std::endl;

    return 0;
}
