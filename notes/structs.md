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