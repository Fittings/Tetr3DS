#ifndef INCLUDE_GAME_GAME_BOARD_TETRIS_BOARD_PIECE_H_
#define INCLUDE_GAME_GAME_BOARD_TETRIS_BOARD_PIECE_H_

#include "../include/game/block/piece/tetris_piece.h"



typedef struct _TetrisBoardPiece TetrisBoardPiece;



extern TetrisBoardPiece *tetris_board_piece_init(TetrisPiece *tetris_piece, Point *board_location);

extern void tetris_board_piece_free(TetrisBoardPiece *self);

extern TetrisPiece *tetris_board_piece_get_tetris_piece(TetrisBoardPiece *self);

extern Point *tetris_board_piece_get_location(TetrisBoardPiece *self);

extern void tetris_board_piece_set_location(TetrisBoardPiece *self, Point *new_location);


#endif
