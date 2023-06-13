#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n;
    do 
    {
        printf("Enter a number greater than 0: ");
        scanf("%i", &n);
    }
    while (n < 1);
    
    int start, stop;
    printf("Enter the start and stop values: ");
    scanf("%i %i", &start, &stop);

    for (int i = 0; i < n; i++) printf("%i ", i % (stop - start + 1) + start);
    printf("\n");
}