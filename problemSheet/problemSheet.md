### Dhakkshin S R &nbsp;&nbsp; 22z215 &nbsp;&nbsp; 19z205

# &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Problem Sheet 1

***
1.Write a program to find the sum of the digits of a given number using a while loop. 
***
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


***
2. Write a program that takes a character as input and uses the ternary operator to print whether the character is a vowel or a consonant.
***

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


***
3. Write a program that takes an integer as input, which represents a month number (1-12), and uses the switch statement to print the corresponding month name.
***

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

***
4. Write a program to check if it is a palindrome
***

```
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
```

***
5.Write a program using for to print the following pattern.
```
*
* *
* * *
* * * *
* * * * *
```
***

```
//pattern
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            printf("*");
        }
        printf("\n");
    }
}
```

***
6. Write a program that takes a 2D array of integers as input and prints the largest element in the array.
***

```
//largest number in a 2d array
#include <stdio.h>

int main(void)
{
    int arr[3][3], a, largest = 0;
    printf("Enter elements for a 3X3 2D array.\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%i", &a);
            arr[i][j] = a;
        }
    }

    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (arr[i][j] > largest) largest = arr[i][j];
    printf("The largest number in the 2d array is %i.\n", largest);
}
```

***
7. Write a program that takes a 2D array of characters as input and prints each element in the array on a new line.
***

```
//print 2d array
#include <stdio.h>

int main(void)
{
    char arr[3][3], a;
    printf("Enter chars for a 3X3 2D array.\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a = getchar();
            getchar(); // to get rid of the newline character
            arr[i][j] = a;
        }
    }

    printf("The 2D array is:\n");
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) printf("%c\n", arr[i][j]);
}
```

***
8. Write a program that takes an integer as input and uses the printf function to print the integer in hexadecimal format. Use the %x format specifier to print the hexadecimal number.
***

```
//print hex
#include <stdio.h>

int main(void)
{
    int a;
    scanf("%i", &a);
    printf("%x\n", a);
}
```

***
9. Write a program that takes a string and an integer as input and uses the printf function to print them. Use the %s format specifier to print the string and the %5d format specifier to print the integer with a minimum width of 5 characters.
***

```
// %s and %5d

#include <stdio.h>

int main(void)
{
    int n;
    char a[100];
    printf("Enter a string.\n");
    scanf("%s", a);
    printf("Enter a number.\n");
    scanf("%i", &n);
    printf("\n%s\n%5d\n", a, n);
}
```

***
10. Write a program that generates a random number between 1 and 100 and asks the user to guess the number. Use a do-while loop to keep asking the user for guesses until they correctly guess the number.
***

```
//number guess between 1 and 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int n = rand() % 100 + 1, guess;
    do 
    {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        if (guess > n) printf("Too high!\n");
        else if (guess < n) printf("Too low!\n");
        else printf("Correct!\n");
    } 
    while (guess != n);

}
```