#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include "../include/game/tetris_controller.h"





struct _TetrisController
{
	//ZZZ TODO Scoreboard
	//ZZZ TODO Board
	//ZZ TODO Queue - pieces

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

	}


	return self;
}


void tetris_controller_free(TetrisController *self)
{
	if (self)
	{
		free(self);
	}
}


//ZZZ TODO Delete. Just to make sure things are going where we are going.
void bePretty(int i)
{
	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		sf2d_draw_rectangle_rotate(190, 160, 70, 60, RGBA8(0xFF, 0xFF, 0xFF, 0xFF), 3.0* i);
		sf2d_draw_rectangle(30, 100, 40, 60, RGBA8(0xFF, 0x00, 0xFF, 0xFF));
		sf2d_draw_rectangle(160-15 + cosf(i)*50.0f, 120-15 + sinf(i)*50.0f, 30, 30, RGBA8(0x00, 0xFF, 0xFF, 0xFF));
	sf2d_end_frame();

	sf2d_swapbuffers();
}
int i = 0;

void update_tetris_controller(TetrisController *self)
{
	i = i + 2;
	bePretty(i);
}




bool tetris_controller_is_running(TetrisController *self)
{
	return true;
}
