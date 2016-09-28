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

#include "../../include/game/game_board/tetris_board_controller.h"
#include "../include/game/configurations/piece_set.h"
#include "../include/game/block_generator/piece_generator.h"
#include "../../include/general/region/region.h"


//ZZZ TODO Remove these from globals and make part of the constructor.
#define G_QUEUE_SIZE 8
#define G_PIECE_SET TETRIS_SET_STANDARD



struct _TetrisController
{
	TetrisBoardController *board_controller;
	PieceGenerator *piece_generator;

	//Game Settings
	bool is_running;
	u8 level;

	//Speed Settings
	u64 game_start_time;
	u64 last_board_update;


};
typedef struct _TetrisController TetrisController;





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

	if (tetris_board_is_current_piece(self->board_controller))
	{
		//Attempt to make piece fall.
		if (tetris_board_can_current_piece_move(self->board_controller, 0, 1))
		{
			tetris_board_controller_move_current_piece(self->board_controller, 0, 1);
		}
		else
		{
			tetris_board_controller_commit_piece(self->board_controller);
			tetris_board_controller_remove_completed_rows(self->board_controller);
		}
	}
	else
	{
		//Attempt to place highest priority in piece queue onto board.
		TetrisPiece *next_piece = piece_generator_get_next(self->piece_generator);
		if (tetris_board_controller_can_spawn_piece(self->board_controller, next_piece))
		{
			tetris_board_controller_spawn_piece(self->board_controller, next_piece);
		}
		else
		{
			//self->is_running = false;
			return;
		}
	}
}

static void draw_tetris_game(TetrisController *self)
{
	sf2d_start_frame(GFX_TOP, GFX_LEFT);
	{
		tetris_board_controller_draw(self->board_controller);
	}
	sf2d_end_frame();


	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
	{

	}
	sf2d_end_frame();

	sf2d_swapbuffers();
}


static void handleInput(TetrisController *self)
{
	//ZZZ TODO Less primitive, standardise movement into a seperate function.
	switch (get_game_input())
	{
	case NO_COMMAND: return;
	case MOVE_UP:
		tetris_board_controller_move_current_piece(self->board_controller, 0, -1);
		break;
	case MOVE_DOWN:
		tetris_board_controller_move_current_piece(self->board_controller, 0, 1);
		break;
	case MOVE_LEFT:
		tetris_board_controller_move_current_piece(self->board_controller, -1, 0);
		break;
	case MOVE_RIGHT:
		tetris_board_controller_move_current_piece(self->board_controller, 1, 0);
		break;
	case DROP_INSTANTLY: //B
		tetris_board_controller_drop_current_piece(self->board_controller);
		break;
	case ROTATE_CLOCKWISE: //X
		tetris_board_controller_rotate_current_piece(self->board_controller, 1);
		break;
	case ROTATE_ANTICLOCKWISE: //Y
		tetris_board_controller_rotate_current_piece(self->board_controller, 3);
		break;
	case STORE_BLOCK:
		break;
	case DO_PAUSE:
		self->is_running = false;
		break;
	}
}


void update_tetris_controller(TetrisController *self)
{
	draw_tetris_game(self);

	handleInput(self);

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
		TetrisBoard *board = tetris_board_init(10, 20); //ZZZ TODO Make this a construction setting.
		self->board_controller = tetris_board_controller_init(board, region_init(point_init(0, 0), 400, 240));
		self->piece_generator = piece_generator_init(G_QUEUE_SIZE, G_PIECE_SET); //ZZZ TODO Fix this, no global pls
		self->is_running = true; //ZZZ TODO Move this

		//ZZZ TODO Move this out of here.
		self->game_start_time = osGetTime();
		self->last_board_update = osGetTime();
		self->level = 5;
	}


	return self;
}


void tetris_controller_free(TetrisController *self)
{
	if (self)
	{
		tetris_board_controller_free(self->board_controller);

		free(self);
	}

}


bool tetris_controller_is_running(TetrisController *self)
{
	return self->is_running;
}
