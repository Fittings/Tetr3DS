#include "../include/game/tetris_controller.h"
#include "../include/game/game_board/tetris_board.h"
#include "../include/game/input/tetris_input.h"
#include "../include/game/input/tetris_command.h"
#include "../include/game/configurations/pieces/pieces.h"
#include "FreeSans_ttf.h" //ZZZ TODO Remove this
#include <sftd.h>
#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>






struct _TetrisController
{
	TetrisBoard *board;
	bool is_running;

	u8 level;

	//Speed Settings
	u64 game_start_time;
	u64 last_board_update;

	sftd_font *font;
};
typedef struct _TetrisController TetrisController;





static void handleInput(TetrisController *self)
{
	//ZZZ TODO Less primitive, standardise movement into a seperate function.
	switch (get_game_input())
	{
	case NO_COMMAND: return;
	case MOVE_UP:
		tetris_board_move_current_piece(self->board, 0, -1);
		break;
	case MOVE_DOWN:
		tetris_board_move_current_piece(self->board, 0, 1);
		break;
	case MOVE_LEFT:
		tetris_board_move_current_piece(self->board, -1, 0);
		break;
	case MOVE_RIGHT:
		tetris_board_move_current_piece(self->board, 1, 0);
		break;
	case DROP_INSTANTLY:
		break;
	case ROTATE_CLOCKWISE:
		break;
	case ROTATE_ANTICLOCKWISE:
		break;
	case STORE_BLOCK:
		break;
	case DO_PAUSE:
		self->is_running = false;
		break;
	}
}



//ZZZ TODO Delete
static void draw_test()
{
	sf2d_start_frame(GFX_TOP, GFX_LEFT);
	{
		sf2d_draw_rectangle(0, 20, 360, 10, RGBA8(0x00, 0x00, 0x00, 0xFF));
		sf2d_draw_rectangle(0, 20, sf2d_get_fps() * 6, 10, RGBA8(0xFF, 0x00, 0x00, 0xCC));
	}
	sf2d_end_frame();


	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
	{
		//sf2d_draw_rectangle(0, 20, 360, 10, RGBA8(0x00, 0x00, 0x00, 0xFF));
		//sf2d_draw_rectangle(0, 20, sf2d_get_fps() * 6, 10, RGBA8(0xFF, 0x00, 0x00, 0xCC));

	}
	sf2d_end_frame();

	sf2d_swapbuffers();
}

static bool is_new_tetris_iteration(TetrisController *self)
{
	/*
	actualLevel      iterationDelay [seconds]
	                (rounded to nearest 0.05)
	============    =========================
	     1                 0.50
	     2                 0.45
	     3                 0.40
	     4                 0.35
	     5                 0.30
	     6                 0.25
	     7                 0.20
	     8                 0.15
	     9                 0.10
	    10                 0.05
	*/
	u64 update_difference_ms = osGetTime() - self->last_board_update;
	u64 current_iteration_delay = (1000 * (11 - self->level) * 0.05);

	if (update_difference_ms >= current_iteration_delay)
	{
		self->last_board_update = osGetTime();
		return true;
	}
	else
	{
		return false;
	}
}

static void do_new_iteration(TetrisController *self)
{
	if (tetris_board_set_current_piece(self->board, create_T())) //ZZZ TODO Replace create, from get from queue.
	{

	}

	if (!tetris_board_move_current_piece(self->board, 0, 1))
	{
		tetris_board_concrete_current_piece(self->board);
	}
}

static void draw_tetris_game(TetrisController *self)
{
	sf2d_start_frame(GFX_TOP, GFX_LEFT);
	{
		tetris_board_draw(self->board, 0, 0, 400, 240);
	}
	sf2d_end_frame();


	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
	{
		sftd_draw_textf(self->font, 10, 10, RGBA8(0, 255, 0, 255), 20, "FPS %f", sf2d_get_fps());
	}
	sf2d_end_frame();

	sf2d_swapbuffers();
}


void update_tetris_controller(TetrisController *self)
{
	handleInput(self);
	draw_tetris_game(self);

	if (is_new_tetris_iteration(self))
	{
		do_new_iteration(self);
	}

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

		self->is_running = true; //ZZZ TODO Move this

		//ZZZ TODO Move this out of here.
		self->game_start_time = osGetTime();
		self->last_board_update = osGetTime();
		self->level = 5;

		//ZZZ TODO Move to a text specific class.
		self->font = sftd_load_font_mem(FreeSans_ttf, FreeSans_ttf_size);
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
	return self->is_running;
}
