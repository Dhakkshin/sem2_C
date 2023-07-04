#include <stdio.h>

int main(void)
{
    // writing
    FILE *fptr1 = fopen("test.txt", "w");
    printf("Enter number of lines: ");
    int n;
    scanf("%i", &n);
    getchar();
    char str[100];
    while (n > 0)
    {
        fgets(str, 100, stdin);
        fputs(str, fptr1); 
        n--;
    }
    fclose(fptr1);
    printf("Write Complete\n\n");
    

    // reading
    FILE *fptr2 = fopen("test.txt", "r");
    // fgets reads only till EOL
    //fgets(str, 100, fptr2);

    // char a;
    // do
    // {
    //     a = fgetc(fptr2);
    //     printf("%c", a);
    // } while (a != EOF);

    //int position;
    while (fgets(str, 100, fptr2)) // feof() also works
    {
        //position = ftell(fptr2);
        printf("%s", str);
    }
    fclose(fptr2);
    printf("Read Complete\n");
}