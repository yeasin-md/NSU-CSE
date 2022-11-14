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
        for (int j = n; j > 0; j--)
        {
            printf(" %d ", j);
            // printf(" * ");
        }
        printf("\n");
    }

    return 0;
}