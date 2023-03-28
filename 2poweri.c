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

    long int a = pow(9, i);
    printf("2 to the power of %i is %li,\nsize of data type used is %li\n", i, a, sizeof(a));

}