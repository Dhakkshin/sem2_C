#include <stdio.h>

struct employees 
{
    char name[100];
    int id;
} e = {"Dhakkshin", 4};

int main(void)
{
    printf("Name : %s\nID   : %i\n", e.name, e.id);
}