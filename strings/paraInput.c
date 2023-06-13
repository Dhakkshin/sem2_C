#include <stdio.h>

int main(void)
{
    int i = 0;
    char paragraph[5][1000];
    printf("Enter paragraphs:\n(Enter ~ to stop)\n");
    do
    {
        fgets(paragraph[i], 1000, stdin);
    }
    while(paragraph[i++][0] != '~');

    printf("You entered:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%s", paragraph[i]);
    }
}
