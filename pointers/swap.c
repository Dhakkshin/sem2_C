//swap using ptrs

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int a = 2, b = 5;
    int *aptr = &a, *bptr = &b;
    swap(aptr, bptr);
    printf("%i %i\n", a, b);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}