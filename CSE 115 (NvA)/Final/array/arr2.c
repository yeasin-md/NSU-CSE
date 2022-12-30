#include <stdio.h>

int main()
{
    int matrix[4][4];
    int mSum = 0;

    for (int k = 0; k < 4; k++)
    {
        for (int l = 0; l < 4; l++)
        {
            scanf("%d", &matrix[k][l]);
        }
    }
    for (int k = 0; k < 4; k++)
    {
        for (int l = 0; l < 4; l++)
        {
            printf("%d ", matrix[k][l]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 3 || i == 0 || i == j)
            {

                printf("%d ", matrix[i][j]);
                mSum += matrix[i][j];
            }
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("\n");

    printf("%d", mSum);

    return 0;
}