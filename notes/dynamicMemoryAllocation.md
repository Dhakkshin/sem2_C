# Dynamic Memory Allocation

## 16/6/23

malloc()

### - takes the number of bytes a argument and return the address of the first byte of that chunk of memory

- Usage: `(void *)malloc(size);` can be later typecast to the appropriate  type
- Example:

```c
int p;
p = (int*)malloc(sizeof(int));
```

- Code 1 - allocate memory for int array of size 10 and write and read using pointer arithmetic:

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(sizeof(int) * 10);

    for (int i = 0; i < 10; i++)
    {
        *(p + i) = i + 1;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", *(p + i));
    }

    free(p);
}
```

- `malloc()` initialises all values to 0. (check this, it is supposede to be garbage values)

- `free()` takes the pointer as argument and frees the memory allocated using malloc.

- `calloc()` takes number of locations and size of each location as arguments and returns the address of the 1st location. initialises to 0.

- Code 2 - same as 1 but using `calloc()`

```c
//calloc
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = calloc(10, sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        *(p + i) = i + 1;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", *(p + i));
    }

    free(p);    
}
```

- `realloc()` takes a pointer and a new size as arguments and returns either the same/new pointer depending on the memory available.

- On using `realloc()` to:
  - increase the size, it returns a pointer to a new larger chunk of memory. The old location is lost but the exixting values are copies to the new location.
  - decrease the size, it returns the original pointer but with the reduced size. Values present outside the reduced location are lost.

- Code 3 - write a program that takes a sentence as input, dynamically allocates memory for that sentence and counts number of words in that sentence.

```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
    printf("Enter a sentence:\n");

    int size = 1, words = 0;
    char *s = malloc(sizeof(char));
    do
    {
        *(s + size - 1) = getch();
        if (*(s + size - 1) == ' ')
        {
            words += 1;
        }
        size += 1;
        s = realloc(s, sizeof(char) * size);
    }
    while (*(s + size - 2) != '.');

    *(s + size - 1) = '\0';

    printf("\nEnterned sentence is:\n%s\nIt has %i words", s, words + 1);

    free(s);
}
```
## 20/06/23

 DImensional Pointers

- array of pointers:
    - `int *p[4]`
    - here, each element in the 4 elemnt array is an integer pointer.

- pointer to an array:
    - `int (*p)`[4]
    - simply points to begining of the array

- Code 1:
Create an array of int pointers, initialise 4 ints, initialise the array to the pointers of those 4 ints. Print the address and the int value using the the array's name.

```c
//array of pointers
#include <stdio.h>

int main(void)
{
    int *a[4];
    int w = 1, x = 2, y = 3, z = 4;

    a[0] = &w;
    a[1] = &x;
    a[2] = &y;
    a[3] = &z;
    
    for (int i = 0; i < 4; i++)
    {
        printf("%p, %i\n", a[i], *a[i]);
    }
}
```

- In 2D array pointer arithmetic of +1 will go to the next row.

```c
#include <stdio.h>

int main(void)
{
    int mat[3][4] = {{1, 2, 3, 4}, 
                    {5, 6, 7, 8}, 
                    {9 ,10, 11, 12}};

    int (*p)[4] = mat;

    for (int i = 0; i < 3; i++)
    {
        printf("%p, %i\n", *(p + i) + 1, *(*(p + i) + 1));
    }
}
```

- array of 5 pointers pointing to floats:
```c
float *p[5];
float a = 1, b = 2, c = 3, d = 4, e = 5;

```

- side note:
The following point to the same thing:
    - `p[4]`
    - `*(p + 4);`
    - `*(4 + p);`
    - `4[p];`
where p is a pointer to an array and 4 can be any index.

- Accessing elements in 2D arrays: `*(*(p + 1) + 1)`.

