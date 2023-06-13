#include <stdio.h>

int main(void)
{
    char x[100];
    scanf("%[a-zA-Z]", x); //[^a-zA-Z] for no alpha
    printf("%s\n", x);
}