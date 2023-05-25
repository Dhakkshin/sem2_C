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