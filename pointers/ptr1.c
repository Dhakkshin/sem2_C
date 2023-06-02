#include <stdio.h>

int main(void)
{
    int x = 4;
    int *ptr = &x;
    printf("%i, %p\n", *ptr, ptr);
    //same as
    // printf("%i, %p\n", x, ptr);
}