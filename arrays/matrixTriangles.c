#include <stdio.h>

int main(void)
{
    int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    //printing the diagonal
    printf("Diagonal:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("   ");
        }
        printf("%2i ", matrix[i][i]);
        printf("\n");
    }
    printf("\n\n");


    //printing the upper triangle
    printf("Upper triangle:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i <= j)
            {
                printf("%2i ", matrix[i][j]);
            }
            else
            {
                printf("   ");
            }
            
        }
        printf("\n");
    }

    //printing the lower triangle
    printf("\n\nLower triangle:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i >= j)
            {
                printf("%i ", matrix[i][j]);
            }          
        }
        printf("\n");
    }
}