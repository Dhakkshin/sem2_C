## Dhakkshin S R - 22z215

# C Programming - 19z205

## 21/03/23

### 1.First program to print hi
```c
#include <stdio.h>
 int main(void)
{
    printf("Hi\n");
}
```
 
- Include statement to get the header files
- Mandatory main function that takes no arguments and returns int
- All statements should end with semicolon
- stdio header file is located at:
`“D:\CodeBlocks\MinGW\lib\gcc\mingw32\4.4.1\include\c++\tr1”`

2. Program to print a number

```c
#include <stdio.h>

int main(void)
{
    int x = 4;
    printf("%i\n",x);
}
```

3.  Printing multiple numbers (type 1)

```c
#include <stdio.h>

int main(void)
{
    int x = 10;
    int y = 5;
    printf("The numbers are %i, %i\n",x,y);
   
}
```

4.  Printing multiple numbers (type 2)

```c
#include <stdio.h>

int main(void)
{
    int x = 10;
    int y = 5;
    printf("The first is %i and second is %i.\n",x,y);
}
```

5. Get input and calculate sum

```c
#include <stdio.h>

int main(void)
{
    int x;
    int y;
    printf("Enter the input: ");
    scanf("%i",&x);
    printf("Enter the input: ");
    scanf("%i",&y);
    printf("%i, %i\n",x, y);
    printf("The sum is %i\n", x+y);
}
```

6. Finding product and printing in specified format
```c
#include <stdio.h>


int main(void)
{
    //initialising the variables
    int b1, b2, b3, product;


    //getting the 1st number
    printf("Enter the first number:");
    scanf("%i", &b1);


    //getting the 2nd number
    printf("Enter the second number:");
    scanf("%i", &b2);


    //getting the 3rd number
    printf("Enter the third number:");
    scanf("%i", &b3);


    //finding product
    product = b1 * b2 *b3;


    //printing the product
    printf("The product of %i, %i and %i is %i.\n", b1, b2, b3, product);
}
```

**How does the compiler know the location of the header files?**

- In C, the compiler uses a set of predefined paths to locate header files when they are included in a source code file. These predefined paths are known as include paths or include directories.

- When a C source file that includes a header file is compiled, the compiler will search for the header file in the following directories, in order:

- The directory containing the source file being compiled.
Directories specified by the -I option on the command line.
Directories specified by environment variables, such as C_INCLUDE_PATH or CPLUS_INCLUDE_PATH.
Directories specified by default system-wide paths, which vary by platform and compiler.

- By default, the C compiler will search for standard header files in the default system-wide paths, which usually include directories like /usr/include or /usr/local/include.

- Additional directories can be specified in which to search for header files by using the -I option when invoking the compiler.





# FUNCTIONS

### syntax

```c
return_datatype func_name(argumnets with datatype)
{
    //func body
    return *placeholder*;
}
```
### function prototype should placed above main

### func1
```c
#include <stdio.h>

void func1(int a, int b);

int main(void)
{
    func1(1, 2);
}

void func1(int a, int b)
{
    //printf("Hello World\n");
    int s = a + b;
}
```

## 23/05/2023

### 
1. factors

```c
#include <stdio.h>
#include <stdbool.h>

bool isFactor(int n, int x);

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%i", &num);

    printf("The factors of %i are:\n", num);
    for (int i = 1; i <= num; i++)
    {
        if (isFactor(num, i))
        {
            printf("%i\n", i);
        }
    }
}

bool isFactor(int n, int x)
{
    return (n % x == 0);
}
```

### 
2. prime
```c
#include <stdio.h>
#include <stdbool.h>

bool isFactor(int n, int x);

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%i", &num);

    for (int i = 2; i < num; i++)
    {
        if (isFactor(num, i))
        {
            printf("%i is not a prime number.\n", num);
            return 0;
        }
    }
    printf("%i is a prime number.\n", num);
    return 0;
}

bool isFactor(int n, int x)
{
    return (n % x == 0);
}
```
### 
3. prime in range
```c
#include <stdio.h>
#include <stdbool.h>

bool isFactor(int n, int x);
int isPrime(int num);

int main(void)
{
    int num1, num2;
    printf("Enter a range: ");
    scanf("%i %i", &num1, &num2);

    printf("The prime numbers in the range %i to %i are:\n", num1, num2);
    
    for (int i = num1; i <= num2; i++)
    {
        if (isPrime(i))
        {
            printf("%i\n", i);
        }
    }
}

int isPrime(int num)
{
    
    for (int i = 2; i < num; i++)
    {
        if (isFactor(num, i))
        {
            return false;
        }
    }
    return true;
}

bool isFactor(int n, int x)
{
    return (n % x == 0);
}
```

