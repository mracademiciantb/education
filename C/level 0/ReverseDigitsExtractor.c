/*
The program is designed to process numerical data by converting any non-negative number
 into an array of its digits presented in reverse order. 
  It can be used in a variety of areas, including financial data processing, 
  digital signal processing, and cryptography, 
  where individual digits of a number need to be manipulated.

Програма призначена для обробки числових даних шляхом перетворення будь-якого невід'ємного числа 
на масив його цифр, представлених у зворотному порядку. 
  Вона може бути використана в різноманітних сферах, включаючи обробку фінансових даних, 
  цифрову обробку сигналів та криптографію, 
  де необхідно маніпулювати окремими цифрами числа.
*/
#include <stddef.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>

void digitize(uint64_t n, uint8_t digits[], size_t *length_out) {
    // Спочатку перевіримо, чи число нуль, бо тоді потрібно просто повернути масив з одного елемента [0]
    if (n == 0) {
        digits[0] = 0;
        *length_out = 1;
        return;
    }

    size_t length = 0;
    while (n > 0) {
        digits[length] = n % 10; // Отримуємо останню цифру
        n /= 10; // Видаляємо останню цифру з числа
        length++;
    }

    *length_out = length; // Встановлюємо довжину вихідного масиву
}

// Для демонстрації
int main() {
    uint64_t number = 9485945;
    uint8_t digits[20]; // Припускаємо, що число не буде більше 20 цифр
    size_t length_out = 0;

    digitize(number, digits, &length_out);

printf("Prime uint64_t: %llu\n", number);
    printf("Reversed digits: ");
    for (size_t i = 0; i < length_out; i++) {
        printf("%u", digits[i]);
        if (i < length_out - 1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}
