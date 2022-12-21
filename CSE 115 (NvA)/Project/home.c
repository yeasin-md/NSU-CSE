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
    // char user[20];
    int price;
    int qty;
    // int total_pCost;
};

// struct Order
// {
//     int orderId;
//     char userName[20];
//     struct OrderedProducts
//     {
//         int pId;
//         char itemName[20];
//         int price;
//         int quantity;
//         int totalPrice;
//     };
//     char orderType[20];
// };

// struct User
// {
//     char user[20];
//     int userId;
//     char userPassword[20];
// };

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
    fp = fopen("./db/products.dat", "r");
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
    FILE *usr;
    FILE *usr2;
    fp = fopen("./db/products.dat", "r");
    od = fopen("./db/orders.dat", "a");
    usr = fopen("./db/users.dat", "a");
    usr2 = fopen("./db/users.dat", "r");

    struct Store ct;
    struct Cart cart;
    int signIn_Up;
    int addTocart_pId;
    int quantity;
    char add;
    char userName[10];
    char getUser[10];
    char password[20];
    char getPass[20];

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
            printf("Enter Quantity: ");
            scanf("%d", &quantity);
            // strcpy(cart.user, userName);
            if (add == 'y')
            {
                puts("1. Don't have account? Sign");
                puts("2. Sign in");
                printf("Enter 1/2 to sign in/sign up: ");
                scanf("%d", &signIn_Up);

                switch (signIn_Up)
                {
                case 1:
                    for (;;)
                    {
                        printf("Enter User Name: ");
                        scanf("%s", userName);
                        if (strlen(userName) > 10)
                        {
                            puts("Too big user name, try again using short name");
                        }
                        else
                        {
                            // printf("Enter User Name: ");
                            // scanf("%s", userName);
                            printf("Enter Password: ");
                            scanf("%s", password);
                            break;
                        }
                    }

                    fprintf(usr, "%s\t\t", userName);
                    fprintf(usr, "%s", password);
                    fprintf(usr, "\n\n");
                    fprintf(od, "%d\t\t", ct.productId);
                    fprintf(od, "%s\t\t", userName);
                    fprintf(od, "%s\t\t", ct.item_name);
                    fprintf(od, "%d\t\t", ct.price);
                    fprintf(od, "%d\t\t", quantity);
                    fprintf(od, "\n");
                    // cart.pId = ct.productId;
                    // strcpy(cart.itemName, ct.item_name);
                    // cart.itemName[20] = ct.item_name[20];
                    // cart.price = ct.price;
                    // cart.qty = quantity;
                    // cart.total_pCost = (cart.qty * cart.price);

                    // fwrite(&cart, sizeof(struct Cart), 1, od);
                    printf("---------------------------------------------------\n");
                    printf("|           Order Placed Successfull              |\n");
                    printf("---------------------------------------------------\n");
                    fclose(fp);
                    fclose(od);
                    fclose(usr);
                    fclose(usr2);

                    break;
                case 2:
                    for (;;)
                    {
                        printf("Enter User Name: ");
                        scanf("%s", userName);
                        if (strlen(userName) > 10)
                        {
                            puts("Too big user name, try again using short name");
                        }
                        else
                        {
                            // printf("Enter User Name: ");
                            // scanf("%s", userName);
                            printf("Enter Password: ");
                            scanf("%s", password);
                            break;
                        }
                    }
                    while (fscanf(usr2, "%s%s", getUser, getPass) != EOF)
                    {
                        // printf("%s %s", getUser, getPass);
                        if (strcmp(getUser, userName) == 0)
                        {
                            printf("User: %s Pass: %s", getUser, getPass);
                            break;
                        }
                        else
                        {
                            puts("Incorrect");
                            break;
                        }
                    }
                    break;

                default:
                    break;
                }
            }
            else
            {
                puts("Error");
            }
        }
    }
}
