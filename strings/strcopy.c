#include <stdio.h>

int main(void)
{
    char a[] = "hello, world";

    char b[100];

    int i = 0;
    int len = sizeof(a)/sizeof(char);
    while(i < len)
    {
        b[i] = a[i];
        i++;
    }

    printf("a: %s\nb: %s\n", a, b);
}