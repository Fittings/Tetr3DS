/**
 * @file tetris_timer.h
 * @author Cameron Milsom
 * @brief Represent the timing of the tetris game.
 *
 * TetrisTimer is used for updating tetris iterations.
 */
#ifndef INCLUDE_GAME_TETRIS_TIMER_H_
#define INCLUDE_GAME_TETRIS_TIMER_H_


#include <stdbool.h>
#include <3ds.h>


/**
 * @brief The Tetris Timer.
 *
 * Handles the current tetris board timings.
 */
typedef struct _TetrisTimer TetrisTimer;


/**
 * @brief Initialises the TetrisTimer struct.
 *
 * Initialises the TetrisTimer which handles tetris game state.
 *
 * @param start_time The time the TetrisTimer was created.x
 * @return The TetrisTimer struct
 */
extern TetrisTimer *tetris_timer_init(u64 start_time);

/**
 * @brief Frees the TetrisTimer struct.
 *
 * Frees the TetrisTimer struct.
 *
 * @param self The TetrisTimer struct to reference.
 */
extern void tetris_timer_free(TetrisTimer *self);

/**
 * @brief Checks if there is a new tetris timer iteration.
 *
 * Returns true if there is a new Tetris Iteration.
 *
 * @param self The TetrisTimer struct to reference.
 * @return true if there is a new Tetris Iteration.
 */
extern bool tetris_timer_is_new_iteration(TetrisTimer *self);

/**
 * @brief Partially increases the tetris iteration by a given percentage.
 *
 * Partially increases the current tetris iteration by a given percentage.
 *
 * @param self The TetrsTimer struct to reference.
 * @param reset_percentage The percentage to reset the current Tetris iteration by.
 */
extern void tetris_timer_current_iteration_reset(TetrisTimer *self, double reset_percentage);

/**
 * @brief Forces a new iteration in the TetrisTimer.
 *
 * Forces a new iteration in the TetrisTime. The current iteration will be reset.
 *
 * @param self The TetrisTimer struct to reference.
 */
extern void tetris_timer_new_iteration(TetrisTimer *self);





#endif
