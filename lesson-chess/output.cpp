#include <cstdlib>
#include "output.h"
#include <stdio.h>

#define CONSOLE_WIDTH   ( 80 )
#define CONSOLE_HEIGHT  ( 30 )

static char buffer[32];

void output_init(){

}

void output_deInit(){

}

void output_printBoard(int **board){
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
    // TODO formated output
    printf("#\t");
    for(int i = 0; i < CHESS_BOARD_SIZE; i++){
        printf("%02c ", INT2LETTER(i));
    }
    printf("\n\n");

    for(int i = 0; i < CHESS_BOARD_SIZE; i++){
        printf("%i\t", i + 1);

        for(int j = 0; j < CHESS_BOARD_SIZE; j++){
            printf("%02x ", board[i][j]);
        }
        printf("\n");
    }

}


char* output_moveInvite(EColors isWhiteMove){
    printf("%s move: ", (isWhiteMove == chess_white)?("White "):("Black "));
    scanf("%s", &buffer);
    return buffer;
}
