#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include <time.h>
#include "../include/game/tetris_controller.h"
#include "../include/game/game_board/tetris_board.h"
#include "../include/game/input/tetris_input.h"
#include "../include/game/input/tetris_command.h"




struct _TetrisController
{
	TetrisBoard *board;

	clock_t game_start_time;
	clock_t last_board_update;
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

static void draw_tetris_game(TetrisController *self)
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
	//ZZZ TODO FInished
	//timeStruct->tm_sec
	CLOCKS_PER_SEC;

    clock_t t1, t2;

    t1 = clock();


    int i;

    for(i = 0; i < CLOCKS_PER_SEC; i++)
    {
        int x = 90;
    }

    t2 = clock();

    //float diff = ((float)(t2 - t1) / float(CLOCKS_PER_SEC) ) * 1000;


    return false;
}


void update_tetris_controller(TetrisController *self)
{
	handleInput(self);
	draw_tetris_game(self);

	if (is_new_tetris_iteration(self))
	{
		//updateBoard
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
		self->game_start_time = clock();
		self->last_board_update = clock();
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
