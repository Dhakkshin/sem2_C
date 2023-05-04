### Dhakkshin S R &nbsp;&nbsp; 22z215

# &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Problem Sheet 1

***1.Write a program to find the sum of the digits of a given number using a while loop.***

```
#include <stdio.h>

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
}
```


***2. Write a program that takes a character as input and uses the ternary operator to print whether the character is a vowel or a consonant.***

```
#include <stdio.h>

int main(void)
{
    char a;
    printf("Enter a character: ");
    scanf("%c", &a);
    printf("%s\n", (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' || a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') ? "vowel" : "consonant");
}
```


***3. Write a program that takes an integer as input, which represents a month number (1-12), and uses the switch statement to print the corresponding month name.***

```
#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter a number from 1 to 12: ");
    scanf("%i", &n);
    
    switch (n)
    {
        case 1:
        printf("January\n");
        break;

        case 2:
        printf("February\n");
        break;

        case 3:
        printf("March\n");
        break;

        case 4:
        printf("April\n");
        break;

        case 5:
        printf("May\n");
        break;

        case 6:
        printf("June\n");
        break;

        case 7:
        printf("July\n");
        break;

        case 8:
        printf("August\n");
        break;

        case 9:
        printf("September\n");
        break;

        case 10:
        printf("October\n");
        break;

        case 11:
        printf("November\n");
        break;

        case 12:
        printf("December\n");
        break;

        default:
        printf("Invalid input\n"); 
    }
}
```

***4. Write a program to check if it is a palindrome***

```//palindrome
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
```

***5.Write a program using for to print the following pattern.
*
* *
* * *
* * * *
* * * * * ***