## passing array to func
```c
void func(arr[])
```
### 
- `[]` in `arr[]` can be empty here
- it is good practice always pass the length of the array as well as an argument

```c
arr[2][3] -> allowed
arr[][3]  -> allowed
arr[2][]  -> wrong when using intialisation
```
### 
4. passing 2d array
```c
#include <stdio.h>

void print_arr(int arr[][3], int col_len, int row_len);

int main(void)
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8 ,9}};
    int col_len = sizeof(arr[0])/sizeof(int);
    int row_len = sizeof(arr)/sizeof(arr[0]);
    print_arr(arr, col_len, row_len);
}


void print_arr(int arr[][3], int col_len, int row_len)
{
    for (int i = 0; i < row_len; i++)
    {
        for (int j = 0; j < col_len; j++)
        {
            printf("%i ", arr[i][j]);
        }
        printf("\n");
    }
}
```

## 24/05/2023

### variable scope
- variables exclusive to a func -> local/auto variable
- scope -> part of program where the variable exists and is accessible
- lifetime -> time during which it is present in memory - same as that of the parent func

## stack
### 
- LIFO
- accessible only at *one end*
- push(insert) and pop(remove)
- top -> points to the top-most element of the stack

## stack-func relation
### 
- everytime a func is called the func (and its loacl variables & arguments) are *pushed to a stack of active functions*
- everytime a func returns, it is *popped from the stack* and the new top is the same *state* that it was in before calling the func that was just returned. 
     - when the a func is popped, all variables in that scope are lost but variables in the previous/parent func still exist (with values unchanged unless the pooped func returns a values and that is assigned to it) even if they have same name as the variable lost in the popped func.

## Recursion:
### 
- is when a function calls itself repeatedly
- a recursive func always has:
    -  base case (when the recursion stops)
    -  recursive case (all except base case)
- in each recursive call, the problem size should *decrease* until base case is reached

### 1. factorial:
```c
#include <stdio.h>

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%i", &num);

    printf("%i! = %i\n", num, factorial(num));
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
```
2. nth fibonacci number
```c
// nth fibonacci number
#include <stdio.h>

int fibo(int n);

int main(void)
{
    printf("Enter a number: ");
    int num;
    scanf("%i", &num);

    printf("The %ith fibonacci number is %i.\n", num, fibo(num));
}

int fibo(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n < 4)
    {
        return 1;
    }
    return fibo(n - 1) + fibo (n - 2);
}
```


## 26/5/23

# Structs

### - user defined datatype
- Keyword: struct
- Declaration synatx:

```c
struct struct_name
{
    type name;
    type name2;
    ...  ...;
    .
    .
}
```
- Declaration example:
```c
struct student
{
    char name[50], roll_no[7], phone[11];
    int age;
    float marks[6];
};
```

- Declaration does *not* take memory space
- Name, roll_no etc are stuct members
- No structure member can be intialised.
- Structure member can be accessed only through the structure variable using the dot (.) operator.
- Usage:
```c
struct student s;
```
- To create a global struct variable outside main, add the variable name after the `;` in the struct declaration.

- Example Code 1 (Get deatails for 1 student)
```c
#include <stdio.h>

struct student
{
    char name[50], roll_num[8], phone[11];
    int age;
    float marks[6];
};

int main(void)
{
    // creating a variable of type student
    struct student s;

    // filling in s
    printf("Enter your name: ");
    fgets(s.name, 50, stdin);
    printf("Enter your roll number: ");
    fgets(s.roll_num, 8, stdin);
    printf("Enter your phone number: ");
    fgets(s.phone, 11, stdin);
    printf("Enter your age: ");
    scanf("%i", &s.age);
    printf("Enter your marks:\n");
    for (int i = 0; i < 6; i++)
    {
        printf("Mark %i: ", i + 1);
        scanf("%f",&s.marks[i]);
    }

    //  displaying details in s
    printf("\n\nName: %s", s.name);
    printf("Roll number: %s", s.roll_num);
    printf("Phone number: %s", s.phone);
    printf("Age: %i\n", s.age);
    printf("Marks:\n");
    for (int i = 0; i < 6; i++)
    {
        printf("Mark %i: %f\n", i + 1, s.marks[i]);
    }
}
```

