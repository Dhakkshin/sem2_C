// nth fibonacci number
#include <stdio.h>

int fibo(int n);

int main(void)
{
    printf("Enter a number: ");
    int num;
    scanf("%i", &num);

    printf("The %ith fibonacci number is %i.\n", num, fibo(num));
}

int fibo(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n < 4)
    {
        return 1;
    }
    return fibo(n - 1) + fibo (n - 2);
}