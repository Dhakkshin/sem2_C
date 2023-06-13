#include <stdio.h>

//prototype for fgets
// char *fgets(char *str, int n, FILE *stream);
// char *gets(char *str); -> not working

int main(void)
{
    char c[10];
    fgets(c, 100, stdin);
    printf("%s", c);
}