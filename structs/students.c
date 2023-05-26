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