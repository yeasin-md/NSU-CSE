#include <stdio.h>
void main()
{
    int n, i = 2, count = 0, j, isPrime;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("First %d prime numbers: ", n);
    while (count < n)
    {
        // if current value of i is a prime no., then print it
        isPrime = 1; // let the current value of i is a prime no.
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {                // if i has a divisor then i isn’t prime
                isPrime = 0; // so assign 0 to isPrime to indicate this
                break;
            }
        } // for
        if (isPrime)
        {
            printf("%d, ", i); // move this outside while loop to print n-th prime
            count++;
        }
        i++;
    } // while
} // main