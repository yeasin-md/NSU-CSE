#include <stdio.h>

int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    for (i = 9; i >= 0; i--)
    {
        printf("%d ", array[i]);
    }

    return 0;
}