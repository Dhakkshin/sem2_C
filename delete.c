#include <stdio.h>
#include <math.h>

int main(void)
{
    int *i = malloc(1000);
    i = pow(2, 65);
    printf("%i", *i);
}
