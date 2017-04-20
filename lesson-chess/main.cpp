#include "gamectrl.h"
#include "output.h"

/**
 * @brief main
 * Simple game. Uses text for ui
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]){

    game_init();
    output_init();
    output_printBoard(game_board());

    while (true) {
        char* buf = output_moveInvite(game_isWhiteMove());
        if (buf == "exit") break;
        if (game_moveAction(&buf[0], &buf[2])) game_togglePlayer();
        output_printBoard(game_board());
    }
    game_deinit();

    return 0;
}
