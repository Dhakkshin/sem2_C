#include <stdio.h>

int main(void)
{
    int mat[3][4] = {{1, 2, 3, 4}, 
                    {5, 6, 7, 8}, 
                    {9 ,10, 11, 12}};

    int (*p)[4] = mat;

    for (int i = 0; i < 3; i++)
    {
        printf("%p, %i\n", *(p + i) + 1, *(*(p + i) + 1));
    }
}

