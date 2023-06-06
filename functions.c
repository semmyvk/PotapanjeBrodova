#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"

// 7
inline bool valid(int i, int n) {
    return i >= 0 && i < n;
}

void buff_clr(void)
{
    char junk;
    do {
        junk = getchar();
    } while (junk != '\n');
}

// 9
int randgen(int** ships_ptr, int n)
{
    int i, j, count = 0;
    srand((unsigned)time(NULL));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            ships_ptr[i][j] = rand() % 2;
            if (ships_ptr[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}


void draw_gui(char** pseudo_gui_ptr, int n)
{
    int i, j;

    pseudo_gui_ptr[0][0] = ' ';
    for (i = 1; i < (n + 1); i++)
    {
        pseudo_gui_ptr[0][i] = '0' + i;
        pseudo_gui_ptr[i][0] = '0' + i;
    }

    for (i = 1; i < (n + 1); i++)
    {
        for (j = 1; j < (n + 1); j++)
        {
            pseudo_gui_ptr[i][j] = '+';
        }
    }
}

void battle(int** ships_ptr, char** pseudo_gui_ptr, int n, koordinate x, int* count, int* miss)
{
    int i = x.x - 1;
    int j = x.y - 1;

    if (!valid(i, n) || !valid(j, n)) {
        printf("\nNemoguca koordinata. Pokusajte ponovno!\n\n");
    }
    else if (pseudo_gui_ptr[i + 1][j + 1] == 'O' ||
             pseudo_gui_ptr[i + 1][j + 1] == 'X') {
        printf("\nYou've already uncovered this field!\n\n");
    }
    else if (ships_ptr[i][j] == 1) {
        printf("\nHit!\n");
        pseudo_gui_ptr[i + 1][j + 1] = 'O';
        (*count)--;

    }
    else if (ships_ptr[i][j] == 0) {
        printf("\nMiss!\n");
        pseudo_gui_ptr[i + 1][j + 1] = 'X';
        (*miss)++;
    }
}

void result(char** pseudo_gui_ptr, int n)
{
    int i, j;

    for (i = 0; i < (n + 1); i++)
    {
        for (j = 0; j < (n + 1); j++)
        {
            printf("%5c", pseudo_gui_ptr[i][j]);
        }
        printf("\n\n");
    }
}

