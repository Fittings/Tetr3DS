#include <malloc.h>
#include <stdbool.h>
#include "../include/game/tetris_controller.h"





struct _TetrisController
{

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




static void handle_menu(TetrisController *self)
{

}

static void handle_game(TetrisController *self)
{

}

static void handle_title(TetrisController *self)
{

}



void update_tetris_controller(TetrisController *self)
{

}




bool tetris_controller_is_running(TetrisController *self)
{
	return false;
}
