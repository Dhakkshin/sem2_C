# FUNCTIONS

### syntax

`
return_datatype func_name(argumnets with datatype)
{
    //func body
    return *placeholder*;
}
`
### function prototype should placed above main

### func1
```
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

```
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
```
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
```
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
```
void func(arr[])
```
### 
- ```[]``` in ```arr[]``` can be empty here
- it is good practice always pass the length of the array as well as an argument

```
arr[2][3]
arr[][3]
arr[2][] -> wrong when using intialisation
```
### 
4. passing 2d array
```
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

### Example-1 factorial:
```
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
