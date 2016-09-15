#ifndef INCLUDE_GAME_TETRIS_BOARD_CONTROLLER_H_
#define INCLUDE_GAME_TETRIS_BOARD_CONTROLLER_H_

#include "../include/game/game_board/tetris_board.h"
#include "../include/game/game_board/tetris_board_piece.h"


typedef struct _TetrisBoardController TetrisBoardController;


extern TetrisBoardController *tetris_board_controller_init(TetrisBoard *board);


extern void tetris_board_controller_free(TetrisBoardController *self);




#endif
