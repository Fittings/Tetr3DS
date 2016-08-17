#include <malloc.h>
#include "tetris_controller.h"




struct _TetrisController
{
	ExternalState flag_mode;
};
typedef struct _TetrisController TetrisController;




TetrisController *tetris_controller_init()
{
	TetrisController *self = malloc(sizeof *self);

	{
		self->flag_mode = GAME_STATE;
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
	self->flag_mode = QUIT_APP;
}

static void handle_game(TetrisController *self)
{
	self->flag_mode = QUIT_APP;
}

static void handle_title(TetrisController *self)
{
	self->flag_mode = QUIT_APP;
}



void update_controller(TetrisController *self)
{
	switch(self->flag_mode)
	{
		case TITLE_SCREEN:
			handle_title(self);
			break;
		case MAIN_MENU:
			handle_menu(self);
			break;
		case GAME_STATE:
			handle_game(self);
			break;
		case QUIT_APP:
			break;
	}
}




bool is_running(TetrisController *self)
{
	return !(self->flag_mode == QUIT_APP);
}
