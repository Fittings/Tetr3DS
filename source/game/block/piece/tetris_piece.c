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
		return NULL; //Invalid parameters, centre_block must be inside the piece_array.
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


void tetris_piece_draw(TetrisPiece *self, u16 pixel_x, u16 pixel_y, u16 block_size)
{
	u16 x_offset = pixel_x - point_get_x(self->centre_block);
	u16 y_offset = pixel_y - point_get_y(self->centre_block);

	for (int w=0; w < self->width; w++)
	{
		for (int h=0; h < self->height; h++)
		{
			tetris_block_draw(self->piece_array[w][h], w + x_offset, h + y_offset, block_size);
		}

	}
}

