#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include "../include/game/game_board/tetris_board.h"
//ZZZ TODO include this header





struct _TetrisBoard
{


};
typedef struct _TetrisBoard TetrisBoard;




TetrisBoard *tetris_board_init(int x_blocks, int y_blocks)
{
	TetrisBoard *self = malloc(sizeof *self);
	if (!self || x_blocks <= 0 || y_blocks <= 0)
	{
		return NULL;
	}

	{

	}


	return self;
}


void tetris_board_free(TetrisBoard *self)
{
	if (self)
	{
		free(self);
	}
}
