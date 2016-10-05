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
		//ZZZ TODO There is something messed up here. If a piece drops instantly and calls this its fine,
		//ZZZ TODO But if it falls we get some messed up behaviour. What's the difference...
		//free(self);
	}
}


TetrisBlock *tetris_block_deep_copy(TetrisBlock *self)
{
	return tetris_block_init(self->type, self->colour);
}


BlockType tetris_block_get_type(TetrisBlock *self)
{
	return self->type;
}

Colour tetris_block_get_colour(TetrisBlock *self)
{
	return self->colour;
}


void tetris_block_draw(TetrisBlock *self, s16 x, s16 y, s16 length, s8 opacity)
{

	if (self->colour != INVISIBLE)
	{
		//Draw a black border
		sf2d_draw_rectangle(x, y, length, length, RGBA8(0x00, 0x00, 0x00, 0xFF));

		//Draw the square
		sf2d_draw_rectangle(x+1, y+1, length-1, length-1, getColourRGBAValue(self->colour, opacity));
	}
}


