#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include "../include/game/block/tetris_block.h"





struct _TetrisBlock
{
	BlockType type;

	Colour colour;
};
typedef struct _TetrisBlock TetrisBlock;


TetrisBlock *tetris_block_init(BlockType type, Colour colour)
{
	TetrisBlock *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->type = type;

		self->colour = colour;
	}

	return self;
}


void tetris_block_free(TetrisBlock *self)
{
	if (self)
	{
		free(self);
	}
}


int tetris_block_sizeof()
{
	return sizeof(TetrisBlock);
}


BlockType tetris_block_get_type(TetrisBlock *self)
{
	return self->type;
}


void tetris_block_draw(TetrisBlock *self, u16 x, u16 y, u16 length)
{
	if (self->type != BLOCK_TYPE_EMPTY)
	{
		//Draw a black border
		sf2d_draw_rectangle(x, y, length, length, RGBA8(0x00, 0x00, 0x00, 0xFF));

		//Draw the square
		sf2d_draw_rectangle(x+1, y+1, length-1, length-1, getColourRGBAValue(self->colour, 0xFF));
	}
}


