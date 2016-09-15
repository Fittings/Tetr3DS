#include "../include/game/tetris_board_controller.h"

#include <malloc.h>


struct _TetrisBoardController
{
	TetrisBoard *board;
	TetrisBoardPiece *current_piece;
};


TetrisBoardController *tetris_board_controller_init(TetrisBoard *board)
{
	TetrisBoardController *self = malloc(sizeof *self);

	if (!self || board == NULL) return NULL;

	{
		self->board = board;
		self->current_piece = NULL;
	}

	return self;
}

bool tetris_board_controller_can_spawn_piece(TetrisBoardController *self, TetrisPiece *piece)
{
	return false; //ZZZ TODO
}

void tetris_board_controller_spawn_piece(TetrisBoardController *self, TetrisPiece *piece)
{
	return; //ZZZ TODO
}

void tetris_board_controller_move_current_piece(TetrisBoardController *self, s8 x_offset, s8 y_offset)
{
	return; //ZZZ TODO
}

void tetris_board_controller_rotate_current_piece(TetrisBoardController *self, u8 rotations)
{
	return; //ZZZ TODO
}
