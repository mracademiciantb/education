#include <stdio.h>
#include <math.h>

int main(void)
{
   double x = 0;
   double step = 0.01; // Value increment step 
   
   while(x < 1){
       double sinValue = sin(x);
       printf("Sine table in increments %lf: %lf\n", x, sinValue);
       x += step;
   }
    return 0;
}