#include <stdio.h>

//prototype for getc
// int getc(FILE *stream);

int main(void)
{
    int a;
    a = getc(stdin);
    printf("%i %c\n", a, a);
}
