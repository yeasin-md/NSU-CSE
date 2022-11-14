#include <stdio.h>

int main()
{
    int num, isPrime = 1;

    printf("Enter any integer: ");
    scanf("%d", &num);

    // factors of num=====
    // for (int i = 1; i <= num / 2; i++)
    // {
    //     num % i == 0 ? printf("%d\n", i) : 0;
    // }

    // whether number is prime or not=====
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            isPrime = 0;
            break;
        }
    }
    isPrime == 0 ? printf("%d is not a prime number", num) : printf("%d is a prime number", num);

    return 0;
}