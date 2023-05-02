#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int a, b, result;
    char choice;
    bool control = true;
    do
    {
        printf("\nEnter the input in 'Number1 Number2 Choice' format\nChoice can be:\na for add\ns for subtract\nm for multiply\nd for divide\nEnter 1 2 Z to exit\n");
        scanf("%i %i %c", &a, &b, &choice);
        switch (choice)
        {
            case 'a':
            result = a + b;
            break;

            case 's':
            result = a - b;
            break;

            case 'm':
            result = a * b;
            break;

            case 'd':
            result = a / b;
            break;

            case 'z':
            control = false;

            default:
            printf("Invalid input.");
        }
        printf("The result is %i\n", result);
    } while (control);
}