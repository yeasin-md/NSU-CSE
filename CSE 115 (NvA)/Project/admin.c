#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
struct Store
{
    int productId;
    char item_name[10];
    int price;
    int offer_price;
    int stock;
    char size[3];
};
// struct Cart
// {
//     int pId;
//     char itemName[20];
//     // char user[20];

//     int price;
//     int qty;
//     // int total_pCost;
// };
void welcome();
void admin_login();
void menu();
int navigation;
int menuFlag;
int loginChance = 3;

// dashboard with utilities===
void dashBoard();
void viewBalance();
void viewOrders();
void removeProduct();
void viewAllProducts();
void addnewProduct();

int main()
{
    // logging in to enter the dashboard===
    admin_login();
    // dashBoard();

    return 0;
}

void welcome()
{

    printf("----------------------------------------------------\n");
    printf("|              **Welcome**                         |\n");
    printf("|            **Online Store**                      |\n");
    printf("|               Dashboard                          |\n");
    printf("|                                                  |\n");
    printf("----------------------------------------------------\n");
}

void admin_login()
{
    char userName[20] = "admin", getUser[20];
    char password[20] = "admin123", getPass[20];

    while (loginChance != 0)
    {
        // getting userId and pass from user===
        puts("\n****Please Login first to continue***");
        printf("Username: ");
        scanf("%s", &getUser);
        printf("Password: ");
        scanf("%s", &getPass);

        // validating userId and Pass to continue===
        if (strcmp(userName, getUser) != 0 || strcmp(password, getPass) != 0)
        {
            puts("\nUsername or Password is incorrect");
            loginChance--;
            printf("You have %d chances\n", loginChance);
        }
        else
        {
            welcome();
            menu(); // shwoing menu to user===
        }
    }
}

void menu()
{
    // int num;

    // navigation = num;

    while (menuFlag != 1)
    {
        printf("---------------------------------------------------\n");
        printf("|                Dashboard Menu:                  |\n");
        printf("---------------------------------------------------\n");
        puts("1. View Balance");
        puts("2. View Orders");
        puts("3. Remove Product");
        puts("4. View All Products");
        puts("5. Add New Product/s");
        puts("6. Exit");

        printf("Enter the number you want to navigate to: ");
        scanf("%d", &navigation);
        dashBoard();
    }
}

void dashBoard()
{
    switch (navigation)
    {

    case 1:
        viewBalance();
        // menuFlag = 0;
        break;
    case 2:
        viewOrders();
        // menuFlag = 0;
        break;
    case 3:
        removeProduct();
        // menuFlag = 0;
        break;
    case 4:
        viewAllProducts();
        // menuFlag = 0;
        break;
    case 5:
        addnewProduct();
        // menuFlag = 0;

        break;
    case 6:
        menuFlag = 1;
        loginChance = 0;
        printf("---------------------------------------------------\n");
        printf("|           DashBoard Exit Successfull            |\n");
        printf("---------------------------------------------------\n");
        break;
    default:
        break;
    }
}

void viewBalance()
{
    FILE *of;
    of = fopen("./db/orders.dat", "r");
    char userName[10], item_name[20];
    int productId, price, quantity;
    int totalBalance = 0;

    while (fscanf(of, "%d%s%s%d%d", &productId, userName, item_name, &price, &quantity) != EOF)
    {

        // printf("%d\t%s\t%s\t%d\t%d\n", productId, userName, item_name, price, quantity);
        totalBalance += price;
    }
    printf("---------------------------------------------------\n");
    printf("|     Total Balance In Store: %d                  |\n", totalBalance);
    printf("---------------------------------------------------\n");
}

void viewOrders()
{
    FILE *of;
    of = fopen("./db/orders.dat", "r");
    // struct Cart cart;
    // int pId, price, qty;
    char userName[10], item_name[20];
    int productId, price, quantity;
    int totalOrderCount = 0;
    printf("---------------------------------------------------\n");
    printf("|           All Orders In Store:                  |\n");
    printf("---------------------------------------------------\n");
    // while (fread(&cart, sizeof(struct Store), 1, of))
    // {
    //     printf("Product Id: %d\n", cart.pId);
    //     printf("Product Name: %s\n", cart.itemName);
    //     // printf("Product User: %s\n", cart.user);
    //     printf("Product Price: %d\n", cart.price);
    //     printf("Product Qty: %d\n", cart.qty);
    //     printf("Product Total Cost: %d\n", cart.price * cart.qty);
    //     totalOrderCount++;
    // }
    // puts("pId   UserName    PName       Price       Qty");
    while (fscanf(of, "%d%s%s%d%d", &productId, userName, item_name, &price, &quantity) != EOF)
    {

        printf("%d\t%s\t%s\t%d\t%d\n", productId, userName, item_name, price, quantity);
        totalOrderCount++;
    }

    printf("------------------------\n");
    printf("|  Total Order/s: %d   |\n", totalOrderCount);
    printf("------------------------\n");
    fclose(of);
}

