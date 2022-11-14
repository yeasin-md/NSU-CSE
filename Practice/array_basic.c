#include <stdio.h>

int main()
{
    int inputNumb;
    printf("Enter inputNumb: ");
    scanf("%d", &inputNumb);
    int marks[inputNumb];
    float sum = 0;

    for (int i = 1; i <= inputNumb; i++)
    {
        printf("Enter Mark %d: ", i);
        scanf("%d", &marks[i]);
    }

    printf("\n//////=====Achieved Marks:=====//////\n");

    for (int i = 1; i <= inputNumb; i++)
    {
        printf("Subject %d: %d\n", i, marks[i]);
        // scanf("%d", &marks[i]);
    }

    for (int i = 1; i <= inputNumb; i++)
    {
        sum = sum + marks[i];
    }
    printf("\nTotal Marks: %.0f \n", sum);
    float avg = sum / inputNumb;
    printf("Average Mark for %d subjects: %.2f \n", inputNumb, avg);

    return 0;
}