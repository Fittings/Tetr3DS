#include "../include/game/input/tetris_input.h"
#include <3ds.h>



TetrisCommand get_game_input()
{
	hidScanInput();

	u32 kHeld = hidKeysHeld();
	u32 kDown = hidKeysDown();
		//Check key_presses
	if (kDown & KEY_A)
	{ //A

	}
	else if (kDown & KEY_B)
	{ //B
		return DROP_INSTANTLY;
	}
	else if (kDown & KEY_X)
	{ //X
		return ROTATE_CLOCKWISE;
	}
	else if (kHeld& KEY_Y) //ZZZ TODO Rate Limit bby
	{ //Y
		return ROTATE_ANTICLOCKWISE;
	}
	else if (kDown & KEY_UP)
	{ //up
		return MOVE_UP; //ZZZ TODO Testing: Don't actually do this...
	}
	else if (kDown & KEY_DOWN)
	{ //down
		return MOVE_DOWN;
	}
	else if (kDown & KEY_LEFT)
	{ //left
		return MOVE_LEFT;
	}
	else if (kDown & KEY_RIGHT)
	{ //right
		return MOVE_RIGHT;
	}
	else if (kDown & KEY_START)
	{ //start
		return DO_PAUSE;
	}
	else if (kDown & KEY_SELECT)
	{
		return NO_COMMAND;
	}


	return NO_COMMAND;
}

TetrisCommand get_paused_input()
{
	return DO_PAUSE;
}
