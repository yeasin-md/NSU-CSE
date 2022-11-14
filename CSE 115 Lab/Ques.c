#include <stdio.h>
#include <math.h>
int main()
{
    int n = 5;
    int reslut;
    for (int i = 0; i <= n; i++)
    {
        for (int space = n; space >= i; space--)
        {
            printf("*", space);
        }

        for (int j = 0; j <= i; j++)
        {
            reslut = pow(2, j);
            printf("%d ", reslut);
        }

        printf("\n");
    }

    return 0;
}