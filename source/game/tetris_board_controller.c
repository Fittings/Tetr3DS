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
	return point_init(width/2, 0);
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

void tetris_board_controller_free(TetrisBoardController *self)
{
	if (self)
	{
		tetris_board_free(self->board);
		tetris_board_piece_free(self->current_piece);
	}
}



void tetris_board_controller_remove_completed_rows(TetrisBoardController *self)
{
	tetris_board_remove_full_lines(self->board);
}

void tetris_board_controller_spawn_piece(TetrisBoardController *self, TetrisPiece *piece)
{
	self->current_piece = tetris_board_piece_init(piece, get_spawn_point(self));
}

void tetris_board_controller_commit_piece(TetrisBoardController *self)
{
	TetrisPiece *current_piece = tetris_board_piece_get_tetris_piece(self->current_piece);
	Point *current_location = tetris_board_piece_get_location(self->current_piece);

	tetris_board_concrete_tetris_piece(self->board, current_piece, current_location);

	tetris_board_piece_free(self->current_piece);
	self->current_piece = NULL;

}

void tetris_board_controller_drop_current_piece(TetrisBoardController *self)
{
	if (self->current_piece != NULL)
	{
		u16 board_height = tetris_board_get_height(self->board);
		u16 current_y = point_get_y(tetris_board_piece_get_location(self->current_piece));

		for (u16 y = board_height; y > current_y; y--)
		{
			s8 y_offset = y - current_y;

			if (tetris_board_can_current_piece_move(self, 0, y_offset))
			{
				tetris_board_controller_move_current_piece(self, 0, y_offset);
				return;
			}
		}
	}

}

void tetris_board_controller_move_current_piece(TetrisBoardController *self, s8 x_offset, s8 y_offset)
{
	if (self->current_piece != NULL && tetris_board_can_current_piece_move(self, x_offset, y_offset))
	{
		Point *old_point = tetris_board_piece_get_location(self->current_piece);
		Point *new_location = point_init(point_get_x(old_point) + x_offset, point_get_y(old_point) + y_offset);

		tetris_board_piece_set_location(self->current_piece, new_location);
	}
}


void tetris_board_controller_rotate_current_piece(TetrisBoardController *self, u8 rotations)
{
	if (self->current_piece != NULL)
	{
		tetris_board_piece_rotate(self->current_piece, rotations);

		//ZZZ TODO Fix this method up with just the TetrisBoardPiece param instead of using a TetrisPiece
		TetrisPiece *current_piece = tetris_board_piece_get_tetris_piece(self->current_piece);
		Point *centre_point = tetris_board_piece_get_location(self->current_piece);
		if (!tetris_board_is_piece_location_valid(self->board, current_piece, centre_point))
		{
			tetris_piece_rotate(tetris_board_piece_get_tetris_piece(self->current_piece), -rotations);
		}
	}
}

bool tetris_board_controller_can_spawn_piece(TetrisBoardController *self, TetrisPiece *piece)
{
	return tetris_board_is_piece_location_valid(self->board, piece, get_spawn_point(self));
}

bool tetris_board_is_current_piece(TetrisBoardController *self)
{
	return self->current_piece != NULL;
}

bool tetris_board_can_current_piece_move(TetrisBoardController *self, s8 x_offset, s8 y_offset)
{
	Point *old_point = tetris_board_piece_get_location(self->current_piece);
	Point *new_location = point_init(point_get_x(old_point) + x_offset, point_get_y(old_point) + y_offset);

	return tetris_board_is_piece_location_valid(self->board, tetris_board_piece_get_tetris_piece(self->current_piece), new_location);
}

void tetris_board_controller_draw(TetrisBoardController *self)
{
	TetrisPiece *current_piece = NULL;
	Point *current_location = NULL;

	if (self->current_piece != NULL)
	{
		current_piece = tetris_board_piece_get_tetris_piece(self->current_piece);
		current_location = tetris_board_piece_get_location(self->current_piece);
	}
	//ZZZ TODO Remove hardcoded values, seperate out display from board.
	tetris_board_draw(self->board, current_piece, current_location, 0, 0, 400, 240);
}












