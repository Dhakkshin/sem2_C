#include <stdio.h>

int main(void)
{
    int n1[] = {1,2,3,4};
    int *p1 = n1;
    
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", *p1++);
    }
}