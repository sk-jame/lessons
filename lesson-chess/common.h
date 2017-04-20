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

typedef enum{
    chess_black,
    chess_white
}EColors;


#define GET_FIGURE(b)     (EFigures)(b & (~(1 << SIDECOLORBIT)))
#define GET_COLOR(figure) ((figure & (1 << SIDECOLORBIT))?(chess_white):(chess_black))
#define SET_COLOR(color)  ((color == chess_black)?(0):(1 << SIDECOLORBIT))

#define INT2LETTER(letter) (char((int)letter + 65))
#define LETTER2INT(letter) ((int)letter - 65)

#define STR2DIGIT(ch)      (ch - '0')

#define CHESS_BOARD_SIZE 8

#endif // COMMON_H
