#include<stdio.h>
#define PI 3.14159
int main(void)
{ 
 int radius = 0;
 printf("Enter radius:");
 scanf("%d", &radius);
 float volume = 4*((radius*radius*radius)*PI)/3;
printf("volume is : %f\n\n", volume);
return 0;
}