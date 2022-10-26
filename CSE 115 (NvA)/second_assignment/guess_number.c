#include <stdio.h>

int main()
{
    int myNum;

    printf("---------------Select any number between 1-10 and multiply it by 5---------------\n \n");
    printf("---------------...multiplied?---------------\n \n");
    printf("---------------Now add 6 to it and divide it by 2.---------------\n \n");
    printf("---------------What's your answer? Enter the answer: ");
    scanf("%d", &myNum);

    int guessedNum = ((myNum * 2) - 6) / 5;

    printf("\n \nI think you guessed: %d", guessedNum);

    return 0;
}