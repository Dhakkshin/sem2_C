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

