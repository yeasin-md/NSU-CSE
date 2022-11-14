#include <stdio.h>

int main()
{
    int n;
    printf("Enter Rows: ");
    scanf("%d", &n);
    // rows====

    for (int i = 1; i <= n; i++)
    {

        for (int j = n; j >= i; j--)
        {
            printf(" ", j);
        }

        for (int j = 1; j <= i; j++)
        {
            printf("* ", j);
        }

        printf("\n");
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n || j == 1 || j == n)
            {
                printf(" *");
            }
            else
                printf("  ");
        }
        printf("\n");
    }
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf(" *");
        }
        printf("\n");
    }

    return 0;
}