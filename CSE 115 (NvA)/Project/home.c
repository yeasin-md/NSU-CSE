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
};
void showProducts();
void welcome();
int main()
{
    welcome();
    showProducts();

    return 0;
}

void showProducts()
{
    FILE *fp;
    fp = fopen("products.txt", "r");
    struct Store p1;
    if (fp == NULL)
    {
        fprintf(stderr, "Can't open the file");
        exit(1);
    }
    else
    {
        while (fread(&p1, sizeof(struct Store), 1, fp))
        {

            printf("pId: %d\n", p1.productId);
            printf("Product Name: %s\n", p1.item_name);
            printf("Price: %d\n", p1.price);
            printf("Discount: %d\n", p1.offer_price);
            printf("Price: %d\n", p1.price);
            printf("Quantity: %d\n", p1.stock);
            printf("Size: ");
            for (int j = 0; j < 3; j++)
            {
                p1.size[j] != '.' ? printf("%c ", p1.size[j]) : printf("");
            }
            printf("\n");
            printf("\n");
        }

        fclose(fp);
    }
};

void welcome()
{
    printf("---------Online Store--------\n");
}