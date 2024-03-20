#include <stdio.h>

struct Student
{
    char Name[30];
    int roll_no;
    float marks;
};

void Studentdetails(struct Student student[], int num_studennt)
{
    for (int i = 0; i < num_studennt; i++)
    {
        printf("\nEnetr Student %d details", i + 1);

        printf("\nStudent Name : ");
        scanf("%s", student[i].Name);

        printf("\nStudent Id : ");
        scanf("%d", &student[i].roll_no);

        printf("\nStudent Marks : ");
        scanf("%f", &student[i].marks);

        printf("\n");
    }
}

void printstructure(struct Student student)
{
    printf("Student Name: %s\n", student.Name);
    printf("Student ID: %d\n", &student.roll_no);
    printf("Student Marks: %.2f\n", &student.marks);
    printf("\n");
}

void printAllStudentDetails(struct Student students[], int num_students)
{
    printf("Details of all students:\n");
    for (int i = 0; i < num_students; ++i)
    {
        printf("Student #%d:\n", i + 1);
        printstructure(students[i]);
        printf("\n");
    }
}

int main()
{
    int num;
    printf("Eneter te no of students You Want to Enter :");
    scanf("%d", &num);

    struct Student students[num];

    Studentdetails(students, num);

    printAllStudentDetails(students, num);

    return 0;
}
