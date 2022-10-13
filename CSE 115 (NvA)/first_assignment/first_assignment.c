#include <stdio.h>

int main(void)
{
    int passingYear;
    float cgpa;
    char name[32];
    char academicTestName[4];

    printf("Write your name: ");
    // input for writing the name====
    scanf("%s", &name);

    printf("Enter Academic Test Name: ");
    scanf("%s", &academicTestName);

    printf("Enter %s passing year: ", academicTestName);
    scanf("%d", &passingYear);

    printf("Enter %s pass GPA: ", academicTestName);
    scanf("%f", &cgpa);

    printf("Student Information: \n Name: %s \n Academic Test Name: %s (Passing Year: %d) \n Achieved GPA: %.2f", name, academicTestName, passingYear, cgpa);

    return 0;
}