#include <stdio.h>

int main()
{
    int n;
    printf("Enter Rows: ");
    scanf("%d", &n);
    // rows====
    for (int i = 1; i <= n; i++)
    {
        // columns====
        // for (int j = 0; j < i; j++)
        // {
        //     // printf(" %d ", j + 1);

        //     printf(" + ");
        // }

        ////////////=======Reverse==========///////////

        // for (int j = n; j >= i; j--)
        // {
        //     printf(" %d ", j);

        //     // printf(" + ");
        // }

        ////////////=======Reverse2==========///////////
        for (int j = n; j >= i; j--)
        {
            printf(" ");

            // printf("%d", j);
        }
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", j);

            // printf("* ");
        }

        printf("\n");
    }

    return 0;
}