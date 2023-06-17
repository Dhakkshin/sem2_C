//malloc
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(sizeof(int) * 10);

    // for (int i = 0; i < 10; i++)
    // {
    //     *(p + i) = i + 1;
    // }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", *(p + i));
    }

    free(p);
}