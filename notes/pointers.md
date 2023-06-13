# Pointers

## 20/05/23

###

- ptr stores the memory location of another variable.
- it is of type `type *`
- Example 1:
```c
#include <stdio.h>

int main(void)
{
    int x = 4;
    int *ptr = &x;
    printf("%i, %p\n", *ptr, ptr);
    //same as
    // printf("%i, %p\n", x, ptr);
}
```
- Dereferencing: `*ptr` (in say printf()), will go to the memory address and return the value in that address

- Data type of the pointer is same that of the value that it is pointing to.

- Example 2:
```c
#include <stdio.h>

int main(void)
{
    float f = 1.2;
    float *fptr = &f;
    printf("%f, %p\n",f, fptr);
    // also works:
    // printf("%f, %p", *fptr, fptr); -> dereferencing
}
```

- 2 ways to print address: &f and fptr
- 2 ways to print value  : f  and *fptr

- Example 3:
```c
#include <stdio.h>

int main(void)
{
    int n1[] = {1,2,3,4}, n2;
    int *p1 = n1;
    int *p2 = n2;

    printf("")

    // n1, n2, p1, p2
    // &n1, &n2, &p1, &p2
    // *p1, *p2
}
```
In the above code:
- n1: mem address
- n2: value 
- p1: mem address
- p2: mem address
- &n1: mem address
- &n2: mem address
- &p1: mem address
- &p2: mem address
- *p1: value
- *p2: value

The following groups will have same values:
- n1, &n1, p1
- p2, &n2
- p1[0], *p1
- n2, *p2
- &p1
- &p2

# Pointers Arithmetic

### 
```c
#include <stdio.h>

int main(void)
{
    int n1[] = {1,2,3,4};
    int *p1 = n1;

    printf("%i, %i\n",*p1, *(p1 + 1));
}
```
- Arithmetic can be performed on pointers to dereference the desired address.

- Example 4:
```c
#include <stdio.h>

int main(void)
{
    int n1[] = {1,2,3,4};
    int *p1 = n1;

    for (int i = 0; i < 4; i++)
    {
        printf("%i, %p\n", *(p1 + i), (p1 + i));
    }
}
```
    Output:
    1, 0x7ffe0dccacd0
    2, 0x7ffe0dccacd4
    3, 0x7ffe0dccacd8
    4, 0x7ffe0dccacdc

- Only addition and subtraction are allowed on pointers (increment and decrement operators work).

- Question:
Using the concept of pointers, find the sum of the elements in the array.
```c
```


## 31/05/23:
Off topic
###
- 2 regions in memory
    - stack (for auto variables)
    - data segment region (global variables)
        - initialised 
        - uninitialised (given value 0)

- register
     - fastest access, least capacity.
     - register varibles: stored in register for instant access.
     - when register is full, new requests for register space are routed to memory without intimation.

- static variable:
    - scope: inside the parent func.
    - lifetime: throughout the program.
    - stored in data segment.

## Back to Pointers

### 
- swapping numbers in place using ptr:
```c
//swap using ptrs

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int a = 2, b = 5;
    int *aptr = &a, *bptr = &b;
    swap(aptr, bptr);
    printf("%i %i\n", a, b);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
```
- For char array alone this thype of initialisation is allowed:
```c
#include <stdio.h>

int main(void)
{
    char *c = "hello";
    printf("%s\n",c);
}
```