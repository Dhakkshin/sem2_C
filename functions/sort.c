#include <stdio.h>

void sort(int x[], int len);

int main(void)
{
    int num[] = {1, 2, 3, 4};
    sort(num, sizeof(num)/sizeof(int));
}

void sort(int x[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%i\n", x[i]);
    }
}