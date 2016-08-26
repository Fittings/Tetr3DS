#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include "../include/game/block/piece/tetris_piece.h"



struct _TetrisPiece
{
	TetrisBlock ***piece_array;
	u16 width;
	u16 height;

	Point *centre_block;
};
typedef struct _TetrisPiece TetrisPiece;



TetrisPiece *tetris_piece_init(TetrisBlock ***piece_array, Point *centre_block, u16 width, u16 height)
{
	if ( (point_get_x(centre_block) >= width) && (point_get_y(centre_block) >= height))
	{
		//Invalid parameters, centre_block must be inside the piece_array.
		return NULL;
	}

	TetrisPiece *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->piece_array = piece_array;
		self->width = width;
		self->height = height;

		self->centre_block = centre_block;
	}

	return self;
}


void tetris_piece_free(TetrisPiece *self)
{
	if (self)
	{
		point_free(self->centre_block);
		free(self);
	}
}


