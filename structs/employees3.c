#include <stdio.h>

struct employees
{
    char name[100];
    int id;
};

int main(void)
{
    struct employees e = {.name = "Dhakkshin", .id = 4};

    printf("Name : %s\nID   : %i\n", e.name, e.id);
}