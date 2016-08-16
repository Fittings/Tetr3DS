/*
 * tetris_controller.h
 *
 *  Created on: 16 Aug 2016
 *      Author: cmilsom
 */

#ifndef INCLUDE_TETRIS_CONTROLLER_H_
#define INCLUDE_TETRIS_CONTROLLER_H_

#include "types.h"


struct _TetrisController
{
	ExternalState flag_mode;
};
typedef struct _TetrisController *TetrisController;

/* Memory Management */
extern TetrisController tetris_controller_init();
extern void tetris_controller_free(TetrisController self);

/* Main Control */
extern void tetris_controller_handle_state(TetrisController self);
extern void tetris_controller_handle_title(TetrisController self);
extern void tetris_controller_handle_menu(TetrisController self);
extern void tetris_controller_handle_game(TetrisController self);



#endif /* INCLUDE_TETRIS_CONTROLLER_H_ */
