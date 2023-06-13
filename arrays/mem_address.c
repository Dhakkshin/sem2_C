#include <stdio.h>

int main(void)
{
    printf("\nLet the base address be b.\nThe 2D array has elements of size n(= 4) bytes and has r(= 4) rows and c(= 5) columns.\nEach element can be accessed by [x][y] where x is the row number and y is the column number.\nEnter the indices in the format [r][c]:");
    int x, y, rLocation, cLocation, n = 4, r = 4, c = 5;
    scanf("[%i][%i]", &x, &y);
    rLocation = (x * c + y) * n;
    cLocation = (y * r + x) * n;
    printf("\nThe memmory address of array[%i][%i] in\nrow major order: b + %i\ncoloumn major order: b + %i\n\n", x, y, rLocation, cLocation);
}