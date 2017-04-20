#ifndef OUTPUT_H
#define OUTPUT_H

#include "common.h"

void output_init();
void output_deInit();
void output_printBoard(int **board, int *dead);
char *output_moveInvite(EColors isWhiteMove);
void output_printMessage(const char *msg);

#endif // OUTPUT_H
