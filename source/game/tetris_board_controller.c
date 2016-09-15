#include "../include/game/tetris_board_controller.h"

#include <malloc.h>


struct _TetrisBoardController
{
	TetrisBoard *board;
	TetrisBoardPiece *current_piece;
};


static Point *get_spawn_point(TetrisBoardController *self)
{
	u16 width = tetris_board_get_width(self->board);
	return point_init(width, 0);
}





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
	return tetris_board_is_piece_location_valid(self->board, piece, get_spawn_point(self));
}

void tetris_board_controller_spawn_piece(TetrisBoardController *self, TetrisPiece *piece)
{
	self->current_piece = tetris_board_piece_init(piece, get_spawn_point(self));
}

bool tetris_board_can_current_piece_move(TetrisBoardController *self, s8 x_offset, s8 y_offset)
{
	Point *old_point = tetris_board_piece_get_location(self->current_piece);
	Point *new_location = point_init(point_get_x(old_point) + x_offset, point_get_y(old_point) + y_offset);

	return tetris_board_is_piece_location_valid(self->board, tetris_board_piece_get_tetris_piece(self->current_piece), new_location);
}

void tetris_board_controller_move_current_piece(TetrisBoardController *self, s8 x_offset, s8 y_offset)
{
	if (tetris_board_can_current_piece_move(self, x_offset, y_offset))
	{
		Point *old_point = tetris_board_piece_get_location(self->current_piece);
		Point *new_location = point_init(point_get_x(old_point) + x_offset, point_get_y(old_point) + y_offset);

		tetris_board_piece_set_location(self->current_piece, new_location);
	}
}

void tetris_board_controller_rotate_current_piece(TetrisBoardController *self, u8 rotations)
{
	//ZZZ TODO
}
