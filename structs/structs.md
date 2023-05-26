## 26/5/23

# structs

### - user defined datatype
- keyword: struct
- declaration synatx:

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

- declaration does *not* take memory space
- name, roll_no etc are stuct members
- no structure member can be intialised.
- structure member can be accessed only through the structure variable using the dot (.) operator.
- usage:
```c
struct student s;
```
- to create a global struct variable outside main, add the variable name after the `;` in the struct declaration.

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

- irrelevent note:
`extern` in C is akin to `global` in Python.
`extern` tells the compiler "trust me, there's an `i` out there, use it and dont throw a fit."

- `int i;` is definition.
- `extern int i;` is declaration.
- declaration does not allocate memory and can not be initialised in the same statement.