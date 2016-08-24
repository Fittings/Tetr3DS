#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include "../include/game/block/tetris_block.h"





struct _TetrisBlock
{
	u32 creator_id;

	Colour colour;
};
typedef struct _TetrisBlock TetrisBlock;


TetrisBlock *tetris_block_init(u32 creator_id, Colour colour)
{
	TetrisBlock *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->creator_id = creator_id;

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

u32 tetris_block_get_creator_id(TetrisBlock *self)
{
	return self->creator_id;
}

//ZZZ TODO This needs to be done correctly, once we have implemented colours.
void tetris_block_draw(TetrisBlock *self, int x, int y, int length)
{
	//Draw a black border
	sf2d_draw_rectangle(x, y, length, length, RGBA8(0x00, 0x00, 0x00, 0xFF));

	//Draw the square
	sf2d_draw_rectangle(x+1, y+1, length-1, length-1, getColourRGBAValue(LIGHT_BLUE, 0x00));
}


