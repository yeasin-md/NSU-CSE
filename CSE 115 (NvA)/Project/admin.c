#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct Store
{
    int productId;
    char item_name[10];
    int price;
    int offer_price;
    int stock;
    char size[3];
};

void welcome();
void admin_login();
void menu();
int navigation;

// dashboard with utilities===
void dashBoard();
void viewBalance();
void viewOrders();
void viewUsers();
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

    // getting userId and pass from user===
    puts("\n****Please Login first to continue***");
    printf("Username: ");
    scanf("%s", &getUser);
    printf("Password: ");
    scanf("%s", &getPass);

    // validating userId and Pass to continue===
    if (strcmp(userName, getUser) != 0 || strcmp(password, getPass) != 0)
    {
        puts("Username or Password is incorrect");
    }
    else
    {
        welcome();
        menu(); // shwoing menu to user===
    }
}

void menu()
{
    // int num;
    puts("1. View Balance");
    puts("2. View Orders");
    puts("3. View Users");
    puts("4. View All Products");
    puts("5. Add New Product/s");
    puts("6. Exit");

    printf("Enter the number you want to navigate to: ");
    scanf("%d", &navigation);
    // navigation = num;

    dashBoard();
}

void dashBoard()
{
    switch (navigation)
    {

    case 1:
        viewBalance();
        break;
    case 2:
        viewOrders();
        break;
    case 3:
        viewUsers();
        break;
    case 4:
        viewAllProducts();
        break;
    case 5:
        addnewProduct();
        break;
    case 6:

        break;
    default:
        break;
    }
}

void viewBalance()
{
    puts("Teka Nai");
}

void viewOrders()
{
    puts("Order Nai");
}

void viewUsers()
{
    puts("User Nai");
}

void viewAllProducts()
{
    int totalProductCount = 0;
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
        printf("------------------------\n");
        printf("|  Total Product/s: %d  |\n", totalProductCount);
        printf("------------------------\n");

        fclose(fp);
    }
}

void addnewProduct()
{

    FILE *fp;
    fp = fopen("products.txt", "a");
    int id, items;
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

        fwrite != 0 ? printf("Content added succcess") : printf("Error");
        fclose(fp);
    }
}
