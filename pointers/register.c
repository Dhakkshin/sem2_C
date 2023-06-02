#include <stdio.h>

void test();

int main(void)
{
    register int i;
    test();
    //printf("%i\n", x); intentional error
}

void test()
{
    int x;
}