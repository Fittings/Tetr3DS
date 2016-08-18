/**
 * @file tetris_controller.h
 * @author Cameron Milsom
 * @brief Game State Controller for Tetris3DS
 *
 * This controller handles the running of a 3DS application
 * The 3DS application should update this TetrisController in the apt main loop.
 *
 * While 3DS Application is still updatable, is_running will return true
 */
#ifndef INCLUDE_GAME_TETRIS_CONTROLLER_H_
#define INCLUDE_GAME_TETRIS_CONTROLLER_H_


#include <stdbool.h>



/**
 * @brief The TetrisController struct for general Tetris application handling.
 *
 * Handles the DS application various general states.
 * All functions should parse this controller
 * Any new specific game controllers, e.g various games mode controller or options should be handled here.
 */
typedef struct _TetrisController TetrisController;




/**
 * @brief Initialises the TetrisController struct
 *
 * TetrisController struct is used for handling 3DS state
 * @return An TetrisController used for handling the 3DS application
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
 * @brief Updates the 3DS application state.
 *
 * This controls the Tetris game application state.
 * While @ref tetris_controller_is_running is true, @ref update_tetris_controller will update.
 *
 * * @param self The TetrisController struct to reference
 */
extern void update_tetris_controller(TetrisController *self);

/**
 * @brief Returns if the Tetris game is still running
 *
 * Returns a bool, true if Tetris game is running, false if game is stopped.
 *
 * While the tetris game is_running, the game will still be updated if @ref tetris_controller_is_running is called.
 * If is_running is false, then the controller will not update and should be freed.
 *
 * @param self The TetrisController struct to reference
 * @return A bool : True if the application is still running, otherwise false
 */
extern bool tetris_controller_is_running(TetrisController *self);




#endif /* INCLUDE_GAME_TETRIS_CONTROLLER_H_ */
