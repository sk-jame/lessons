#include <cstdlib>
#include "output.h"
#include <stdio.h>
#include "common.h"

#define CONSOLE_WIDTH   ( 80 )
#define CONSOLE_HEIGHT  ( 30 )


void output_init(){

}

void output_deInit(){

}

void output_printBoard(int **board, int whiteInvited){
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
    // TODO formated output
    for(int i = 0; i < CHESS_BOARD_SIZE; i++){
        for(int j = 0; j < CHESS_BOARD_SIZE; j++){
            printf("%02i ", board[i][j]);
        }
        printf("\n");
    }
    printf("%s move: ", (whiteInvited)?("White "):("Black "));
}
