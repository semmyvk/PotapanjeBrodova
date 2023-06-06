#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 2
struct par
{
    int y;
    int x;

};

// 3
typedef struct par koordinate;

bool valid(int i, int n);
void buff_clr(void);
int randgen(int** ships_ptr, int n);
void draw_gui(char** pseudo_gui_ptr, int n);
void battle(int** ships_ptr, char** pseudo_gui_ptr, int n, koordinate x, int* count, int* miss);
void result(char** pseudo_gui_ptr, int n);

#endif
