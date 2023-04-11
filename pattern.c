#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter the number:");
    scanf("%i", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++) printf(" ");
        for (int k = 1; k <= i; k++) printf("%i", k);
        for (int l =i - 1; l > 0; l--) printf("%i", l);
        printf("\n");
    }
}