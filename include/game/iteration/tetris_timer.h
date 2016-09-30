#ifndef INCLUDE_GAME_TETRIS_TIMER_H_
#define INCLUDE_GAME_TETRIS_TIMER_H_


#include <stdbool.h>
#include <3ds.h>



typedef struct _TetrisTimer TetrisTimer;




extern TetrisTimer *tetris_timer_init(u64 start_time);

extern void tetris_timer_free(TetrisTimer *self);

extern bool tetris_timer_is_new_iteration(TetrisTimer *self);

extern void tetris_timer_current_iteration_reset(TetrisTimer *self, double reset_percentage);

extern void tetris_timer_new_iteration(TetrisTimer *self);





#endif
