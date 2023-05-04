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