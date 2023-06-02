#include <stdio.h>

int main(void)
{
    float f = 1.2;
    float *fptr = &f;
    printf("%f, %p\n",f, fptr);
    // also works:
    // printf("%f, %p", *fptr, fptr); -> dereferencing
}