#include <stdio.h>

int calculation(int a, int b, char c)
{

    return c == '+' ? a + b : c == '-'      ? a - b
                          : c == 'x' || '*' ? a * b
                          : c == '/' || 'd' ? a / b
                                            : 0;
}

int main()
{
    int num1, num2;
    char op;
    printf("//////----Calculator----///////");
    printf("\nEnter Operator #(+, -, x or *, / or d): ");
    scanf("%c", &op);
    printf("\nEnter First Number: ");
    scanf("%d", &num1);

    printf("\nEnter Second Number: ");
    scanf("%d", &num2);

    printf("Result %d", calculation(num1, num2, op));

    return 0;
}
