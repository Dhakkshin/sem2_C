#include <stdio.h>

int main(void)
{
    long double celsius, fahrenheit;
    printf("Enter the temperature in celsius:");
    scanf("%Lf", &celsius);
    fahrenheit = ((long double)9 / 5) * celsius + 32.0;
    printf("The temperature in fahrenheit is %.80Lf\n", fahrenheit);
    //printf("size of celsius is %li and fahreheit iss %li\n", sizeof(celsius), sizeof(fahrenheit));
}