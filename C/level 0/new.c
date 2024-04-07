#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "abcabcbb";
    char toFind = 'c';
    char* found = strchr(s, toFind);

    if (found != NULL) {
        printf("Символ c знайдено на позиції: %ld\n", found - s);
    } else {
        printf("Символ '%c' не знайдено в рядку.\n", toFind);
    }

    return 0;
}
