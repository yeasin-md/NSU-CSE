#include <stdio.h>
int main()
{

    int ans1 = 1;
    int ans2 = 1;
    int ans3 = 2;
    int ans4 = 3;
    int ans5 = 4;
    int enteredAns1, enteredAns2, enteredAns3, enteredAns4, enteredAns5;
    printf("========Welcome to KBC Game======");
    printf("\n Task: You have to locate yourself");
    printf("\n \n Question:1 :: Your Institute?");
    printf("\n1.NSU \n2.IUB \n3.AIUB \n4.UIU \n5.EWU");
    printf("\nEnter Your Option: ");
    scanf("%d", &enteredAns1);

    printf("\n Task: You have to locate yourself");
    printf("\n \n Question:2 :: Your Area?");
    printf("\n1.Bashundhara \n2.Baridhara \n3.Badda \n4.Ghatpar \n5.Nadda");
    printf("\nEnter Your Option: ");
    scanf("%d", &enteredAns2);

    printf("\n Task: You have to locate yourself");
    printf("\n \n Question:3 :: Your City?");
    printf("\n1.Savar \n2.Dhaka \n3.Sreemongal \n4.Birampur \n5.Gajipur");
    printf("\nEnter Your Option: ");
    scanf("%d", &enteredAns3);

    printf("\n Task: You have to locate yourself");
    printf("\n \n Question:4 :: Your Country?");
    printf("\n1.India \n2.Pakistan \n3.Bangladesh \n4.USA \n5.Nepal");
    printf("\nEnter Your Option: ");
    scanf("%d", &enteredAns4);

    printf("\n Task: You have to locate yourself");
    printf("\n \n Question:1 :: Your Continent?");
    printf("\n1.Europe \n2.Atlnatinca \n3.Africa \n4.Asia \n5.Russia");
    printf("\nEnter Your Option: ");
    scanf("%d", &enteredAns5);

    int score1 = enteredAns1 == ans1 ? 1 : 0;
    int score2 = enteredAns2 == ans2 ? 1 : 0;
    int score3 = enteredAns3 == ans3 ? 1 : 0;
    int score4 = enteredAns4 == ans4 ? 1 : 0;
    int score5 = enteredAns5 == ans5 ? 1 : 0;
    int totalScore = score1 + score2 + score3 + score4 + score5;

    (totalScore > 3 && totalScore <= 5) ? printf("You woned in KBC Game with a score of %d out of 5 \n \n", totalScore) : printf("Sorry You could'nt win and you scored %d out of 5 \n \n", totalScore);

    return 0;
}