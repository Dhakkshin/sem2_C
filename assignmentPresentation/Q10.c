/*Create a function that accepts a pointer to a 2D array of floating-point numbers and calculates
the average value of each column, storing the results in a dynamically allocated 1D array. The
function should return a pointer to the resulting array.*/

#include <stdio.h>
#include <stdlib.h>

float * colAvg(float (*arr)[3], int rows, int coloumns);

int main(void)
{
    float arr[3][3] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}, {7.7, 8.8 ,9.9}};

    float * final = colAvg(arr, 3, 3);
    for (int i = 0; i < 3; i++)
    {
        printf("%f ", final[i]);
    }
    printf("\n");

}

float * colAvg(float (*arr)[3], int rows, int coloumns)
{
    float * cAvg = malloc(coloumns * sizeof(float));
    
    for (int j = 0; j < coloumns; j++)
    {
        cAvg[j] = 0;
        for (int i = 0; i < rows; i++)
        {
            cAvg[j] += arr[i][j];
        }
        cAvg[j] /= rows;
    }
    return cAvg;
}