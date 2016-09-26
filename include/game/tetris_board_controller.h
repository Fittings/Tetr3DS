#ifndef INCLUDE_GAME_TETRIS_BOARD_CONTROLLER_H_
#define INCLUDE_GAME_TETRIS_BOARD_CONTROLLER_H_

#include "../include/game/game_board/tetris_board.h"
#include "../include/game/game_board/tetris_board_piece.h"


typedef struct _TetrisBoardController TetrisBoardController;


extern TetrisBoardController *tetris_board_controller_init(TetrisBoard *board);
extern void tetris_board_controller_free(TetrisBoardController *self);

extern void tetris_board_controller_remove_completed_rows(TetrisBoardController *self);

extern void tetris_board_controller_spawn_piece(TetrisBoardController *self, TetrisPiece *piece);
extern void tetris_board_controller_move_current_piece(TetrisBoardController *self, s8 x_offset, s8 y_offset);
extern void tetris_board_controller_rotate_current_piece(TetrisBoardController *self, u8 rotations);
extern void tetris_board_controller_commit_piece(TetrisBoardController *self);

extern void tetris_board_controller_drop_current_piece(TetrisBoardController *self);


extern bool tetris_board_controller_can_spawn_piece(TetrisBoardController *self, TetrisPiece *piece);
extern bool tetris_board_is_current_piece(TetrisBoardController *self);
extern bool tetris_board_can_current_piece_move(TetrisBoardController *self, s8 x_offset, s8 y_offset);

extern void tetris_board_controller_draw(TetrisBoardController *self);




#endif
