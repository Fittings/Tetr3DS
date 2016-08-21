#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include "../include/game/block/tetris_block.h"





struct _TetrisBlock
{
	//ZZZ TODO Colour
	u32 creator_id;
};
typedef struct _TetrisBlock TetrisBlock;


TetrisBlock *tetris_block_init(u32 creator_id)
{
	TetrisBlock *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->creator_id = creator_id;
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


