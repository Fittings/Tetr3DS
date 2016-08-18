/**
 * @file application_controller.h
 * @author Cameron Milsom
 * @brief General state controller for the 3DS Application
 *
 * This controller handles the running of a 3DS application
 * The 3DS application should update this ApplicationController in the apt main loop.
 *
 * While 3DS Application is still updatable, is_running will return true
 */
#ifndef INCLUDE_APPLICATION_CONTROLLER_H_
#define INCLUDE_APPLICATION_CONTROLLER_H_

#include <stdbool.h>
#include "types.h"




/**
 * @brief The ApplicationController struct for general Tetris application handling.
 *
 * Handles the DS application various general states.
 * All functions should parse this controller
 * Any new specific game controllers, e.g various games mode controller or options should be handled here.
 */
typedef struct _ApplicationController ApplicationController;




/**
 * @brief Initialises the ApplicationController struct
 *
 * ApplicationController struct is used for handling 3DS state
 * @return An ApplicationController used for handling the 3DS application
 */
extern ApplicationController *application_controller_init();

/**
 * @brief Frees the ApplicationController struct
 *
 * Frees the ApplicationController struct.
 * This should always be called after the ApplicationController struct is no longer in use
 *
 * @param self The ApplicationController struct to reference
 */
extern void application_controller_free(ApplicationController *self);




/**
 * @brief Updates the 3DS application state.
 *
 * This controls the 3SD application state.
 * While @ref application_controller_is_running is true, update_controller will update.
 *
 * * @param self The ApplicationController struct to reference
 */
extern void update_application_controller(ApplicationController *self);

/**
 * @brief Returns if the 3DS application is still running
 *
 * Returns a bool, true if 3DS application is running, false if Tetris3DS is stopped.
 *
 * While Tetris3DS is_running, the application will still be update if @ref update_application_controller is called.
 * If Tetris3DS is_running is false, then the controller will not update and should be freed.
 *
 * @param self The ApplicationController struct to reference
 * @return A bool : True if the application is still running, otherwise false
 */
extern bool application_controller_is_running(ApplicationController *self);




#endif /* INCLUDE_APPLICATION_CONTROLLER_H_ */
