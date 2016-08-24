/**
 * @file tetris_input.h
 * @author Cameron Milsom
 * @brief Input handler for Tetris Game
 *
 * This is an input handler for the tetris game.
 * Run this on any update in the TetrisController (@ref tetris_controller.h)
 * and this will return the TetrisCommand enum. (@ref tetris_command.h)
 */
#ifndef INCLUDE_GAME_TETRIS_INPUT_H_
#define INCLUDE_GAME_TETRIS_INPUT_H_

#include "../include/game/input/tetris_command.h"
#include "../include/game/tetris_game_state.h"



/**
 * @brief Checks and handles the input during a Tetris Game.
 *
 * Handles user input and converts it to a TetrisCommand for the controller to handle.
 * Should be called during a TetrisController update.
 * (@ref tetris_controller.h)
 *
 * Keybinding can be updated in a user-file
 *
 * @return A TetrisCommand enum. This can be handled by the controller
 */
extern TetrisCommand get_game_input();


/**
 * @brief Checks and handles the input during a Tetris Game Pause Screen.
 *
 * Handles user input and converts it to a TetrisCommand for the controller to handle.
 * Should be called during a TetrisController update.
 * (@ref tetris_controller.h)
 *

 * @return A TetrisCommand enum. This can be handled by the controller
 */
extern TetrisCommand get_paused_input();
//ZZZ TODO Create a seperate Pause enum. This should be standard across.
//ZZZ TODO Maybe this should also be moved to a seperate location, we can defer all paused states to a paused controller.



#endif
