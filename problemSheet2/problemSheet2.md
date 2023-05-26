### Dhakkshin S R &nbsp;&nbsp; 22z215 &nbsp;&nbsp; 19z205

# &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Problem Sheet 2

##  Q2
Write a C function named sort that takes a 1D integer array as input and sorts the array elements in
ascending order. The function should modify the original array passed as an argument. Implement the
function and provide a sample usage.
Function Signature:
`void sort(int arr[], int size);`


```c
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
```

## Q3
Write a program in C to perform the following operations on arrays of strings:

- Find the length of the shortest string.
- Find the length of the longest string.
- Calculate the average length of all the strings.
- Count the number of strings with a length greater than a given threshold.
Your program should take an array of strings as input and provide a menu-driven interface to perform
these operations. The program should terminate when the user chooses to exit.
Note:
Assume that the maximum number of strings in the array is 100 and the maximum length of each string
is 100 characters. The length of a string should be calculated excluding the null-terminating character.
You can use the following function signatures as a reference:
int findShortestString(char arr[][100], int n);
int findLongestString(char arr[][100], int n);
float calculateAverageLength(char arr[][100], int n);
int countStringsAboveThreshold(char arr[][100], int n, int threshold);
Provide the necessary user prompts and handle the input/output accordingly. Write the program code
and the necessary functions to implement the above operations.

```c
#include <stdio.h>
#include <string.h>

int findShortestString(char arr[][100], int n);
int findLongestString(char arr[][100], int n);
float calculateAverageLength(char arr[][100], int n);
int countStringsAboveThreshold(char arr[][100], int n, int threshold);

int main(void)
{
    char arr[100][100] = { "hello", "world", "this", "is", "a", "test", "string", "array" };
    printf("Choose one:\n1) Find the length of the shortest string.\n2) Find the length of the longest string.3) Calculate the average length of all the strings.\n4) Count the number of strings with a length greater than a given threshold.\n5) Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("The length of the shortest string is %d.\n", (int)strlen(arr[findShortestString(arr, 100)]));
        break;
    case 2:
        printf("The length of the longest string is %d.\n", (int)strlen(arr[findLongestString(arr, 100)]));
        break;
    case 3:
        printf("The average length of all the strings is %.2f.\n", calculateAverageLength(arr, 100));
        break;
    case 4:
        printf("Enter a threshold: ");
        int threshold;
        scanf("%d", &threshold);
        printf("The number of strings with a length greater than %d is %d.\n", threshold, countStringsAboveThreshold(arr, 100, threshold));
        break;
    case 5:
        return 0;
    default:
        printf("Invalid choice.\n");
        break;
    }
}

int findShortestString(char arr[][100], int n)
{
    int shortest = 101;
    for (int i = 0; i < n; i++)
    {
        if (strlen(arr[i]) < strlen(arr[shortest]))
        {
            shortest = i;
        }
    }
    return strlen(arr[shortest]);
}

int findLongestString(char arr[][100], int n)
{
    int longest = 0;
    for (int i = 0; i < n; i++)
    {
        if (strlen(arr[i]) > strlen(arr[longest]))
        {
            longest = i;
        }
    }
    return strlen(arr[longest]);
}

float calculateAverageLength(char arr[][100], int n)
{
    int totalLength = 0;
    for (int i = 0; i < n; i++)
    {
        totalLength += strlen(arr[i]);
    }
    return (float)totalLength / n;
}

int countStringsAboveThreshold(char arr[][100], int n, int threshold)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (strlen(arr[i]) > threshold)
        {
            count++;
        }
    }
    return count;
}
```