#include "../include/game/iteration/tetris_timer.h"


#include <malloc.h>

//ZZZ TODO Remove these from globals and make part of the constructor.
#define G_QUEUE_SIZE 8
#define G_PIECE_SET TETRIS_SET_STANDARD



struct _TetrisTimer
{
	//Speed Settings
	u64 game_start_time;
	u64 last_board_update;
};



TetrisTimer *tetris_timer_init(u64 start_time)
{
	TetrisTimer *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->game_start_time = start_time;
		self->last_board_update = start_time;
	}

	return self;
}


void tetris_timer_free(TetrisTimer *self)
{
	if (self)
	{
		free(self);
	}
}


void tetris_timer_current_iteration_reset(TetrisTimer *self, s8 reset_percentage)
{

}



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
bool tetris_timer_is_new_iteration(TetrisTimer *self, s8 current_tetris_level)
{
	u64 update_difference_ms = osGetTime() - self->last_board_update;
	u64 current_iteration_delay = (1000 * (11 - current_tetris_level) * 0.05);

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
