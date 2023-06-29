/*Create a function that accepts two dynamically allocated arrays of integers and merges them into
a new sorted array. The function should return a pointer to the merged array, and it should handle
the deallocation of the input arrays.*/

#include <stdio.h>
#include <stdlib.h>

int * merge(int arr1Len, int arr2Len);

int main(void)
{
    int arr1Len, arr2Len;
    printf("Enter size of array 1 (1 <): ");
    scanf("%i", &arr1Len);
    getchar();
    
    printf("Enter size of array 2 (1 <): ");
    scanf("%i", &arr2Len);
    getchar();

    int * mergedSorted = merge(arr1Len, arr2Len);
    
    printf("After merging and sorting: \n");
    for (int i = 0; i < arr1Len + arr2Len; i++)
    {
        printf("%i ", mergedSorted[i]);
    }
    printf("\n");
    free(mergedSorted);
}

int * merge(int arr1Len, int arr2Len)
{
    int *arr1, *arr2;

    arr1 = malloc(arr1Len * sizeof(int));
    if (arr1 == NULL)
    {
        printf("Error reallocating memory.\n");
        exit(1);
    }

    printf("Enter the elements for array 1 one by one: \n");    
    for (int i = 0; i < arr1Len; i++)
    {
        scanf("%i", arr1 + i);
        getchar();
    }


    arr2 = malloc(arr2Len * sizeof(int));
    if (arr2 == NULL)
    {
        printf("Error reallocating memory.\n");
        exit(1);
    }

    printf("Enter the elements for array 2 one by one: \n");    
    for (int i = 0; i < arr2Len; i++)
    {
        scanf("%i", arr2 + i);
        getchar();
    }




    int * merged = malloc((arr1Len + arr2Len) * sizeof(int));
    for (int i = 0; i < arr1Len; i++)
    {
        merged[i] = arr1[i];
    }
    for (int i = arr1Len; i < arr1Len + arr2Len; i++)
    {
        merged[i] = arr2[i - arr1Len];
    }

    free(arr1);
    free(arr2);

    int temp;
    int len = arr1Len + arr2Len;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (merged[j] > merged[j + 1])
            {
                temp = merged[j];
                merged[j] = merged[j + 1];
                merged[j + 1] = temp;
            }
        }
    }

    return merged;
}