/*Write a function that accepts a two-dimensional array of integers and returns the transpose of the
array (rows become columns and vice versa).*/

#include <stdio.h>
#include <stdlib.h>

int ** transpose(int (*arr)[3], int rows, int coloumns);

int main(void)
{
    int arr[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8 ,9}, {10, 11 ,12}};
    printf("Matrix: \n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%2i ", arr[i][j]);
        }
        printf("\n");
    }
    int ** final0 = transpose(arr, 4, 3); 
    printf("Transpose: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%i ", final0[i][j]);
        }
        printf("\n");
    }
}

int ** transpose(int (*arr)[3], int rows, int coloumns)
{
    int tmp;
    int **final = malloc(rows * sizeof(int *));
    for (int k = 0; k < rows; k++)
    {
        final[k] = malloc(coloumns * sizeof(int));
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < coloumns; j++)
        {
            //printf("%i %i\n", i, j);
            //printf("%i ", arr[i][j]);
            final[j][i] = arr[i][j];
            final[i][j] = arr[j][i];
        }
        //printf("\n");
    }
    return final;
}