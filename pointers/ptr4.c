#include <stdio.h>

int main(void)
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10}, sum = 0;

    for (int *ptr = array; (int)ptr < (array + 10*sizeof(int)); ptr++)
    {
        sum += *ptr;
    }
    printf("The sum is: %i\n", sum);
}