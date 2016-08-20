#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include "../include/game/game_board/tetris_board.h"
#include "../include/game/block/tetris_block.h"






struct _TetrisBoard
{
	//ZZZ TODO Create an ID enum system

	int width;
	int height;

	TetrisBlock ***block_array; //ZZZ TODO Is this really a triple pointer situation?

};
typedef struct _TetrisBoard TetrisBoard;




TetrisBoard *tetris_board_init(int width, int height)
{
	TetrisBoard *self = malloc(sizeof *self);
	if (!self || width <= 0 || height <= 0)
	{
		return NULL;
	}

	{
		self->width = width;
		self->height = height;

		self->block_array = malloc(width * sizeof(void *));
		for (int w=0; w < width; w++)
		{
			self->block_array[w] = malloc(height * tetris_block_sizeof());
			for (int h=0; h < height; h++)
			{
				self->block_array[w][h] = tetris_block_init(1); //ZZZ TODO use an enum ID here.
			}
		}
	}


	return self;
}

static void free_block_array(TetrisBoard *self)
{
	for (int w=0; w < self->width; w++)
	{
		for (int h=0; h < self->height; h++)
		{
			tetris_block_free(self->block_array[w][h]); //Frees the internal TetrisBlock
		}
		free(self->block_array[w]); //Frees the sub-array
	}
	free(self->block_array); //Frees the outside array
}


void tetris_board_free(TetrisBoard *self)
{
	if (self)
	{
		free_block_array(self);
		free(self);
	}
}



