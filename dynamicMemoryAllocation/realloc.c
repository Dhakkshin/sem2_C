//realloc

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(sizeof(int) * 10);

    printf("Before realloc: %p\n", p);

    p = realloc(p, sizeof(int) * 5);

    printf("After realloc: %p\n", p);

    free(p);
}