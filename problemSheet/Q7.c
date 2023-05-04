//print 2d array
#include <stdio.h>

int main(void)
{
    fflush(stdin);
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