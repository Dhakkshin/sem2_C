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