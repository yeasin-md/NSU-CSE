#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include<
struct emp
{
    int eId;
    int age;
    char name[20];
    int salary;
};
FILE *fp;
int main()
{
    fp = fopen("employee.dat", "r");
    struct emp e1;

    if (fp == NULL)
    {
        fprintf(stderr, "Error Found");
        exit(1);
    }
    else
    {
        while (fread(&e1, sizeof(struct emp), 1, fp))
        {
            printf("Emp Id: %d\n", e1.eId);
            printf("Age: %d\n", e1.age);
            printf("Name: %s\n", e1.name);
            printf("Salary: %d\n", e1.salary);
        }

        fclose(fp);
    }

    return 0;
}