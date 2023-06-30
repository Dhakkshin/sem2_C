/*Write a function that accepts a two-dimensional array of integers and returns the largest square
submatrix that consists of only 1s.*/

#include <stdio.h>
#include <stdlib.h>

struct sub
{
    int r, c, side;
};

struct sub largestSub(int (*arr)[6], int rows, int coloumns);

int main(void)
{
    int arr[6][6] = {{0, 0, 0, 0, 0, 1}, 
                     {0, 1, 1, 1, 1, 0}, 
                     {1, 1, 1, 1, 1, 1}, 
                     {0, 1, 1, 1, 1, 0}, 
                     {1, 1, 1, 1, 1, 0}, 
                     {0, 0, 0, 1, 1, 1}};

    struct sub final = largestSub(arr, 6, 6);

    printf("Starts at: %i \nEnds at: %i \nSide: %i\nThe largest sub atrix of ones is:\n", final.r, final.c, final.side);
    for (int i = final.r; i < (final.r + final.side); i++)
    {
        for (int j = final.c; j < (final.c + final.side); j++)
        {
            printf("%i ",  arr[i][j]);
        }
        printf("\n");
    }
}

struct sub largestSub(int (*arr)[6], int rows, int coloumns)
{
    struct sub largest;
    largest.side = 0;
    int ones = 1, side = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < coloumns; j++)
        {
            if (arr[i][j] == 1)
            {
                ones = 1;
                
                for (int k = j; k < coloumns; k++)
                {
                    if (arr[i][k] == 0)
                    {
                        side = k - j;
                        break;
                    }
                    if ((k == coloumns - 1) && arr[i][k] == 1)
                    {
                        side = k - j + 1;
                        break;
                    }
                }

                if (side > largest.side)
                {                 
                    for (int z = 0; z < side; z++)
                    {
                        if ((i + z) < rows)
                        {
                            ones = 1;
                            for (int m = i; m <= i + z; m++)
                            {
                                for (int n = j; n <= j + z; n++)
                                {
                                    if (arr[m][n] == 0) ones = 0;
                                }                
                            }
                            if (ones && ((z + 1) > largest.side))
                            {
                                largest.r = i;
                                largest.c = j;
                                largest.side = z + 1;
                            }
                        }
                        
                    }
                }
            }
        }
    }
    // printf("Starts at: %i \nEnds at: %i \nSide: %i\n", largest.r, largest.c, largest.side);
    return largest;
}