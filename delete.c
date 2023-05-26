#include <stdio.h>

void test();

int main()
{
    extern int i;
    test();
    printf("%i\n", i);
    test();
}

int i;

void test()
{
    i++;
    printf("%i\n", i);
}