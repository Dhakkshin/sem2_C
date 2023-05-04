//palindrome
#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[1000], palindrome = 't', a, b;
    scanf("%s", word);

    int len = strlen(word), i;

    i = 0;
    len--;
    while (i <= len)
    {
        if (word[i] != word[len])
        {
            palindrome = 'f';
        }
        i++;
        len--;
    }
    (palindrome == 't') ? printf("It is a palindrome.\n") : printf("It is not a palindrome.\n");
}