/*Write a recursive function to calculate the power of a given number (x^n), where both x and n are
integers.*/

#include <stdio.h>

int power(int x, int n);

int main(void)
{
    int x, n;
    printf("Enter x,n : ");
    scanf("%i**%i", &x, &n);

    printf("%i**%i = %i\n", x, n, power(x, n));
}

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return x * power(x, n - 1);
    }
}