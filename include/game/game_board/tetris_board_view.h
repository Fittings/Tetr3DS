#ifndef INCLUDE_GAME_TETRIS_BOARD_VIEW_H_
#define INCLUDE_GAME_TETRIS_BOARD_VIEW_H_

#include "../include/game/game_board/tetris_board.h"
#include "../include/game/game_board/tetris_board_piece.h"
#include "../include/game/block/piece/tetris_piece.h"
#include "../include/general/region/region.h"


typedef struct _TetrisBoardView TetrisBoardView;


extern TetrisBoardView *tetris_board_view_init(Region *max_region, Colour board_colour);

extern void tetris_board_view_free(TetrisBoardView *self);

extern void tetris_board_view_draw(TetrisBoardView *self, TetrisBoard *board, TetrisBoardPiece *board_piece);

#endif
