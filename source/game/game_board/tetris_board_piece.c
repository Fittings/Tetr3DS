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

void tetris_board_piece_rotate(TetrisBoardPiece *self, s8 rotations)
{
	tetris_piece_rotate(self->current_piece, rotations);
}


void tetris_board_piece_draw(TetrisBoardPiece *self, s16 start_x, s16 start_y, s16 block_size, Point *shadow_board_location)
{
	s16 x_offset = point_get_x(self->board_location) * block_size;
	s16 y_offset = point_get_y(self->board_location) * block_size;
	s16 shadow_y_offset = (point_get_y(self->board_location) + (point_get_y(shadow_board_location))) * block_size;

	tetris_piece_draw(self->current_piece, start_x + x_offset, start_y + shadow_y_offset, block_size, 0xAA); //Shadow
	tetris_piece_draw(self->current_piece, start_x + x_offset, start_y + y_offset, block_size, 0xFF); //Actual Piece

}
