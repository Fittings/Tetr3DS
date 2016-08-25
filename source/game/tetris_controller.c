#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include "../include/game/tetris_controller.h"
#include "../include/game/game_board/tetris_board.h"
#include "../include/game/input/tetris_input.h"
#include "../include/game/input/tetris_command.h"




struct _TetrisController
{
	TetrisBoard *board;
};
typedef struct _TetrisController TetrisController;





static void handleInput(TetrisController *self)
{
	switch (get_game_input())
	{
	case MOVE_UP:
	case MOVE_DOWN:
	case MOVE_LEFT:
	case MOVE_RIGHT:
	case DROP_INSTANTLY:
	case ROTATE_CLOCKWISE:
	case ROTATE_ANTICLOCKWISE:
	case STORE_BLOCK:
	case DO_PAUSE: break;
	}
}

static void drawTetrisGame(TetrisController *self)
{
	sf2d_start_frame(GFX_TOP, GFX_LEFT);
	{
		tetris_board_draw(self->board, 0, 0, 400, 240);
	}
	sf2d_end_frame();


	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
	{
		sf2d_draw_rectangle(0, 20, 360, 10, RGBA8(0x00, 0x00, 0x00, 0xFF));
		sf2d_draw_rectangle(0, 20, sf2d_get_fps() * 6, 10, RGBA8(0xFF, 0x00, 0x00, 0xCC));
	}
	sf2d_end_frame();

	sf2d_swapbuffers();

}

void update_tetris_controller(TetrisController *self)
{
	handleInput(self);

	drawTetrisGame(self);
}


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


bool tetris_controller_is_running(TetrisController *self)
{
	return true;
}
