#include <stdio.h>

int main(void)
{
    int sum = 0, n = 0;
    printf("Enter a number: ");
    scanf("%i", &n);

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    printf("The sum of the digits is %i\n", sum);
}