#include <stdio.h>

int main()
{
    int numb;
    printf("Enter Number of Inputs: ");
    scanf("%d", &numb);
    double marks[numb];

    for (int i = 1; i <= numb; i++)
    {
        printf("Enter mark %d: ", i);
        scanf("%lf", &marks[i]);
    }

    for (int j = 1; j <= numb; j++)
    {
        printf("mark %d: %.2lf\n", j, marks[j]);
    }

    // // storing the largest number to arr[0]
    // for (int i = 1; i < numb; i++)
    // {
    //     if (marks[0] < marks[i])
    //     {
    //         marks[0] = marks[i];
    //     }
    // }
    // printf("Highest Number: %.2lf", marks[0]);

    for (int i = 1; i < numb; i++)
    {
        if (marks[i] < marks[0])
        {
            marks[0] = marks[i];
        }
    }
    printf("Lowest Number: %.2lf", marks[0]);
    return 0;
}