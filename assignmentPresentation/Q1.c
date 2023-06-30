/*Write a recursive function to calculate the power of a given number (x^n), where both x and n are
integers.*/

#include <stdio.h>

float power(int x, int n);

int main(void)
{
    int x, n;
    printf("Enter x,n : ");
    scanf("%i^%i", &x, &n);

    printf("%i^%i = %f\n", x, n, power(x, n));
}

float power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if ( n < 0)
    {
        return 1 / power(x, -n);
    }
    else
    {
        return x * power(x, n - 1);
    }
}