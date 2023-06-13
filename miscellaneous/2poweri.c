#include <stdio.h>
#include <math.h>

int main(void)
{ 
    int i;
    do 
    {
        printf("Enter a number between 1 and 1000: ");
        scanf("%i", &i);
    }
    while (i < 1 || i > 1000);

    if (i < 32)
    {
        unsigned int a = pow(2, i);
        printf("2 to the power of %i is %u.\nData type used is unsigned int.\nSize of data type used is %li\n", i, a, sizeof(a));
    }
    else if (i > 31 && i < 64)
    {
        unsigned long int a = pow(2, i);
        printf("2 to the power of %i is %lu.\nData type used is unsigned long int.\nSize of data type used is %li\n", i, a, sizeof(a));
    }
    else
    {
        double a = pow(2, i);
        printf("2 to the power of %i is %lf.\nData type used is double.\nSize of data type used is %li\n", i, a, sizeof(a));
    }
}