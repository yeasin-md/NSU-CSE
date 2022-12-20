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
struct Cart
{
    int pId;
    char itemName[20];
    int price;
    int qty;
    int total_pCost;
};

struct Order
{
    int orderId;
    char userName[20];
    struct OrderedProducts
    {
        int pId;
        char itemName[20];
        int price;
        int quantity;
        int totalPrice;
    };
    char orderType[20];
};

struct User
{
    char user[20];
    int userId;
    char userPassword[20];
};

void welcome();
void showProducts();
void cart();

int main()
{
    welcome();
    showProducts();

    return 0;
}
void welcome()
{
    printf("----------------------------------------------------\n");
    printf("|              **Welcome**                         |\n");
    printf("|            **Online Store**                      |\n");
    printf("|           One Step Sollution                     |\n");
    printf("|                                                  |\n");
    printf("----------------------------------------------------\n");
}

// showing products====
void showProducts()
{
    FILE *fp;
    fp = fopen("./db/products.txt", "r");
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
    // adding product to cart using product id====
    cart();
};

// adding items to cart====
void cart()
{
    FILE *fp;
    FILE *od;
    fp = fopen("./db/products.txt", "r");
    od = fopen("./db/orders.txt", "w");
    struct Store ct;
    struct Cart cart;
    int addTocart_pId;
    char add;
    printf("Enter Product Id to add to cart: ");
    scanf("%d", &addTocart_pId);
    puts("Your searched item: ");
    while (fread(&ct, sizeof(struct Store), 1, fp))
    {

        if (ct.productId == addTocart_pId)
        {
            printf("pId: %d\n", ct.productId);
            printf("Product Name: %s\n", ct.item_name);
            printf("Price: %d\n", ct.price);
            printf("Discount: %d\n", ct.offer_price);
            printf("Price: %d\n", ct.price);
            printf("Quantity: %d\n", ct.stock);
            printf("Size: ");
            for (int j = 0; j < 3; j++)
            {
                ct.size[j] != '.' ? printf("%c ", ct.size[j]) : printf("");
            }
            printf("\n");
            printf("\n");

            printf("Enter 'y' to add this item to cart: ");
            scanf(" %c", &add);

            if (add == 'y')
            {
                cart.pId = ct.productId;
                cart.itemName[20] = ct.item_name[20];
                cart.price = ct.price;
                cart.qty = 5;
                cart.total_pCost = (cart.qty * cart.price);

                fwrite(&cart, sizeof(struct Cart), 1, od);
            }
            else
            {
                puts("Error");
            }
        }
    }
}
