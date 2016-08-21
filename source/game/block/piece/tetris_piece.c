#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include "../include/game/block/piece/tetris_piece.h"




struct _TetrisPiece
{
	u8 centre_x;
	u8 centre_y;

	TetrisBlock ***piece_array; //ZZZ TODO Is this really a triple pointer situation?
};
typedef struct _TetrisPiece TetrisPiece;


//ZZZ TODO Use an enum to define this array pieces
TetrisPiece *tetris_piece_init(TetrisBlock ***piece_array, u8 width, u8 height)
{
	TetrisPiece *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->piece_array = piece_array;

		for (int w=0; w < width; w++)
		{
			for (int h=0; h < height; h++)
			{
				if (tetris_block_get_creator_id(self->piece_array[w][h]) == 0) //ZZZ TODO Compare to an enum for block creators
				{
					self->centre_x = w;
					self->centre_y = h;
				}
			}
		}
	}

	return self;
}


void tetris_piece_free(TetrisPiece *self)
{
	if (self)
	{
		free(self);
	}
}


