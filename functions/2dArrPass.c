#include <stdio.h>

void print_arr(int arr[][3], int col_len, int row_len);

int main(void)
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8 ,9}};
    int col_len = sizeof(arr[0])/sizeof(int);
    int row_len = sizeof(arr)/sizeof(arr[0]);
    print_arr(arr, col_len, row_len);
}


void print_arr(int arr[][3], int col_len, int row_len)
{
    for (int i = 0; i < row_len; i++)
    {
        for (int j = 0; j < col_len; j++)
        {
            printf("%i ", arr[i][j]);
        }
        printf("\n");
    }
}