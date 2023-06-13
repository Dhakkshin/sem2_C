#include <stdio.h>

//multiples
int main(void)
{
    int base,numberOfMultiples;
    printf("Enter the base number followed by the number of multiples you want to see:");
    scanf("%i %i", &base, &numberOfMultiples);
    for (int i = 1; i <= numberOfMultiples; i++)
    {
        //printf("%i's table till %i:\n",i, numberOfMultiples);
        for (int j = 1; j <= base; j++)
        {
            printf("%i * %i = %i\t",j, i, i * j);
        }
        printf("\n");   
    }
}