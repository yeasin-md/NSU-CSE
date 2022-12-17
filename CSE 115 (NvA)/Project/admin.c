#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Store
{
    int productId;
    char item_name[10];
    int price;
    int offer_price;
    int stock;
    char size[3];
} item[2];

void add_input();

int main()
{

    add_input();

    return 0;
}

void add_input()
{
    FILE *fp;
    fp = fopen("products.txt", "w");
    int i, j, id;

    if (fp == NULL)
    {
        fprintf(stderr, "Can't open the file");
        exit(1);
    }
    else
    {

        for (i = 0; i < 2; i++)
        {
            id = i + 1;
            item[i].productId = id;

            printf("Product Id: %d\n", item[i].productId);
            printf("Enter product name: ");
            scanf("%s", item[i].item_name);
            printf("Enter price: ");
            scanf("%d", &item[i].price);
            printf("Enter offer: ");
            scanf("%d", &item[i].offer_price);
            printf("Enter stock: ");
            scanf("%d", &item[i].stock);
            printf("Enter size: ");
            for (j = 0; j < 3; j++)
            {
                scanf(" %c", &item[i].size[j]);
            }
            printf("\n");
        }

        for (int k = 0; k < 2; k++)
        {
            fwrite(&item[k], sizeof(struct Store), 1, fp);
        }

        fwrite != 0 ? printf("Content added succcess") : printf("Error");
        fclose(fp);
    }
}
