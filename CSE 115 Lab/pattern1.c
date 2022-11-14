#include <stdio.h>

int main()
{
    for (int i = 1; i <= 5; i++)
    {

        //      1
        //     1 2
        //    1 2 3
        //   1 2 3 4
        //  1 2 3 4 5

        for (int j = 5; j >= i; j--)
        {
            printf("%d", j);
        }
        for (int j = 1; j <= i; j++)
        {
            printf("* ", j);
        }

        printf("\n");
    }

    return 0;
}