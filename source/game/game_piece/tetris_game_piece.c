#include "../include/game/game_piece/tetris_game_piece.h"

#include <malloc.h>
#include "../include/game/block/point.h"


struct _TetrisGamePiece
{
	TetrisPiece *current_piece;
	Point *current_centre_location;

	TetrisPiece *future_piece;
	u16 future_y_offset;
};




TetrisGamePiece *tetris_game_piece_init(TetrisPiece *current_piece, Point *current_centre_location)
{
	TetrisGamePiece *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->current_piece = current_piece;


	}

	return self;
}


bool tetris_game_piece_move_current_piece(TetrisBoard *self, u16 blocks_down, u16 blocks_right)
{
	return false;
}

bool tetris_game_piece_rotate_current_piece(TetrisBoard *self, u8 rotations)
{
	return false;
}


TetrisPiece *tetris_game_piece_get_current_piece(TetrisGamePiece *self)
{
	return self->current_piece;
}
