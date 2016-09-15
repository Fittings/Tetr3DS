#ifndef INCLUDE_GAME_GAME_BOARD_TETRIS_BOARD_PIECE_H_
#define INCLUDE_GAME_GAME_BOARD_TETRIS_BOARD_PIECE_H_

#include "../include/game/block/piece/tetris_piece.h"



typedef struct _TetrisBoardPiece TetrisBoardPiece;



extern TetrisBoardPiece *tetris_board_piece_init(TetrisPiece *tetris_piece, Point *board_location);

extern void tetris_board_piece_free(TetrisBoardPiece *self);





#endif
