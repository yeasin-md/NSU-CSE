#include <stdio.h>

int main()
{

    int num1, num2, remainder;
    int gcd, lcm;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int n1 = num1, n2 = num2;

    while (n2 != 0)
    {
        remainder = n1 % n2;
        n1 = n2;
        n2 = remainder;
    }
    gcd = n1;
    lcm = (num1 * num2) / gcd;

    printf("Here, GCD: %d\n", gcd);
    printf("Here, LCM: %d", lcm);

    return 0;
}