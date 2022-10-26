#include <stdio.h>
int main()
{
    int side1, side2, side3;
    printf("Enter length of Side 1: ");
    scanf("%d", &side1);
    printf("Enter length of Side 2: ");
    scanf("%d", &side2);
    printf("Enter length of Side 3: ");
    scanf("%d", &side3);

    if (side1 == side2 && side2 == side3 && side3 == side1)
    {
        printf("Its an equilateral triangle");
    }
    else if (side1 == side2 || side2 == side3 || side3 == side1)
    {
        printf("Its an isoscelene triangle");
    }
    else if (side1 != side2 && side2 != side3 && side3 != side1)
    {
        printf("Its a scalene triangle");
    }

    return 0;
}