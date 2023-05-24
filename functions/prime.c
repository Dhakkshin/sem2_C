#include <stdio.h>
#include <stdbool.h>

bool isFactor(int n, int x);

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%i", &num);

    for (int i = 2; i < num; i++)
    {
        if (isFactor(num, i))
        {
            printf("%i is not a prime number.\n", num);
            return 0;
        }
    }
    printf("%i is a prime number.\n", num);
    return 0;
}

bool isFactor(int n, int x)
{
    return (n % x == 0);
}