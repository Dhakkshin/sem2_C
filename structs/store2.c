#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct item
{
    char name[100];
    int quantity, price;
};

void insert(struct item items[], int n);
struct item ithElement(struct item[], int i);
void printAll(struct item items[]);
int search(struct item items[], char name[]);
struct item*  priceGreaterThan(struct item items[], int n);

int length = 1, len;

int main(void)
{
    struct item* items = malloc(sizeof(struct item));
    items[0] = (struct item){"sample", 0, 0};

    int length = 0, choice, n, exit = 0;

    do
    {    
    printf("1. Insert\n2. ith item\n3. Search\n4. Greater than n\n5. Print all\n6.Exit\n");
    scanf("%i", &choice);
    getchar();
    switch (choice)
    {
        case 1:
        printf("Enter the number of elemnets you want to add: ");
        scanf("%i", &n);
        getchar();
        insert(items, n);
        break;

        case 2:
        printf("Enter the index of the item you want to access: ");
        scanf("%i", &n);
        getchar();
        struct item x = ithElement(items, n);
        printf("Item: %s\tQuantity: %d\tUnit price:%d\n", x.name, x.quantity, x.price);
        break;

        case 3:
        printf("Enter the name of the item you want to search: ");
        char itemToSearch[100];
        fgets(itemToSearch, 100, stdin);
        int y = search(items, itemToSearch);
        (y == 1) ? printf("Item found.\n") : printf("Item not found.\n");
        break;

        case 4:
        printf("Enter a number: ");
        scanf("%i", &n);
        getchar();
        struct item*  tmp = priceGreaterThan(items, n);
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
        printf("Invalid Choice.\n");
        break;
    }
    }while(exit != 1);
    return 0;
}

// add, ithItem, search, greater than n

void insert(struct item items[], int n)
{
    int q, p;
    struct item* tmp = realloc(items, (length + n) * sizeof(struct item));
    if (tmp == NULL)
    {
        printf("Error reallocating memory./n");
        exit(1);
    }
    items = tmp;
    for (int i = length; i < length + n; i++)
    {
        printf("Enter item name: ");
        fgets(items[i].name, 100, stdin);
        
        printf("Enter quantity: ");
        scanf("%i", &q);
        getchar();
        items[i].quantity = q;
        
        printf("Enter price: ");
        scanf("%i", &p);
        getchar();
        items[i].price = p;
    }
    length = length + n;
}

struct item ithElement(struct item items[], int i)
{
    return items[i];
}

int search(struct item items[], char name[])
{
    for (int i = 0; i < length; i++)
    {
        if (strcmp(items[i].name, name) == 0)
        {
            return 1;
        }
    }
    return 0;
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
    struct item* greaterThann = malloc(sizeof(struct item));
    greaterThann[0] = (struct item){"sample", 0, 0};
    len = 1;
    for(int i = 0; i < length; i++)
    {
        if (items[i].price > n)
        {
            len++;
            struct item* tmp = realloc(greaterThann, len * sizeof(struct item));
            if (tmp == NULL)
            {
                printf("Error reallocating memory.\n");
                exit(1);
            }
            greaterThann = tmp;
            greaterThann[len - 1] = items[i];
            
        }
    }
    return greaterThann;
}