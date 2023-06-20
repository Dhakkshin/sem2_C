#include <stdio.h>

int main(void)
{
    float *a[4];
    float w = 1.1, x = 2.2, y = 3.3, z = 4.4;

    a[0] = &w;
    a[1] = &x;
    a[2] = &y;
    a[3] = &z;

    printf("%f\n", *(*(a + 1)));
}