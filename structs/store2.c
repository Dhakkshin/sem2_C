#include <stdio.h>
#include <string.h>

void insert(struct item items[], int n);
struct item ithElement(struct item[], int i);
void printAll(struct item items[]);
struct item search(struct item items[], char name[]);
struct item*  priceGreaterThan(struct item items[], int n);

struct item
{
    char name[100];
    int quantity, price;
};

int length = 0, len;

int main(void)
{
    struct item items[100];

    int lenght = 0, choice, n, exit = 0;


    do
    {    
    printf("1. Insert\n 2. ith item\n 3. Search\n 4. Greater than n5. Print all\n 6.Exit\n");
    scanf("%i", choice);
    fflush(stdin);
    switch (choice)
    {
        case 1:
        printf("Enter the number of elemnets you want to add: ");
        scanf("%i", n);
        insert(items, n);
        break;

        case 2:
        printf("Enter the index of the item you want to access: ");
        scanf("%i", n);
        struct item x = ithElement(items, n);
        printf("%s %i %i\n", x.name, x.quantity, x.price);
        break;

        case 3:
        printf("Enter the name of the item you want to search: ");
        char itemToSearch[100];
        fgets(itemToSearch, 100, stdin);
        struct item x = search(items, itemToSearch);
        printf("%s %i %i\n", x.name, x.quantity, x.price);
        break;

        case 4:
        printf("Enter a number: ");
        scanf("%i", n);
        struct item*  tmp = priceGreaterThan(struct item items[], int n);
        printf("The following have price greater than n: \n");
        for (int i = 0; i < len; i++)
        {
            printf("Item: %s\tQuantity: %d\tUnit price:%d\n", tmp[i].name, tmp[i].quantity, tmp[i].price);
        }
        break;
        
        case 5:
        printAll(items);
        break;

        case 6:
        exit = 1;
        break;

        default:
        printf("Invalid Choice.");
        break;
    }
    }while(exit != 1);

}

// add, ithItem, search, greater than n

void insert(struct item items[], int n)
{
    int q, p;
    for (int i = length; i < length - 1 + n; i++)
    {
        printf("Enter item name: ");
        fgets(items[i].name, 100, stdin);
        
        printf("Enter quantity: ");
        scanf("%i", &q);
        items[i].quantity = q;
        fflush(stdin);
        
        printf("Enter price: ");
        scanf("%i", &p);
        fflush(stdin);
        items[i].price = q;
    }
    length++;
}

struct item ithElement(struct item items[], int i)
{
    return items[i];
}

struct item search(struct item items[], char name[])
{
    for (int i = 0; i < length; i++)
    {
        if (strcmp(items[i].name, name) == 0)
        {
            return items[i];
        }
    }
}

void printAll(struct item items[])
{
    for (int i = 0; i < length; i++)
    {
        printf("Item: %s\tQuantity: %d\tUnit price:%d\n", items[i].name, items[i].quantity, items[i].price);
    }
}

struct item*  priceGreaterThan(struct item items[], int n)
{
    struct item greaterThann[100];
    len = 0;
    for(int i = 0; i < length; i++)
    {
        if (items[i].price > n)
        {
            greaterThann[len] = items[i];
            len++;
        }
    }
    return greaterThann;
}