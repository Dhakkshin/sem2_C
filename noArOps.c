#include <stdio.h>

int main(void)
{
    char x[100];
    scanf("%[^+-*/%]", x); // will take input only till it sees + or - or * or / or %
    printf("%s\n", x);
}