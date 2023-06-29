/*Write a function that accepts a string and returns the longest palindrome substring in the string.*/

#include <stdio.h>
#include <stdlib.h>

char * subPalindrome(char * word);

int main(void)
{
    //               2     8
    char word[] = "qwracecaracuyi";
    char * final0 = subPalindrome(word);
    printf("%s\n", final0);
}

char * subPalindrome(char * word)
{
    int i = 0, j, start = 0, longest = 0, yes = 1;
    while (word[i] != '\0')
    {
        j = i + 1;
        while (word[j] != '\0')
        {
            if (word[i] == word[j])
            {
                yes = 1;
                for (int k = i; k < (i + ((j - i) / 2)); k++)
                {
                    if (word[k] != word[j - k + i])
                    {
                        yes = 0;
                        break;
                    }
                    
                }
                if (yes == 1 && (j - i + 1) > longest)
                {
                    start = i;
                    longest = j - i + 1;
                }
            }
            j++;
        }
        i++;
    }
    
    char * final = malloc((longest + 1) * sizeof(char));
    for (int i = 0; i < longest; i++)
    {
        final[i] = word[start + i];
    }
    final[longest] = '\0';
    //printf("%i %s\n", longest, final);
    return final;
}