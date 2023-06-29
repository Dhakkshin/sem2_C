/*Implement a function that accepts a string and returns a dynamically allocated array of characters
containing the unique characters in the string, sorted in ascending order.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* unique(char *word);
char * sort(char * unique);

int main(void)
{
    char word[100], *uniqueSorted;
    printf("Enter a word: ");
    fgets(word, 100, stdin);

    uniqueSorted = sort(unique(word));
    printf("%s\n", uniqueSorted);
}

char* unique(char *word)
{
    char *tmp;
    char *unique = malloc(sizeof(char));
    unique[0] = word[0];
    int i = 0, j, len = 1;
    while (word[i] != '\0')
    {
        j = 0;
        int new = 1;
        while (unique[j] != '\0')
        {
            if (word[i] == unique[j]) 
            {
                new = 0;
            }
            j++;
        }
        if (new == 1)
        {
            len++;
            tmp = realloc(unique, len * sizeof(char));
            if (tmp == NULL)
            {
                printf("Error reallocating memory.\n");
                exit(1);
            }
            unique = tmp;
            unique[len - 1] = word[i];
        }
        i++;
    }
    tmp = realloc(unique, (len + 1) * sizeof(char));
    if (tmp == NULL)
    {
        printf("Error reallocating memory.\n");
        exit(1);
    }
    unique = tmp;
    unique[len] = '\0';
    return unique;
}

char * sort(char* uniqueSorted)
{
    char tmp;
    int len = strlen(uniqueSorted);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 2; j++)
        {
            if (uniqueSorted[j] > uniqueSorted[j + 1])
            {
                tmp = uniqueSorted[j];
                uniqueSorted[j] = uniqueSorted[j + 1];
                uniqueSorted[j + 1] = tmp;
            }
        }
    }
    return uniqueSorted;    
}