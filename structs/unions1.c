#include <stdio.h>
#include <string.h>

struct employees
{
    char name[100];
    int id;
};

struct employees
{
    char name[100];
    int id;
};

int main(void)
{
    struct employees e1 = {"me", 1};
    union employees e2 = {"me", 1};

    printf("%i %i\n", sizeof(e1), sizeof(e2));
}