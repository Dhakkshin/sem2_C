/*Write a function that accepts a pointer to a string and removes all the vowels from the string,
modifying it in-place.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void iHateVowels(char * word);

int main(void)
{
    char word[100];
    printf("Enter a word: ");
    fgets(word, 100, stdin);
    iHateVowels(word);
}

void iHateVowels(char * word)
{
    int i = 0;
    while (word[i] != '\0')
    {
        if ((tolower(word[i]) == 'a') || (tolower(word[i]) == 'e') || (tolower(word[i]) == 'i') || (tolower(word[i]) == 'o') || (tolower(word[i]) == 'u'))
        {
            int j = i;
            while (word[j] != '\0')
            {
                word[j] = word[j + 1];
                j++;
            }
        }
        i++;
    }
    printf("%s", word);
}