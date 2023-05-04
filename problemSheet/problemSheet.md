# Problem Sheet 1

***1.Write a program to find the sum of the digits of a given number using a while loop.***

`#include <stdio.h>

int main(void)
{
    int sum = 0, n = 0;
    printf("Enter a number: ");
    scanf("%i", &n);

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    printf("The sum of the digits is %i\n", sum);
}`

***2. Write a program that takes a character as input and uses the ternary operator to print whether the character is a vowel or a consonant.***

`#include <stdio.h>

int main(void)
{
    char a;
    printf("Enter a character: ");
    scanf("%c", &a);
    printf("%s\n", (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' || a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') ? "vowel" : "consonant");
}`