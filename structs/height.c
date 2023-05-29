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