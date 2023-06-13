#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[100];
    printf("Enter a string: ");
    fgets(s, 100, stdin);
    printf("The length of the string is: %lu\n", strlen(s));
}