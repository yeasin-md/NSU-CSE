#include <stdio.h>

void guess();
void lifeCounter();
char array[6] = {'m', 'a', 'n', '_', 'o', '\0'};
int state = 0;
char input;
int i = 0, life = 5;
int main()
{

    while (state == 0)
    {
        printf("\n");
        printf("Life Remaining: %d\n", life);

        puts("man_o");
        guess();
        lifeCounter();
    }
    return 0;
}

void guess()
{
    printf("Enter the correct letter: ");
    scanf(" %c", &input);
    if (input != 'g')
    {
        array[3] = input;
        puts(array);
        life--;
    }

    if (input == 'g')
    {
        array[3] = input;
        puts(array);
        state = 1;
        puts("You Won");
    }
}
void lifeCounter()
{

    if (life == 0)
    {
        state = 1;
        printf("\nGame Over");
    }
}
