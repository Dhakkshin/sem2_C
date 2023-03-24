#include <stdio.h>

int main(void)
{
    //initialising the vairables
    int b1, b2, b3, product;

    //getting the 1st number
    printf("Enter thr first number:");
    scanf("%i", &b1);

    //getting the 2nd number
    printf("Enter thr second number:");
    scanf("%i", &b2);

    //getting the 3rd number
    printf("Enter thr thrid number:");
    scanf("%i", &b3);

    //finding product
    product = b1 * b2 *b3;

    //printing the product
    printf("The product of %i, %i and %i is %i.\n", b1, b2, b3, product);
}