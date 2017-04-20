#ifndef COMMON_H
#define COMMON_H

typedef enum{
    figure_empty = 0,       // пусто    0b
    figure_pawn,            // пешка    1b
    figure_knight,          // конь     10b
    figure_bishop,          // слон     11b
    figure_rook,            // ладья    100b
    figure_queen,           // ферзь    101b
    figure_king             // король   110b
}EFigures;

#define SIDECOLORBIT 5

#define IS_FIGURE_WHITE(figure) ((figure & (1 << SIDECOLORBIT))?(true):(false))
#define IS_FIGURE_BLACK(figure) ((figure & (1 << SIDECOLORBIT))?(true):(false))

#define CHESS_BOARD_SIZE 8

#endif // COMMON_H
