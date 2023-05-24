#include <stdio.h>

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%i", &num);

    printf("%i! = %i\n", num, factorial(num));
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}