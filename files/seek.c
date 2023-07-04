#include <stdio.h>

int main(void)
{
    FILE *fptr2 = fopen("test.txt", "r");
    fseek(fptr2, -20, 2);
    char str[100];
    fgets(str, 100, fptr2);
    printf("%s\n", str);
    fclose(fptr2);
}