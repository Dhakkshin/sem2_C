#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
    printf("Enter a sentence:\n");

    int size = 1, words = 0;
    char *s = malloc(sizeof(char));
    do
    {
        *(s + size - 1) = getch();
        if (*(s + size - 1) == ' ')
        {
            words += 1;
        }
        size += 1;
        s = realloc(s, sizeof(char) * size);
    }
    while (*(s + size - 2) != '.');

    *(s + size - 1) = '\0';

    printf("\nEnterned sentence is:\n%s\nIt has %i words", s, words + 1);

    free(s);
}