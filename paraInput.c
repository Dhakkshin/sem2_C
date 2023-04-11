#include <stdio.h>
//#include <conio.h>
#include <stdbool.h>


int main(void)
{
    int i = 0;
    char c;
    char paragraph[10000];
    while (true)
    {
        c = getch();
        if (c == 13)
        {
            break;
        }
        paragraph[i++] = c;
    }
    printf("%s", paragraph);

    // do
    // {
    //     c = getchar();
    //     putchar(c);
    // }
    // while (c != 13);
}
char *c;
int i = 0;
while ((c[i++] = getchar()) != 13);
printf("%s", c);