#ifndef OUTPUT_H
#define OUTPUT_H

#include "common.h"

void output_init();
void output_deInit();
void output_printBoard(int **board);
char *output_moveInvite(EColors isWhiteMove);


#endif // OUTPUT_H
