#include <stdio.h>

int main(void)
{
    int a[3][2] = {}, b[3][2] = {};

    //row major
    printf("Enter the numbers for matrix a:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("After updating:\n");
            for  (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    printf("%i ", a[k][l]);
                }
                printf("\n");
            }
            printf("\n");
            printf("Enter the next number:\n");
            scanf("%i", &a[i][j]);
        }
    }

    printf("\nEnter the numbers for matrix b:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("After updating:\n");
            for  (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    printf("%i ", b[k][l]);
                }
                printf("\n");
            }
            printf("\n");
            printf("Enter the next number:\n");
            scanf("%i", &b[i][j]);
        }
    }

    // //column major
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("Enter a number:\n");
    //         scanf("%i", &b[i][j]);
    //     }
    // }

    //printing
    printf("matrix a:\n");
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sum += a[i][j];
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }
    printf("sum of matrix a:%i\n", sum);
}