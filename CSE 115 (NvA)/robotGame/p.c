#include <stdio.h>
#include <stdlib.h>
int maze[10][10], j = 0, k = 0, game_state = 1;
char m;
void welcome();
void player_movement();
void bomb_detection();
void game_fill();
void maze_draw();
void destination_checker();

int main()
{
    welcome();
    game_fill();
    while (game_state == 1)
    {
        destination_checker();
        maze_draw();
        player_movement();
        bomb_detection();
    }
    return 0;
}
void player_movement()
{
    scanf(" %c", &m);

    switch (m)
    {
    case 'w':
        if (j != 0)
            j--;
        break;
    case 'a':
        if (k != 0)
            k--;
        break;
    case 's':
        if (j != 9)
            j++;
        break;
    case 'd':
        if (k != 9)
            k++;
        break;
    }
}
void bomb_detection()
{
    if (maze[j][k] == 1)
    {
        printf("\nYou won\n");
        game_state = 0;
    }
}
void game_fill()
{
    int go, la;
    for (int b = 0; b < 10; b++)
    {
        for (int c = 0; c < 10; c++)
            maze[b][c] = 0;
    }
    go = rand() % 10;
    la = rand() % 10;
    while (go == 0 && la == 9 || go == 9 && la == 9)
    {
        go = rand() % 10;
        la = rand() % 10;
    }
    for (int d = 0; d < 4; d++)
        maze[go][la] = 1;
}
void maze_draw()
{
    char player = 'X', no_player = ' ', destination = 'O';
    for (int b = 0; b < 10; b++)
    {
        for (int c = 0; c < 10; c++)
        {
            if (b == j && c == k)
                printf("|%c", player);
            else if (b == 9 && c == 9)
                printf("|%c", destination);
            else
                printf("|%c", no_player);
        }
        printf("|\n");
    }
}
void destination_checker()
{
    if (j == 9 && k == 9)
        printf("\nYou won\n");
}
void welcome()
{
    printf("WELCOME!! USE   W A S D    TO MOVE AROUND THE MAZE AND REACH THE DESTINATION O\nAVOID ALL FLOWERS OR ELSE YOU DIE\n");
}