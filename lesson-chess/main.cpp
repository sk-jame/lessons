#include "gamectrl.h"
#include "output.h"
#include <string.h>

/**
 * @brief main
 * Simple game. Uses text for ui
 * @return
 */
int main(){

    game_init();
    output_init();
    output_printBoard(game_board(), game_deadFigures());

    while (true) {
        char* buf = output_moveInvite(game_isWhiteMove());
        if (!strcmp(buf, "exit")) break;
        if (game_moveAction(&buf[0], &buf[2])){
            game_togglePlayer();
            output_printBoard(game_board(), game_deadFigures());
        }
        else{
            output_printMessage("Wrong move!\n");
        }
    }
    game_deinit();

    return 0;
}