- Example Code 2 (get details and find avg marks)
```c
#include <stdio.h>

struct student
{
    char name[50], roll_num[8], phone[11];
    int age;
    float marks[6];
};

int main(void)
{
    // creating a variable of type student
    struct student s[10];

    for (int i = 0; i < 10; i++)
    {
        printf("\n\nStudent %i\n", i + 1);
        // filling in s
        printf("Enter your name: ");
        fgets(s[i].name, 50, stdin);
        printf("Enter your roll number: ");
        fgets(s[i].roll_num, 8, stdin);
        printf("Enter your phone number: ");
        fgets(s[i].phone, 11, stdin);
        printf("Enter your age: ");
        scanf("%i", &s[i].age);
        printf("Enter your marks:\n");
        for (int j = 0; j < 6; j++)
        {
            printf("Mark %i: ", j + 1);
            scanf("%f",&s[i].marks[j]);
        }
    }
    
    // calulating average marks
    float stu_avg[10], sum;
    for (int i = 0; i < 10; i++)
    {
        sum = 0;
        for (int j = 0; j < 6; j++)
        {
            sum += s[i].marks[j];
        }
        stu_avg[i] = sum / 6;
    }

    printf("Averages:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Student %i's average is %f.\n", i + 1, stu_avg[i]);
    }
}
```

- Irrelevent note:
`extern` in C is akin to `global` in Python.
`extern` tells the compiler "trust me, there's an `i` out there, use it and dont throw a fit."

- `int i;` is definition.
- `extern int i;` is declaration.
- Declaration does not allocate memory and can not be initialised in the same statement.

## 29/05/23

### 
- one way to initialise:
```c
struct employees 
{
    char name[100];
    int id;
} e= {'Dhakkshin', 4};
```
This has one-to-one relationship, just like format specifiers.

- Another way (using `strcpy()`):
```c
#include <stdio.h>
#include <string.h>

struct employees
{
    char name[100];
    int id;
} e;

int main(void)
{
    strcpy(e.name, "Dhakkshin");
    e.id = 4;

    printf("Name : %s\nID   : %i\n", e.name, e.id);
}
```
- Yet another way:
```c
#include <stdio.h>

struct employees
{
    char name[100];
    int id;
};

int main(void)
{
    struct employees e = {.name = "Dhakkshin", .id = 4};

    printf("Name : %s\nID   : %i\n", e.name, e.id);
}
```

1. Create a record for 3 employees with the struct defined above

 - Method 1:

```c
#include <stdio.h>

struct employees
{
    char name[100];
    int id;
};

int main(void)
{
    struct employees e[3] = {{.name = "Dhakkshin", .id = 4}, {.name = "qwerty", .id = 1}, {.name = "ytrewq", .id = 2}};

    for (int i = 0; i < 3; i++)
    {
        printf("Name : %s\nID   : %i\n\n", e[i].name, e[i].id);
    }
}
```
  - Method 2:

```c
#include <stdio.h>
struct employees
{
    char name[100];
    int id;
};

int main(void)
{
    struct employees e[3];
    e[0] = (struct employees){"Dhakkshin", 4};
    e[1] = (struct employees){"qwerty", 2};
    e[2] = (struct employees){"ytrewq", 2};
    
    for (int i = 0; i < 3; i++)
    {
        printf("Name : %s\nID   : %i\n\n", e[i].name, e[i].id);
    }
}
```

   - Method 3:
```c
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
```

2. Create a struct for a person with a name, height, marks(6), avg marks and age. Get input for 3 persons

