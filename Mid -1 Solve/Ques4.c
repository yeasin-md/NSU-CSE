#include <stdio.h>
int main()
{
    int arraySize = 5;
    int array[arraySize], searchKey;

    for (int i = 1; i <= arraySize; i++)
    {
        printf("Enter elements %d : ", i);
        scanf("%d", &array[i]);
    }

    printf("Search your mark: ");
    scanf("%d", &searchKey);

    for (int j = 1; j <= arraySize; j++)
    {
        if (array[j] == searchKey)
        {
            printf("\n%d is Found in index no %d", searchKey, j);
        }
    }

    return 0;
}