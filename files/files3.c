#include <stdio.h>

int main(void)
{
    FILE *fptr= fopen("files3.txt", "w");
    if (fptr == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int i = 10;
    //char i = 'A';
    fprintf(fptr, "%d", i);
    fclose(fptr);

    FILE *fptr2 = fopen("files3.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    int j;
    fscanf(fptr2, "%d", &j);
    printf("%d\n", j);
    fclose(fptr2);
}