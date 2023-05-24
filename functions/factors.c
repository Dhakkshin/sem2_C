#include <stdio.h>
#include <stdbool.h>

bool isFactor(int n, int x);

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%i", &num);

    printf("The factors of %i are:\n", num);
    for (int i = 1; i <= num; i++)
    {
        if (isFactor(num, i))
        {
            printf("%i\n", i);
        }
    }
}

bool isFactor(int n, int x)
{
    return (n % x == 0);
}