- Method 1
```c
#include <stdio.h>

struct person
{
    char name[100];
    float height;
    int age;
    float marks[6];
    float avg;
};

int main(void)
{
    struct person people[3];
    char dummy;

    //getting inputs
    for (int i = 0; i < 3; i++)
    {
        printf("Person %i\nEnter the name: ", i + 1);
        fgets(people[i].name, 100, stdin);

        printf("Enter Height: ");
        scanf("%f", &people[i].height);
        scanf("%c", &dummy);

        printf("Enter Age: ");
        scanf("%i", &people[i].age);
        scanf("%c", &dummy);

        for (int j = 0; j < 6; j++)
        {
            printf("Enter mark %i: ", j + 1);
            scanf("%f", &people[i].marks[j]);
            scanf("%c", &dummy);
            people[i].avg += people[i].marks[j];
        }
        people[i].avg /= (float) 6;
    }

    printf("\n");
    // printing the data
    for (int i = 0; i < 3; i++)
    {
        printf("Person %i\nName: %sHeight: %f\nAge: %i\nAvg : %f\n\n", i + 1, people[i].name, people[i].height, people[i].age, people[i].avg);
    }
}
```
- Method 2 (user def func for avg)
```c
#include <stdio.h>

struct person
{
    char name[100];
    float height;
    int age;
    float marks[6];
    float avg;
};

float avg(struct person x);

int main(void)
{
    struct person people[3];
    char dummy;

    //getting inputs
    for (int i = 0; i < 3; i++)
    {
        printf("Person %i\nEnter the name: ", i + 1);
        fgets(people[i].name, 100, stdin);

        printf("Enter Height: ");
        scanf("%f", &people[i].height);
        scanf("%c", &dummy);

        printf("Enter Age: ");
        scanf("%i", &people[i].age);
        scanf("%c", &dummy);

        for (int j = 0; j < 6; j++)
        {
            printf("Enter mark %i: ", j + 1);
            scanf("%f", &people[i].marks[j]);
            scanf("%c", &dummy);
        }
        
        people[i].avg = avg(people[i]);
    }

    printf("\n");
    // printing the data
    for (int i = 0; i < 3; i++)
    {
        printf("Person %i\nName: %sHeight: %f\nAge: %i\nAvg : %f\n\n", i + 1, people[i].name, people[i].height, people[i].age, people[i].avg);
    }
}

float avg(struct person x)
{
    float avg = 0;
    for (int i = 1; i < 6; i++)
    {
        avg += x.marks[i];
    }
    avg /= (float)6;
    return avg;
}
```

3. Same as Q2 but just find the max avg by passing the array of structs to a func.
```c
#include <stdio.h>

struct person
{
    char name[100];
    float height;
    int age;
    float marks[6];
    float avg;
};

float avg(struct person x);
struct person maxAvg(struct person x[], int len);

int main(void)
{
    struct person people[3];
    char dummy;

    //getting inputs
    for (int i = 0; i < 3; i++)
    {
        printf("Person %i\nEnter the name: ", i + 1);
        fgets(people[i].name, 100, stdin);

        printf("Enter Height: ");
        scanf("%f", &people[i].height);
        scanf("%c", &dummy);

        printf("Enter Age: ");
        scanf("%i", &people[i].age);
        scanf("%c", &dummy);

        for (int j = 0; j < 6; j++)
        {
            printf("Enter mark %i: ", j + 1);
            scanf("%f", &people[i].marks[j]);
            scanf("%c", &dummy);
        }
        
        people[i].avg = avg(people[i]);
    }

    printf("\n");
    struct person maxRecord = maxAvg(people, 3);
    printf("Person with maximum average:\nName: %sHeight: %f\nAge: %i\nAvg : %f\n\n", maxRecord.name, maxRecord.height, maxRecord.age, maxRecord.avg);   
}

float avg(struct person x)
{
    float avg = 0;
    for (int i = 1; i < 6; i++)
    {
        avg += x.marks[i];
    }
    avg /= (float)6;
    return avg;
}

struct person maxAvg(struct person x[], int len)
{
    struct person max = x[0];
    for (int i = 0; i < len; i ++)
    {
        if (max.avg < x[i].avg)
        {
            max = x[i];
        }
    }

    return max;
}
```

