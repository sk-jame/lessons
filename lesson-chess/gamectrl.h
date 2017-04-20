#ifndef GAMECTRL_H
#define GAMECTRL_H

#include "common.h"

void game_init();
void game_deinit();

int** game_board();
int* game_deadFigures();

EColors game_isWhiteMove();
void game_togglePlayer();

bool game_moveAction(char oldPos[2], char newPos[2]);

#endif // GAMECTRL_H
