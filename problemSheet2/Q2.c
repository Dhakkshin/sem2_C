#include <stdio.h>

void sort(int arr[], int size);

int main(void)
{
    int arr[10] = { 5, 2, 7, 9, 1, 3, 4, 8, 6, 0 };
    sort(arr, 10);
}

void sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) 
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}