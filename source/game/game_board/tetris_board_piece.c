#include "../include/game/game_board/tetris_board_piece.h"

#include <malloc.h>

struct _TetrisBoardPiece
{
	TetrisPiece *current_piece;
	Point *board_location;
};

TetrisBoardPiece *tetris_board_piece_init(TetrisPiece *tetris_piece, Point *board_location)
{
	TetrisBoardPiece *self = malloc(sizeof *self);

	if (!self || tetris_piece == NULL || board_location == NULL) return NULL;

	{
		self->current_piece = tetris_piece;
		self->board_location = board_location;
	}

	return self;
}


void tetris_board_piece_free(TetrisBoardPiece *self)
{
	if (self)
	{
		tetris_piece_free(self->current_piece);
		point_free(self->board_location);
		free(self);
	}
}

TetrisPiece *tetris_board_piece_get_tetris_piece(TetrisBoardPiece *self)
{
	return self->current_piece;
}

Point *tetris_board_piece_get_location(TetrisBoardPiece *self)
{
	return self->board_location;
}

void tetris_board_piece_set_location(TetrisBoardPiece *self, Point *new_location)
{
	self->board_location = new_location;
}

void tetris_board_piece_rotate(TetrisBoardPiece *self, u8 rotations)
{
	tetris_piece_rotate(self->current_piece, rotations);
}

void tetris_board_piece_draw(TetrisBoardPiece *self, u16 start_x, u16 start_y, u16 block_size)
{
	tetris_piece_draw(self->current_piece, start_x, start_y, block_size);
}
