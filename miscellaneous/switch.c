#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int a, b, result;
    char choice;
    bool control = true;
    do
    {
        printf("\nEnter the input in 'Number1 Number2 Choice' format\nChoice can be:\na for add\ns for subtract\nm for multiply\nd for divide\nEnter 1 2 z to exit\n");
        scanf("%i %i %c", &a, &b, &choice);
        fflush(stdin);
        switch (choice)
        {
            case 'a':
            printf("The result is %i\n", a + b);
            break;

            case 's':
            printf("The result is %i\n", a - b);
            break;

            case 'm':
            printf("The result is %i\n", a * b);
            break;

            case 'd':
            printf("The result is %i\n", a / b);
            break;

            case 'z':
            control = false;
            printf("Exiting now.\n");
            break;

            default:
            printf("Invalid input.\n");
        }
    } while (control);
}