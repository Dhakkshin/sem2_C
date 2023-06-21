#include <stdio.h>
#include <string.h>

struct item
{
    char name[100];
    int quantity, price;
};


int main(void)
{
    struct item items[3] = {
        {"Apple", 10, 5},
        {"Banana", 15, 7},
        {"Orange", 30, 12}
    };

    char item[100];
    printf("\n");
    printf("Enter item name: ");
    fgets(item, 100, stdin);

    if (strcmp(item, "Apple\n") == 0)
    {
        printf("Item: %s\tQuantity: %d\tUnit price:%d\n", items[0].name, items[0].quantity, items[0].price);
    }
    else if (!strcmp(item, "Banana\n"))
    {
        printf("Item: %s\tQuantity: %d\tUnit price:%d\n", items[1].name, items[1].quantity, items[1].price);
    }
    else if (!strcmp(item, "Orange\n"))
    {
        printf("Item: %s\tQuantity: %d\tUnit price:%d\n", items[2].name, items[2].quantity, items[2].price);
    }
    else
    {
        printf("Item not found.\n");
    }
}