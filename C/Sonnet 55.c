/*
Sonnet 55 by William Shakespeare
11.02.2024
In this program, we can see 2 different ways to display text 
*/

#include <stdio.h>

int main(void)
{
    char sentence[256] = "But you shall shine more bright in these contents\nThan unswept stone, besmeared with sluttish time.\n";

    printf("Not marble, nor the gilded monuments \n"
    "Of princes, shall outlive this powerful rhyme;\n");
    printf("%s", sentence);

    return 0;
}