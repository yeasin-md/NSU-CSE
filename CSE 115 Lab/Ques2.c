#include <stdio.h>
#include <math.h>

int pass_fail(int a)
{
    int result;

    for (int x = 0; x <= a; x++)
    {
        if (x >= 0 && x < 50)
        {
            result = 0;
        }
        else if (x >= 50 && x <= 100)
        {
            result = 1;
        }
        else
        {
            result = 2;
        }
    }
    return result;
}

int main()
{
    int mark; // here, mark is collected from user by scanf
    printf("Enter Mark: ");
    scanf("%d", &mark);

    if (pass_fail(mark) == 0)
    {
        printf("You Failed");
    }
    else if (pass_fail(mark) == 1)
    {
        printf("You Passed");
    }
    else if (pass_fail(mark) == 2)
    {
        printf("out of range");
    }

    // pass_fail(mark) == 0
    //     ? printf("You Failed")
    // : pass_fail(mark) == 1 ? printf("You Passed")
    // : pass_fail(mark) == 2 ? printf("out of range")
    //                        : printf("Invalid");

    return 0;
}