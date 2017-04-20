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

void output_printBoard(int **board, int* dead){
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
    // TODO formated output

    /* Print message */
    printf("Pretty simple game.\nWhite figures start from bottom and has digit 2 at start.\n");

    /*  print dead before print table   */
    printf("\nDead figures:\n");
    int* pDead = dead;
    while(*pDead != 0){
        printf("%02x ", *pDead);
        pDead++;
    }
    printf("\n");

    /*  print board and headers */
    printf("#\t");
    for(int i = 0; i < CHESS_BOARD_SIZE; i++){
        printf("%2c ", INT2LETTER(i));
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
    printf("\n\nType \"exit\" to finish game.\n%s move: ", (isWhiteMove == chess_white)?("White "):("Black "));
    scanf("%s", buffer);
    return buffer;
}

void output_printMessage(const char *msg){
    printf("%s", msg);
}
