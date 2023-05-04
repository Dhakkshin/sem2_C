//largest number in a 2d array
#include <stdio.h>

int main(void)
{
    int arr[3][3], a, largest = 0;
    printf("Enter elements for a 3X3 2D array.\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%i", &a);
            arr[i][j] = a;
        }
    }

    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (arr[i][j] > largest) largest = arr[i][j];
   printf("The largest number in the 2d array is %i.\n", largest);
}