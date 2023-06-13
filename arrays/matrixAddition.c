#include <stdio.h>

int main(void)
{
    int a[3][2] = {1,2,3,4,5,6}, b[3][2] = {9,8,7,6,5,4}, c[3][2] = {};
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
            printf("%i ", c[i][j]);
        }
        printf("\n");
    }
    
}