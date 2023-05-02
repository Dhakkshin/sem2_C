#include <stdio.h>
#define lenght 6

int main(void)
{
    int arr[lenght] = {1, 2, 3, 4, 5, 6};
    int temp;
    for (int i = 0; i < lenght; i+=2)
    {
        if (i+1 == lenght)
        {
            break;
        }
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }

    for (int i = 0; i < lenght; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");

}