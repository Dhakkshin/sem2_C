#include <stdio.h>
#include <stdbool.h>

bool isFactor(int n, int x);
int isPrime(int num);

int main(void)
{
    int num1, num2;
    printf("Enter a range: ");
    scanf("%i %i", &num1, &num2);

    printf("The prime numbers in the range %i to %i are:\n", num1, num2);
    
    for (int i = num1; i <= num2; i++)
    {
        if (isPrime(i))
        {
            printf("%i\n", i);
        }
    }
}

int isPrime(int num)
{
    
    for (int i = 2; i < num; i++)
    {
        if (isFactor(num, i))
        {
            return false;
        }
    }
    return true;
}

bool isFactor(int n, int x)
{
    return (n % x == 0);
}