//https://www.hackerrank.com/challenges/printing-pattern-2/problem?isFullScreen=true&h_r=next-challenge&h_v=zen
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void same_num(int a);
void recursion(int n, int z, int control_n);

int main() 
{
    int n;
    scanf("%d", &n);
    int n_copy = n;

    recursion(n, 0, n);
    
    return 0;
}

void recursion(int n, int z, int control_n)
{
    int j;
    for (j = control_n; j > (control_n - z); j--)
    {
        printf("%i ",j);
    }

    same_num(j);

    for (int k = j + 1; k <= control_n; k++)
    {
        printf("%i ",k);
    }
    printf("\n");


    if (n > 1)
    {
        recursion(n - 1, z +1, control_n);
    }


    if (n != 1)
    {
        int j;
        for (j = control_n; j > (control_n - z); j--)
        {
            printf("%i ",j);
        }

        same_num(j);

        for (int k = j + 1; k <= control_n; k++)
        {
            printf("%i ",k);
        }
        printf("\n");
    }
    
}

void same_num(int a)
{
    for (int i = 0; i < (2 * a - 1); i++)
    {
        printf("%i ",a);
    }
}