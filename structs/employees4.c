#include <stdio.h>

struct employees
{
    char name[100];
    int id;
};

int main(void)
{
    struct employees e[3];
    char dummy;

    for (int i = 0; i < 3; i++)
    {
        printf("Employee %i\nEnter the name: ", i + 1);
        fgets(e[i].name, 100, stdin);

        printf("Enter ID: ");
        scanf("%i", &e[i].id);
        scanf("%c", &dummy); //to get rid of the return character in the buffer
    }
    
    for (int i = 0; i < 3; i++)
    {
        printf("Name : %sID   : %i\n\n", e[i].name, e[i].id);
    }
}