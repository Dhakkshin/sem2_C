# Files
## 4 / 7 /23

Reading and Writing from files

###
- `fopen()` (remember to escape special characters in the path)
    - modes:
        - w
        - r
        - a
        - w+
        - r+
        - a+
    - flags:
        - rt (for text)
        - rb (for binary)

- `fread()`
- `fwrite()`
- `fclose()`
- `fseek(fptr, no_of_bytes, origin)`
    - number_of_bytes:
        - positive: move forward
        - negative: move backward
    - origin (move with respect to):
        - Begining: `SEEK_SET`or `0`
        - Current: `CUR`or `1`
        - End: `END`or `2` 
    - returns:
        - `0` if successful
        - `1` if unsuccessful   
- `feof()`
    - returns `1` if end of file is reached
    - returns `0` if end of file is not reached
    - Example:
        ```c
        while (!feof(fptr))
        {
            // do something
        }
        ```

1. Code to writr and read multiple lines (text file)
```c
#include <stdio.h>

int main(void)
{
    // writing
    FILE *fptr1 = fopen("test.txt", "w");
    printf("Enter number of lines: ");
    int n;
    scanf("%i", &n);
    getchar();
    char str[100];
    while (n > 0)
    {
        fgets(str, 100, stdin);
        fputs(str, fptr1); 
        n--;
    }
    fclose(fptr1);
    printf("Write Complete\n\n");
    

    // reading
    FILE *fptr2 = fopen("test.txt", "r");
    int position;
    while (fgets(str, 100, fptr2))
    {
        position = ftell(fptr2);
        printf("%s", str);
    }
    fclose(fptr2);
    printf("Read Complete\n");
}
```

2. Code to read 20 character from the end of a file
```c
#include <stdio.h>

int main(void)
{
    FILE *fptr2 = fopen("test.txt", "r");
    fseek(fptr2, -20, 2);
    char str[100];
    fgets(str, 100, fptr2);
    printf("%s\n", str);
    fclose(fptr2);
}
```

3. Code to write and read (binary file)
```c
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
```