4. Create a struct for items in a store with the members as items, quantity and unit price. Print details based on user input.
```c
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
        printf("Item: %s\tQuantity: %d\tUnit price:%d\n\n", items[0].name, items[0].quantity, items[0].price);
    }
    else if (!strcmp(item, "Banana\n"))
    {
        printf("Item: %s\tQuantity: %d\tUnit price:%d\n\n", items[1].name, items[1].quantity, items[1].price);
    }
    else if (!strcmp(item, "Orange\n"))
    {
        printf("Item: %s\tQuantity: %d\tUnit price:%d\n\n", items[2].name, items[2].quantity, items[2].price);
    }
    else
    {
        printf("Item not found.\n\n");
    }
}
```

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


### Dhakkshin S R &nbsp;&nbsp; 22z215 &nbsp;&nbsp; 19z205

# &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Problem Sheet 2

##  Q2
Write a C function named sort that takes a 1D integer array as input and sorts the array elements in
ascending order. The function should modify the original array passed as an argument. Implement the
function and provide a sample usage.
Function Signature:
`void sort(int arr[], int size);`


```c
#include <stdio.h>

void sort(int arr[], int size);

int main(void)
{
    int arr[10] = { 5, 2, 7, 9, 1, 3, 4, 8, 6, 0 };
    sort(arr, 10);
}

void sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) 
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}
```

## Q3
Write a program in C to perform the following operations on arrays of strings:

- Find the length of the shortest string.
- Find the length of the longest string.
- Calculate the average length of all the strings.
- Count the number of strings with a length greater than a given threshold.
Your program should take an array of strings as input and provide a menu-driven interface to perform
these operations. The program should terminate when the user chooses to exit.
Note:
Assume that the maximum number of strings in the array is 100 and the maximum length of each string
is 100 characters. The length of a string should be calculated excluding the null-terminating character.
You can use the following function signatures as a reference:
int findShortestString(char arr[][100], int n);
int findLongestString(char arr[][100], int n);
float calculateAverageLength(char arr[][100], int n);
int countStringsAboveThreshold(char arr[][100], int n, int threshold);
Provide the necessary user prompts and handle the input/output accordingly. Write the program code
and the necessary functions to implement the above operations.

```c
#include <stdio.h>
#include <string.h>

int findShortestString(char arr[][100], int n);
int findLongestString(char arr[][100], int n);
float calculateAverageLength(char arr[][100], int n);
int countStringsAboveThreshold(char arr[][100], int n, int threshold);

int main(void)
{
    char arr[100][100] = { "hello", "world", "this", "is", "a", "test", "string", "array" };
    printf("Choose one:\n1) Find the length of the shortest string.\n2) Find the length of the longest string.3) Calculate the average length of all the strings.\n4) Count the number of strings with a length greater than a given threshold.\n5) Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("The length of the shortest string is %d.\n", (int)strlen(arr[findShortestString(arr, 100)]));
        break;
    case 2:
        printf("The length of the longest string is %d.\n", (int)strlen(arr[findLongestString(arr, 100)]));
        break;
    case 3:
        printf("The average length of all the strings is %.2f.\n", calculateAverageLength(arr, 100));
        break;
    case 4:
        printf("Enter a threshold: ");
        int threshold;
        scanf("%d", &threshold);
        printf("The number of strings with a length greater than %d is %d.\n", threshold, countStringsAboveThreshold(arr, 100, threshold));
        break;
    case 5:
        return 0;
    default:
        printf("Invalid choice.\n");
        break;
    }
}

int findShortestString(char arr[][100], int n)
{
    int shortest = 101;
    for (int i = 0; i < n; i++)
    {
        if (strlen(arr[i]) < strlen(arr[shortest]))
        {
            shortest = i;
        }
    }
    return strlen(arr[shortest]);
}

int findLongestString(char arr[][100], int n)
{
    int longest = 0;
    for (int i = 0; i < n; i++)
    {
        if (strlen(arr[i]) > strlen(arr[longest]))
        {
            longest = i;
        }
    }
    return strlen(arr[longest]);
}

float calculateAverageLength(char arr[][100], int n)
{
    int totalLength = 0;
    for (int i = 0; i < n; i++)
    {
        totalLength += strlen(arr[i]);
    }
    return (float)totalLength / n;
}

int countStringsAboveThreshold(char arr[][100], int n, int threshold)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (strlen(arr[i]) > threshold)
        {
            count++;
        }
    }
    return count;
}
```