#include <stdio.h>
#include <math.h>
int main()
{

    int i, n;
    float sum = 0, product = 1;

    printf("Enter Number: ");
    scanf("%d", &n);

    //////////---Scenario::01----//////
    printf("1. Sum: 1+2+3+...+n\n");
    for (i = 1; i <= n; i++)
    {
        sum += i;
        printf("%.1f\n", sum);
    }

    //////////---Scenario::02----//////
    printf("\n2. Sum: 1 + 1/2 + 1/3 +...+ n\n");
    for (i = 1; i <= n; i++)
    {
        sum += i;
        printf("1/%.1f\n", sum);
    }

    //////////---Scenario::03----//////
    printf("\n3. Product: 1 * 2 * 3 *...* n\n");
    for (i = 1; i <= n; i++)
    {
        product *= i;
        printf("%.1f\n", product);
    }

    //////////---Scenario::04----//////
    printf("\n4. Sum: 1 + 2^2 + 3^3 +...+ n\n");
    for (i = 1; i <= n; i++)
    {
        sum += i;
        printf("%.1f\n", pow(sum, i));
    }

    //////////---Scenario::05----//////
    printf("\n4. Sum: 1 + 1/2^2 + 1/3^3 +...+ n\n");
    for (i = 1; i <= n; i++)
    {
        sum += i;
        printf("1/%.1f\n", pow(sum, i));
    }
    return 0;
}