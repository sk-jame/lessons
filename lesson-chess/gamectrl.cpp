#include "gamectrl.h"
#include "common.h"
#include "string.h"

static int** board = NULL;

static int deadFigures[32];
static int deadFiguresCount;

inline bool moveFigure(int oldX, int oldY, int x, int y, EFigures fig, EColors color);
inline bool eatFigure(int x, int y);

static EColors currentPlayer;

#define SET_FIGURE(x,y,fig, color) { moveFigure(-1,-1, x,y, fig, color); }

inline void put4figures(int offset, EFigures fig){
    SET_FIGURE(0, 0 + offset, fig,chess_black);
    SET_FIGURE(0, CHESS_BOARD_SIZE - 1 - offset, fig,chess_black);

    SET_FIGURE(CHESS_BOARD_SIZE - 1, 0 + offset, fig, chess_white);
    SET_FIGURE(CHESS_BOARD_SIZE - 1, CHESS_BOARD_SIZE - offset - 1, fig, chess_white);

}

void game_init(){
    currentPlayer = chess_white;
    board = new int*[CHESS_BOARD_SIZE];
    for(int i = 0; i < CHESS_BOARD_SIZE; i++){
        board[i] = new int[CHESS_BOARD_SIZE];
    }

    deadFiguresCount = 0;

        // set up pawns
    for(int i = 0; i < CHESS_BOARD_SIZE; i++){
        SET_FIGURE(1,i, figure_pawn, chess_black);
        SET_FIGURE(CHESS_BOARD_SIZE - 2, i, figure_pawn, chess_white);
    }

    put4figures(0, figure_rook);
    put4figures(1, figure_knight);
    put4figures(2, figure_bishop);
    SET_FIGURE(0, 3, figure_king, chess_black);
    SET_FIGURE(CHESS_BOARD_SIZE - 1, 3, figure_queen, chess_white);
    SET_FIGURE(0, 4, figure_king, chess_black);
    SET_FIGURE(CHESS_BOARD_SIZE - 1, 4, figure_queen, chess_white);
}

void game_deinit(){
    delete board;
}

int** game_board(){
    return board;
}

int *game_deadFigures(){
    return deadFigures;
}

inline bool moveFigure(int oldX, int oldY, int x, int y, EFigures fig, EColors color){
    if (board[x][y] != figure_empty){
        if (GET_COLOR(board[x][y]) != color){
            eatFigure(x,y);
        }
        else{
            return false;
        }
    }

    if (oldX > 0 && oldY > 0){
        board[oldX][oldY] = figure_empty;
    }

    board[x][y] = fig | SET_COLOR(color);
    return true;
}

inline bool eatFigure(int x, int y){
    deadFigures[deadFiguresCount++] = board[x][y];
    return true;
}

bool game_moveAction(char oldPos[], char newPos[]){
    int old_col = LETTER2INT(oldPos[0]);
    int old_row = STR2DIGIT(oldPos[1]) - 1;

    int new_col = LETTER2INT(newPos[0]);
    int new_row = STR2DIGIT(newPos[1]) - 1;

    int fig = GET_FIGURE(board[old_row][old_col]);
    EColors color = GET_COLOR(board[old_row][old_col]);
    if (color != currentPlayer) return false;

    return moveFigure(old_row, old_col,
               new_row, new_col,
               EFigures(fig),
               GET_COLOR(board[old_row][old_col]));

}

EColors game_isWhiteMove(){
    return currentPlayer;
}

void game_togglePlayer(){
    currentPlayer = (currentPlayer == chess_black)?(chess_white):(chess_black);
}
