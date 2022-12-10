#include <stdio.h>
#include <stdlib.h>

void print_board();
void player_movement();
void wrong_step();
void win();
int game_state = 1, height = 0, width = 0;
int board_height = 5, board_width = 5;
char player;
int main()
{

    while (game_state == 1)
    {

        print_board();
        player_movement();
        wrong_step();
        win();
    }
    // if (game_state == 2)
    // {
    //     printf("\nLosed Game");
    // }
    return 0;
}

void player_movement()
{
    scanf(" %c", &player);

    switch (player)
    {
    case 'w':
        if (height != 0)
        {
            height--;
        }
        break;
    case 'a':
        if (width != 0)
        {
            width--;
        }
        break;
    case 's':
        if (height != board_height - 1)
        {
            height++;
        }
        break;
    case 'd':
        if (width != board_width - 1)
        {
            width++;
        }
        break;
    }
};
void wrong_step()
{
    if (height == 2 && width == 3)
    {
        game_state = 2;
        printf("\nStepped On Bomb ()*, Game Over");
    }
    else if (height == 3 && width == 1)
    {
        game_state = 2;
        printf("\nStepped On Bomb ()*, Game Over");
    }
};
void win()
{
    if (height == board_height - 1 && width == board_width - 1 * 9)
    {
        game_state = 0;
        printf("\nHola!! You Won!!");
    }
};

void print_board()
{
    char robot = 'R', blank = ' ', endPoint = 'O', bomb = '*';

    for (int i = 0; i < board_height; i++)
    {
        for (int j = 0; j < board_width; j++)
        {
            if (i == height && j == width)
            {
                printf("|%c", robot);
            }
            else if (i == board_height - 1 && j == board_width - 1)
            {
                printf("|%c", endPoint);
            }
            else if (i == 2 && j == 3)
            {
                printf("|%c", bomb);
            }

            else if (i == 3 && j == 1)
            {
                printf("|%c", bomb);
            }
            else
            {
                printf("|%c", blank);
            }
        }
        printf("|\n");
    }
}