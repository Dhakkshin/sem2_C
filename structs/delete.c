#include <stdio.h>

struct item
{
    char name[100];
    int quantity, price;
};

struct item ithElement(struct item items[], int i);

int length = 0;

int main(void)
{
    struct item items[3] = {
        {"Apple", 10, 5},
        {"Banana", 15, 7},
        {"Orange", 30, 12}
    };

    struct item x = ithElement(items, 1);

    printf("%s %i %i\n", x.name, x.quantity, x.price);

    return 0;
}

struct item ithElement(struct item items[], int i)
{
    return items[i];
}