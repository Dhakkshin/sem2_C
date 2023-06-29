/*Write a function that accepts a pointer to a 2D array of integers and rotates the array 90 degrees
clockwise in-place.*/

#include <stdio.h>
#include <stdlib.h>

void rotate90(int (*arr)[3], int rows, int coloumns);

int main(void)
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8 ,9}};
    printf("Matrix: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%2i ", arr[i][j]);
        }
        printf("\n");
    }
    rotate90(arr, 3, 3);
}

void rotate90(int (*arr)[3], int rows, int coloumns)
{
    int tmp;
    // int **final = malloc(rows * sizeof(int *));
    // for (int k = 0; k < rows; k++)
    // {
    //     final[k] = malloc(coloumns * sizeof(int));
    // }

    //transposing
    for (int i = 0; i < rows; i++)
    {
        for (int j = i; j < coloumns; j++)
        {
            tmp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = tmp;
        }
    }
    // printf("After transposing: \n");
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("%2i ", arr[i][j]);
    //     }
    //     printf("\n");
    // }
    
    //flipping
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < (coloumns / 2); j++)
        {
            tmp = arr[i][j];
            arr[i][j] = arr[i][coloumns - j - 1];
            arr[i][coloumns - j - 1] = tmp;
        }
    }

    printf("After rotation: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%2i ", arr[i][j]);
        }
        printf("\n");
    }
}