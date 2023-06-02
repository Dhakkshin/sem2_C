#include <stdio.h>

void print();
void print1();


int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        print();
    }

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        print1();
    }
}

void print()
{
    int i = 5;
    printf("%i\n", ++i);
}

void print1()
{
    static int i;
    printf("%i\n", ++i);
}