//array of pointers
#include <stdio.h>

int main(void)
{
    int *a[4];
    int w = 1, x = 2, y = 3, z = 4;

    a[0] = &w;
    a[1] = &x;
    a[2] = &y;
    a[3] = &z;
    
    for (int i = 0; i < 4; i++)
    {
        printf("%p, %i\n", a[i], *a[i]);
    }
}