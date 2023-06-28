#include <stdio.h>

struct point
{
    int x, y;
};

int main(void)
{
    struct point p;// = {1, 2};

    struct point *p1 = &p;

    scanf("%i", &(p1 -> x));

    printf("%i", (p1 -> x));
}