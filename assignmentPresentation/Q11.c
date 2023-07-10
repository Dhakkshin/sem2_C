/*Write a program in C to sort the lines of a text file in alphabetical order.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char str[100][100], temp[100];
    int i = 0, j = 0, k = 0, n = 0;

    fp = fopen("Q11.txt", "r");

    if (fp == NULL)
    {
        printf("File not found");
        exit(1);
    }

    while (fgets(str[i], 100, fp) != NULL)
    {
        i++;
    }

    n = i;

    for (j = 0; j < n; j++)
    {
        for (k = j + 1; k < n; k++)
        {
            if (strcmp(str[j], str[k]) > 0)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[k]);
                strcpy(str[k], temp);
            }
        }
    }

    printf("\n\nThe content of the file after sorting:\n\n");

    for (i = 0; i < n; i++)
    {
        printf("%s", str[i]);
    }

    fclose(fp);

    return 0;
}