#ifndef INCLUDE_GAME_GAME_BOARD_TETRIS_BOARD_PIECE_H_
#define INCLUDE_GAME_GAME_BOARD_TETRIS_BOARD_PIECE_H_

#include "../include/game/block/piece/tetris_piece.h"



typedef struct _TetrisBoardPiece TetrisBoardPiece;



extern TetrisBoardPiece *tetris_board_piece_init(TetrisPiece *tetris_piece, Point *board_location);

extern void tetris_board_piece_free(TetrisBoardPiece *self);

extern TetrisPiece *tetris_board_piece_get_tetris_piece(TetrisBoardPiece *self);

extern void tetris_board_piece_draw(TetrisBoardPiece *self, u16 start_x, u16 start_y, u16 block_size, Point *shadow_board_location);

extern Point *tetris_board_piece_get_location(TetrisBoardPiece *self);

extern void tetris_board_piece_set_location(TetrisBoardPiece *self, Point *new_location);

extern void tetris_board_piece_rotate(TetrisBoardPiece *self, u8 rotations);

#endif
