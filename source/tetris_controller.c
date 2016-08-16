/*
 * TetrisController.c
 *
 * Main Controller for the game. Handles various state controlelrs such as Title menu controllers
 * and Gameplay controllers.
 *
 *  Created on: 16 Aug 2016
 *      Author: Cameron Milsom
 */

#include <malloc.h>
#include "tetris_controller.h"


TetrisController tetris_controller_init()
{
	TetrisController self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	self->flag_mode = GAME_STATE;

	return self;
}


void tetris_controller_free(TetrisController self)
{
	if (self)
	{
		free(self);
	}
}


void tetris_controller_handle_state(TetrisController self)
{
	switch(self->flag_mode)
	{
		case TITLE_SCREEN: 	//TitleController
			tetris_controller_handle_title(self);
			break;
		case MAIN_MENU:		//MainMenuController
			tetris_controller_handle_menu(self);
			break;
		case GAME_STATE:		//GameController
			tetris_controller_handle_game(self);
			break;
		case QUIT_APP:
			break; //ZZZ TODO
	}
}


void tetris_controller_handle_menu(TetrisController self)
{
	//ZZZ TODO
}

void tetris_controller_handle_game(TetrisController self)
{
	//ZZZ TODO
}
