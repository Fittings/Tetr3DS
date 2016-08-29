#include "../include/game/input/tetris_input.h"
#include <3ds.h>



TetrisCommand get_game_input()
{
	hidScanInput();
	//u32 kDown = hidKeysDown();

	return NO_COMMAND;
}

TetrisCommand get_paused_input()
{
	return DO_PAUSE;
}




