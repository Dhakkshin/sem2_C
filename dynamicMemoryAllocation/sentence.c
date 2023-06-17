#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size = 1;
    char *s = malloc(sizeof(char) * size);
    *(s + size - 1) = getchar();
}