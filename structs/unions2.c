#include <stdio.h>

union details
{
    int n;
    char arr[4];
};

int main(void)
{
    union details d;
    printf("Enter n:");
    scanf("%i", &d.n);
    printf("%i %i %i %i\n", d.arr[0], d.arr[1], d.arr[2], d.arr[3]);
}