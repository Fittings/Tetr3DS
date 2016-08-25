#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include "../include/game/tetris_controller.h"
#include "../include/game/game_board/tetris_board.h"



struct _TetrisController
{
	TetrisBoard *board;
};
typedef struct _TetrisController TetrisController;




TetrisController *tetris_controller_init()
{
	TetrisController *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->board = tetris_board_init(10, 20); //ZZZ TODO Fix this... TODO Maybe this init structure could be nicer in general...
		if (!self)
		{
			tetris_controller_free(self);
			return NULL;
		}
	}


	return self;
}


void tetris_controller_free(TetrisController *self)
{
	if (self)
	{
		if (self->board)
		{
			tetris_board_free(self->board);
		}

		free(self);
	}

}


void update_tetris_controller(TetrisController *self)
{

	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);

	tetris_board_draw(self->board, 0, 0, 320, 240);

	sf2d_end_frame();
	sf2d_swapbuffers();
}


bool tetris_controller_is_running(TetrisController *self)
{
	return true;
}
