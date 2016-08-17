/**
 * @file tetris_controller.h
 * @author Cameron Milsom
 * @brief General state controller for Tetris3DS
 *
 * This controller handles the running of Tetris3DS
 * The 3DS application should update this TetrisController in the apt main loop.
 *
 * While Tetris3DS is still updatable, is_running will return true
 */
#ifndef INCLUDE_TETRIS_CONTROLLER_H_
#define INCLUDE_TETRIS_CONTROLLER_H_

#include <stdbool.h>
#include "types.h"




/**
 * @brief The TetrisController struct for general Tetris application handling.
 *
 * Handles the Tetris3DS application various general states.
 * All functions should parse this controller
 * Any new specific gamae controllers, e.g various games mode controller or options should be handled here.
 */
typedef struct _TetrisController TetrisController;




/**
 * @brief Initialises the TetrisController struct
 *
 * TetrisController struct is used for handling Tetris3DS state
 * @return A TetrisController used for handling the Tetris3DS application
 */
extern TetrisController *tetris_controller_init();

/**
 * @brief Frees the TetrisController struct
 *
 * Frees the TetrisController struct.
 * This should always be called after the TetrisController struct is no longer in use
 *
 * @param self The TetrisController struct to reference
 */
extern void tetris_controller_free(TetrisController *self);




/**
 * @brief Updates the Tetris3DS application state.
 *
 * This controls the Tetris3DS application state.
 * While @ref is_running is true, update_controller will update.
 *
 * * @param self The TetrisController struct to reference
 */
extern void update_controller(TetrisController *self);

/**
 * @brief Returns if the Tetris3DS application is still running
 *
 * Returns a bool, true if Tetris3DS is running, false if Tetris3DS is stopped.
 *
 * While Tetris3DS is_running, the application will still be update if @ref update_controller is called.
 * If Tetris3DS is_running is false, then the controller will not update and should be freed.
 *
 * @param self The TetrisController struct to reference
 * @return A bool : True if the application is still running, otherwise false
 */
extern bool is_running(TetrisController *self);




#endif /* INCLUDE_TETRIS_CONTROLLER_H_ */
