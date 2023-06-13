#include <stdio.h>

int main(void)
{
    int matrix[5][4];
    int ones[1000][4];
    int sum = 0, count = 0, m = 5, n = 4;

    // adding all sub matrix of only ones to ones matrix
    // ones[][0] -> row index of 1st element of sub matix
    // ones[][1] -> col index of 1st element of sub matix
    // ones[][2] -> row lenght of sub matix
    // ones[][3] -> row lenght of sub matix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int x = i; x < m; x++)
            {
                for (int y = j; y < n ; y++)
                {
                    for (int row = i; row < x; row++)
                    {
                        for (int col = i; col < y; col++)
                        {
                            sum += matrix[row][col];
                        }
                    }

                    if (sum == ((x - i + 1) * (y - j + 1)))
                    {
                        ones[count][0] = i;
                        ones[count][1] = j;
                        ones[count][2] = x - i + 1;
                        ones[count][3] = y - j + 1;
                        count++;
                    }
                    sum = 0;
                }
            }
        }
    }

    //filtering smaller subs
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (ones[i][2] * ones[i][3] > ones[j][2] * ones[j][3])
            {
                int temp[4];
                for (int k = 0; k < 4; k++)
                {
                    temp[k] = ones[i][k];
                    ones[i][k] = ones[j][k];
                    ones[j][k] = temp[k];
                }
            }
        }

}