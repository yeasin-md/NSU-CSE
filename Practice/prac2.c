#include <stdio.h>

int main()
{
    int num, count = 0;

    printf("Enter any integer: ");
    scanf("%d", &num);

    // while (num != 0)
    // {
    //     // current digit is num%10
    //     // if (num % 10 != 0)
    //     count++;
    //     num /= 10;
    // }

    // printf("Total nonzero digits: %d",
    //        count);

    while (num > 0)
    {
        count = count + num % 10;
        num = num / 10;
    }
    printf("Total sum of digits: %d",
           count);
    return 0;
}