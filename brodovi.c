#define _CRT_SECURE_NO_WARNINGSb

#include "functions.h"

koordinate coords;

int main() {
    // 1, 4 (snake_case)
    int** ships;
    char** pseudo_gui;
    int i, j;
    int n;
    char switch_size, switch_difficulty;
    int difficulty = 0;
    int shipcount = 0;
    int x_count = 0;

    // 12
    char naslov[18] = {'P', 'O', 'T', 'A', 'P', 'A', 'N', 'J', 'E',
                        ' ', 'B', 'R', 'O', 'D', 'O', 'V', 'A', '\n'};
    printf("%s", naslov);

    // 8
    printf("\nChoose size(S,M,L):");
    scanf("%c", &switch_size);
    buff_clr();

    switch (switch_size)
    {
    case 's':
    case 'S':
        n = 3;
        break;
    case 'm':
    case 'M':
        n = 5;
        break;
    case 'l':
    case 'L':
        n = 8;
        break;
    default:
        printf("\nYou've choosen poorly!\n");
        exit(EXIT_FAILURE);
    }

    // 8
    printf("\nChoose difficulty(E,H):");
    scanf("%c", &switch_difficulty);
    buff_clr();

    switch (switch_difficulty)
    {
    case 'e':
    case 'E':
        difficulty = (n * 2) - 2;
        break;
    case 'h':
    case 'H':
        difficulty = (n / 2);
        break;
    default:
        printf("\nYou've choosen poorly!");
        exit(EXIT_FAILURE);
    }

    // 13, 14
    ships = (int**)malloc(n * sizeof(int*));

    for (i = 0; i < n; i++)
    {
        ships[i] = (int*)malloc(n * sizeof(int));
    }

    pseudo_gui = (char**)malloc((n + 1) * sizeof(char*));

    for (i = 0; i < (n + 1); i++)
    {
        pseudo_gui[i] = (char*)malloc((n + 1) * sizeof(char));
    }

    // 10
    shipcount = randgen(ships, n);

    printf("\n\nNumber of ships to be sunk:%d", shipcount);
    printf("\nNumber of misses allowed: %d\n\n", difficulty);

    draw_gui(pseudo_gui, n);
    result(pseudo_gui, n);

    while (shipcount != 0 && x_count != difficulty)
    {

        printf("\nEnter coordinates (x,y):");
        scanf("%d,%d", &coords.x, &coords.y);
        buff_clr();

        // Windows clear screen
        system("cls");
        // Linux clear screen
        // system("clear");

        battle(ships, pseudo_gui, n, coords, &shipcount, &x_count);
        result(pseudo_gui, n);

        printf("Number of ships to be sunk:%d", shipcount);
        printf("\nNumber of misses (out of %d): %d\n\n", difficulty, x_count);
    }

    if (shipcount == 0)
    {
        printf("\nWinner!\n\n");
    }
    else if (x_count == difficulty)
    {
        printf("\nYou Lose!\n\n");
    }

    // 15
    for (i = 0; i < n; i++)
    {
        free(ships[i]);
    }
    free(ships);

    for (i = 0; i < (n + 1); i++)
    {
        free(pseudo_gui[i]);
    }
    free(pseudo_gui);

    return 0;
}
