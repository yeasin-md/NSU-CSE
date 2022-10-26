
#include <stdio.h>
#include <time.h>
int main()
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    int accountNumber = 54321;
    int password = 1234;
    int inAccunt = 5500;
    int enteredPass, enteredAccNum;
    int option;
    printf("Hello sir, Please select an option:\n");
    printf("1.Check Account Details\n");
    // printf("2.Check Total Amount In Account\n");
    printf("2.Withdraw Balance\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("---------------------------------------------------\nEnter Account Number:");
        scanf("%d", &enteredAccNum);
        printf("Enter Pin Number:");
        scanf("%d", &enteredPass);

        if (enteredPass != password || enteredAccNum != accountNumber)
        {
            printf("Sorry Wrong Credentials!");
        }
        else
        {
            printf("//////////------------Acoount Details:-------------/////////\n");
            printf("User: Username\n");
            printf("In Account: %d\n", inAccunt);
            printf("Account Created: 23/10/14\n");
            printf("Server time and date: %s \n ---------------------------------------------------", asctime(timeinfo));
        }
        break;
    case 2:
        printf("---------------------------------------------------\nEnter Account Number:");
        scanf("%d", &enteredAccNum);
        printf("Enter Pin Number:");
        scanf("%d", &enteredPass);

        if (enteredPass != password || enteredAccNum != accountNumber)
        {
            printf("Sorry Wrong Credentials!");
        }
        else
        {
            int wAmount;
            printf("//////////--------------------/////////\n");
            printf("In Account: %d\n", inAccunt);
            printf("Enter Withdrawl Amount: ");

            scanf("%d", &wAmount);
            printf("Withdrawl Success!!\n");

            printf("Current Balance: %d \n", inAccunt - wAmount);

            printf("Server time and date: %s \n ---------------------------------------------------", asctime(timeinfo));
        }
        break;

    default:
        break;
    }
    return 0;
}