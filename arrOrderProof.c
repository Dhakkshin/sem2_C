#include <stdio.h>

int main(void)
{
    int a[3][2] = {1,2,3,4,5,6}, b[3][2] = {1,4,2,5,3,6}, c[3][2] = {};
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%i %p  ", a[i][j], &a[i][j]);
        }
        printf("\n");
    }
    if (&a[0][1] - &a[0][0] == 1)
    {
        printf("a is in row major order\n");
    }
    else
    {
        printf("a is in coloumn major order\n");
    }

    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%i %p  ", b[i][j], &b[i][j]);
        }
        printf("\n");
    }
    if (&b[1][0] - &b[0][0] == 1)
    {
        printf("b is in row major order\n");
    }
    else
    {
        printf("b is in coloumn major order\n");
    }
    
}