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
    fp = fopen("employee.dat", "w");
    struct emp e[2];

    if (fp == NULL)
    {
        fprintf(stderr, "Error Found");
        exit(1);
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            printf("Enter Id: ");
            scanf("%d", &e[i].eId);
            printf("Enter Age: ");
            scanf("%d", &e[i].age);
            printf("Enter Name: ");
            scanf(" %s", e[i].name);
            printf("Enter Salary: ");
            scanf("%d", &e[i].salary);
        }
        for (int j = 0; j < 2; j++)
        {
            fwrite(&e[j], sizeof(struct emp), 1, fp);
        }
        puts("Content Added Success");

        fclose(fp);
    }

    return 0;
}