#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include "../include/game/block/piece/tetris_piece.h"
#include "../include/utility/array_utility.h"



struct _TetrisPiece
{
	TetrisBlock ***block_array;
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
		self->block_array = piece_array;
		self->width = width;
		self->height = height;

		self->centre_block = centre_block;
	}

	return self;
}


void tetris_piece_shallow_free(TetrisPiece *self)
{
	if (self)
	{
		point_free(self->centre_block);
		free(self);
	}
}

void tetris_piece_free(TetrisPiece *self)
{
	if (self)
	{
		for (int x=0; x < self->width; x++)
		{
			for (int y=0; y < self->height; y++)
			{
				tetris_block_free(self->block_array[x][y]);
			}
		}

		point_free(self->centre_block);
		free(self);
	}
}


void tetris_piece_draw(TetrisPiece *self, u16 pixel_x, u16 pixel_y, u16 block_size)
{
	for (int w=0; w < self->width; w++)
	{
		for (int h=0; h < self->height; h++)
		{
			int block_x = pixel_x + ( (w-point_get_x(self->centre_block)) * block_size);
			int block_y = pixel_y + ( (h-point_get_y(self->centre_block)) * block_size);
			tetris_block_draw(self->block_array[w][h], block_x , block_y, block_size);
		}
	}
}

Point *tetris_piece_get_point(TetrisPiece *self)
{
	return self->centre_block;
}

TetrisBlock ***tetris_piece_get_array(TetrisPiece *self)
{
	return self->block_array;
}

u16 tetris_piece_get_width(TetrisPiece *self)
{
	return self->width;
}

u16 tetris_piece_get_height(TetrisPiece *self)
{
	return self->height;
}


void tetris_piece_rotate(TetrisPiece *self, int clockwise_90_rotation_count)
{
	for (int i=0; i < clockwise_90_rotation_count; i++)
	{
		self->block_array = rotate_2d_array(self->block_array);
		//point_init(point_get_y(self->centre_block), point_get_x(self->centre_block));
	}



}

