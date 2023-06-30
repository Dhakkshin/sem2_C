/*Implement a recursive function to solve the Tower of Hanoi problem with n disks, given three
towers.*/

#include <stdio.h>
#include <stdlib.h>

void ToH(int disks, int *source, int *auxiliary, int *destination);
void move(int *source, int *destination);
void printRods(int *source, int *auxiliary, int *destination);

int main(void)
{
    int num;
    printf("Enter the number of disks: ");
    scanf("%i", &num);

    int *a = malloc((num + 1) * sizeof(int));
    int *b = malloc((num + 1) * sizeof(int));
    int *c = malloc((num + 1) * sizeof(int));

    a[0] = num;
    b[0] = 0;
    c[0] = 0; // store the size of the tower dynamically
    for (int i = num, j = 1; i > 0; i--, j++) a[j] = i;
    //for (int i = 0; i < num + 1; i++) printf("%i ", a[i]);
    ToH(num, a, b, c);
    
}

void ToH(int disks, int *source, int *auxiliary, int *destination)
{
    printRods(source, auxiliary, destination);
    if (disks == 1)
    {
        // s to d
        move(source, destination);
        printRods(source, auxiliary, destination);
    }
    else
    {
        ToH(disks - 1, source, destination, auxiliary);
        // s to d
        move(source, destination);
        printRods(source, auxiliary, destination);
        ToH(disks - 1, auxiliary, source, destination);
    }

    //printRods(source, auxiliary, destination);
}

void move(int *source, int *destination)
{
    int tmp = source[source[0]];
    source[0]--;
    destination[0]++;
    destination[destination[0]] = tmp;
}

void printRods(int *source, int *auxiliary, int *destination)
{
    printf("Source: ");
    for (int i = 1; i < source[0] + 1; i++) printf("%i ", source[i]);
    printf("\nAuxiliary: ");
    for (int i = 1; i < auxiliary[0] + 1; i++) printf("%i ", auxiliary[i]);
    printf("\nDestination: ");
    for (int i = 1; i < destination[0] + 1; i++) printf("%i ", destination[i]);
    printf("\n\n");
}