void viewUsers()
{
    puts("User Nai");
}
void removeProduct()
{
    int totalProductCount = 0;
    FILE *fp;
    fp = fopen("./db/products.dat", "r+");
    struct Store p1;
    struct Store rmv[totalProductCount];
    int rmvpId;
    if (fp == NULL)
    {
        fprintf(stderr, "Can't open the file");
        exit(1);
    }
    else
    {
        printf("---------------------------------------------------\n");
        printf("|             Remove Product                      |\n");
        printf("---------------------------------------------------\n");
        while (fread(&p1, sizeof(struct Store), 1, fp))
        {

            printf("pId: %d\n", p1.productId);
            printf("Product Name: %s\n", p1.item_name);
            printf("Price: %d\n", p1.price);
            printf("Discount: %d\n", p1.offer_price);
            printf("Quantity: %d\n", p1.stock);
            printf("Size: ");
            for (int j = 0; j < 3; j++)
            {
                p1.size[j] != '.' ? printf("%c ", p1.size[j]) : printf("");
            }
            printf("\n");
            printf("\n");
            totalProductCount++;
        }
        printf("----------------------------\n");
        printf("|    Total Product/s: %d   |\n", totalProductCount);
        printf("----------------------------\n");
        printf("Enter Product Id to remove: ");
        scanf("%d", &rmvpId);

        for (int i = 0; i < totalProductCount; i++)
        {
            if (rmv[i].productId == rmvpId)
            {
                rmv[i].productId = rmv[i + 1].productId;
                strcpy(rmv[i].item_name, rmv[i + 1].item_name);
                rmv[i].price = rmv[i + 1].price;
                rmv[i].offer_price = rmv[i + 1].offer_price;
                rmv[i].stock = rmv[i + 1].stock;
                for (int s = 0; s < 3; s++)
                {
                    strcpy(rmv[s].size, rmv[s + 1].size);
                }
            }
        }
        for (int k = 0; k < totalProductCount; k++)
        {
            fwrite(&rmv[k], sizeof(struct Store), 1, fp);
        }
        fwrite != 0 ? printf("Content added succcess\n\n") : printf("Error");
        fclose(fp);
        printf("----------------------------\n");
        printf("|   Product Remove Success |\n");
        printf("----------------------------\n");
    }
}

void viewAllProducts()
{
    int totalProductCount = 0;
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
        printf("---------------------------------------------------\n");
        printf("|           All Products In Store:                |\n");
        printf("---------------------------------------------------\n");
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
            totalProductCount++;
        }
        printf("----------------------------\n");
        printf("|    Total Product/s: %d   |\n", totalProductCount);
        printf("----------------------------\n");

        fclose(fp);
    }
}

void addnewProduct()
{

    FILE *fp;
    fp = fopen("./db/products.dat", "a");
    srand(time(0));
    int id, items;
    printf("---------------------------------------------------\n");
    printf("|           Add New Product:                      |\n");
    printf("---------------------------------------------------\n");
    int r = rand() % 200;
    if (fp == NULL)
    {
        fprintf(stderr, "Can't open the file");
        exit(1);
    }
    else
    {
        printf("Enter Number of items to be added: ");
        scanf("%d", &items);

        struct Store item[items];

        for (int i = 0; i < items; i++)
        {
            id = r + i;
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
            for (int j = 0; j < 3; j++)
            {
                scanf(" %c", &item[i].size[j]);
            }
            printf("\n");
        }

        for (int k = 0; k < items; k++)
        {
            fwrite(&item[k], sizeof(struct Store), 1, fp);
        }

        fwrite != 0 ? printf("Content added succcess\n\n") : printf("Error");
        fclose(fp);
    }
}
