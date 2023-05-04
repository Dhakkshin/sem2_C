#include <stdio.h>

int main(void)
{
    int n1 = 1000, n2 = 81, n3 = 20, max;
    max = (n1 > n2 && n1 > n3) ? n1 : (n2 > n1 && n2 > n3) ? n2 : n3;
    //max = (n1 > n2) ? (n1 > n3) ? n1 : n3 : (n2 > n3) ? n2 : n3;
    printf("max is %i\n", max);
}