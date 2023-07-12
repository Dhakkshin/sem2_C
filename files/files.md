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
   - `fwrite(&var, sizeof(var), 1, fptr)`
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
- `fprintf()`
    - `fprintf(fptr, "format string", arg1, arg2, ...)`
    - Example:
        ```c
        fprintf(fptr, "%s %i", "Hello", 10);
        ```
- `fscanf()`
    - `fscanf(fptr, "format string", arg1, arg2, ...)`
    - Example:
        ```c
        fscanf(fptr, "%s %i", str, &n);
        ```

1. Code to write and read multiple lines (text file)
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


## 11 / 7 / 23
Enumerations

###
- `enum` is a user defined data type
- `enum` is used to assign names to integral constants
- `enum` is used to make the code more readable and maintainable

- Syntax:
    ```c
    enum enum_name
    {
        constant1,
        constant2,
        constant3,
        ...
    };
    ```
- Example along with usage:
    ```c
    #include <stdio.h>

    enum week
    {
        Monday,    // 0
        Tuesday,   // 1
        Wednesday, // 2
        Thursday,  // 3
        Friday,    // 4
        Saturday,  // 5
        Sunday     // 6
    };

    int main(void)
    {
        enum week today;
        today = Wednesday;
        printf("Day %i\n", today + 1);
    }
    ```
- usage with scanf:
    ```c
    enum ErrorCode
    {
        on,
        off
    };
    scanf("%i", (int *)&e);
    ```
- enum is not a string, it is an integer

- example with initialisation:
    ```c
    enum week
    {
        Monday = 1,    // 1
        Tuesday,       // 2
        Wednesday = 5, // 5
        Thursday,      // 6
        Friday,        // 7
        Saturday,      // 8
        Sunday         // 9
    };
    ```
