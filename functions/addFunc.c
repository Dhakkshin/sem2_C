#include <stdio.h>

void add(int p[]);

int main(void)
{
    int a[] = {1,2,3,4,5,6,7,8,9,0};
    
    add(a);

    printf("Inside main function:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%i ",*(a + i));
    }
    printf("\n");
}

// void add(int *a)
// {
//     for (int i = 0; i < 10; i++)
//     {
//         *(a + i) += 1;
//     }
    
//     printf("Inside add function:\n");
//     for (int i = 0; i < 10; i++)
//     {
//         printf("%i ",*(a + i));
//     }
//     printf("\n");
// }

void add(int p[])
{
    for (int i = 0; i < 10; i++)
    {
        p[i] += 1;
    }

    printf("Inside add function:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%i ",p[i]);
    }
    printf("\n");
}