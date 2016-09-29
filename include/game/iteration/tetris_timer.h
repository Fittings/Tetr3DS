#ifndef INCLUDE_GAME_TETRIS_TIMER_H_
#define INCLUDE_GAME_TETRIS_TIMER_H_


#include <stdbool.h>
#include <3ds.h>



typedef struct _TetrisTimer TetrisTimer;




extern TetrisTimer *tetris_timer_init(u64 start_time);

extern void tetris_timer_free(TetrisTimer *self);

extern bool tetris_timer_is_new_iteration(TetrisTimer *self, s8 current_tetris_level);





#endif
