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

5. More Complex store
```c
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
```
- 
```c
struct point p;
p.lat = 10;
```
```c
struct point *p1;
p1 -> lat = 10;
// scanf("%i", &(p1 -> lat));  
```

## 28/06/2023

## Nested Structures

###

- using structs as members of another struct just like another data type

1. Write 2 structs student and address, write func to get input.

```c
#include <stdio.h>


struct location 
{
    char *lattitude, *longitude;
};

struct address
{
    int doorNo, pincode;
    char streetName[100], city[100];
    struct location l;
};

struct student
{
    char *name, * rollNo;
    struct address a;
};

int main(void)
{
    struct student students;
    insert(students);
}

struct student insert(struct student s)
{
    printf("Enter name: ");
    fgets(s.name, 100 ,stdin);

    printf("Enter roll number: ");
    fgets(s.rollNo, 100, stdin);

    printf("Enter door number: ");
    scanf("%i", &s.a.doorNo);
    getchar();

    printf("Enter pincode: ");
    scanf("%i", &s.a.pincode);
    getchar();

    printf("Enter street name: ");
    fgets(s.a.streetName, 100, stdin);

    printf("Enter city name: ");
    fgets(s.a.city, 100, stdin);

    printf("Enter lattitude: ");
    fgets(s.a.l.lattitude, 100, stdin);

    printf("Enter logitude: ");
    fgets(s.a.l.longitude, 100, stdin);    
}


```