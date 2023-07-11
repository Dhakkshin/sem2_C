// write a program to write the details of n students into a file
// the details are: name, roll number, marks
// get the vaules and input in the file

#include <stdio.h>

struct student
{
    char name[100];
    int rollNum, marks[3];
};

int main(void)
{
    FILE *fptr = fopen("files4.txt", "a");
    if (fptr == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int n;
    printf("ENter the number of students: ");
    scanf("%i", &n);
    getchar();

    struct student s;
    int sub1Marks = 0, sub2Marks = 0, sub3Marks = 0;

    for (int i = 0; i < n; i++)
    {
        printf("Enter the name of student %i: ", i + 1);
        fgets(s.name, 100, stdin);
        printf("Enter the roll number of student %i: ", i + 1);
        scanf("%i", &s.rollNum);
        printf("Enter the marks of student %i separated by spaces : ", i + 1);
        scanf("%i %i %i", s.marks[0], s.marks[1], s.marks[2]);
        getchar();
        sub1Marks += s.marks[0];
        sub2Marks += s.marks[1];
        sub3Marks += s.marks[2];
        fwrite(&s, sizeof(struct student), 1, fptr);
    }

    float sub1Avg = sub1Marks / n;
    float sub2Avg = sub2Marks / n;
    float sub3Avg = sub3Marks / n;

    fprintf(fptr, "%f", sub1Avg);
    fprintf(fptr, "%f", sub2Avg);
    fprintf(fptr, "%f", sub3Avg);

    fclose(fptr);

    ///////////

    FILE *fptr2 = fopen("files4.txt", "r");
    if (fptr2 == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fread(&s, sizeof(struct student), 1, fptr2);
        printf("Name: %s", s.name);
        printf("Roll number: %i\n", s.rollNum);
        printf("Marks: %i %i %i\n", s.marks[0], s.marks[1], s.marks[2]);
    }

    float avg1, avg2, avg3;
    fscanf(fptr2, "%f", &avg1);
    fscanf(fptr2, "%f", &avg2);
    fscanf(fptr2, "%f", &avg3); 

    printf("Average marks of subject 1: %f\nAverage marks of subject 2: %f\nAverage marks of subject 2: %f\n", avg1, avg2, avg3);
    fclose(fptr2);
    
}