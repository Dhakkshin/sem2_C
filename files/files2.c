#include <stdio.h>

struct item
{
    char name[100];
    int quantity, price;
};

int main(void)
{
    FILE *fptr = fopen("testStruct.bin", "wb");
    struct item a[4] = {{"Apple", 10, 10}, {"Banana", 20, 20}, {"Orange", 30, 30}, {"Mango", 40, 40}};
    fwrite(&a, sizeof(struct item), 4, fptr);
    fclose(fptr);

    FILE *fptr2 = fopen("testStruct.bin", "rb");
    struct item b[4];
    fread(&b, sizeof(struct item), 4, fptr2);
    for (int i = 0; i < 4; i++)
    {
        printf("Name: %s\nQuantity: %i\nPrice: %i\n\n", b[i].name, b[i].quantity, b[i].price);
    }
    fclose(fptr2);
}