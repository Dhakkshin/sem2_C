#include <stdio.h>
#include <string.h>

struct employees
{
    char name[100];
    int id;
} e;

int main(void)
{
    strcpy(e.name, "Dhakkshin");
    e.id = 4;

    printf("Name : %s\nID   : %i\n", e.name, e.id);
}