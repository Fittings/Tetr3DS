#include <malloc.h>
#include <3ds.h>
#include <sf2d.h>
#include "../include/application_controller.h"
#include "../include/game/tetris_controller.h"


#define CONFIG_3D_SLIDERSTATE (*(float *)0x1FF81080)

struct _ApplicationController
{
	ExternalState flag_mode;

	TetrisController *tetris_controller;
};
typedef struct _ApplicationController ApplicationController;




ApplicationController *application_controller_init()
{
	ApplicationController *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->flag_mode = GAME_STATE;

		self->tetris_controller = tetris_controller_init();
	}


	return self;
}


void application_controller_free(ApplicationController *self)
{
	if (self)
	{
		free(self);
	}
}




static void update_menu(ApplicationController *self)
{
	self->flag_mode = QUIT_APP;
}


static void update_game(ApplicationController *self)
{
	/* Start the game, if not loaded */



	if (tetris_controller_is_running(self->tetris_controller))
	{
		update_tetris_controller(self->tetris_controller);

	}
	else
	{
		//tetris_controller_free(self->tetris_controller);
		//self->flag_mode = MAIN_MENU;
	}





}

static void update_title(ApplicationController *self)
{
	self->flag_mode = QUIT_APP;
}


void update_application_controller(ApplicationController *self)
{
	switch(self->flag_mode)
	{
		case TITLE_SCREEN:
			update_title(self);
			break;
		case MAIN_MENU:
			update_menu(self);
			break;
		case GAME_STATE:
			update_game(self);
			break;
		case QUIT_APP:
			break;
	}
}




bool application_controller_is_running(ApplicationController *self)
{
	return !(self->flag_mode == QUIT_APP);
}

