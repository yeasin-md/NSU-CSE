#include <stdio.h>
int main()
{
    int n, i, count = 0;
    printf("Enter a number between #(1-150): ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
            count++;
    }
    if (n < 1 || n > 150)
        printf("Please Select Between #(1-150)");
    else if (n % 2 == 0)
        printf("Even Non Prime Number.");
    else if (n % 2 != 0 && count++)
        printf("Odd Prime Number.");
    else if (count++)
        printf("Prime number.");
    return 0;
}