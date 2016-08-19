/**
 * @file tetris_board.h
 * @author Cameron Milsom
 * @brief Represents and validates tetris board state.
 *
 * Represents the current board state.
 * Controls piece input/removal and maintains board integrity.
 */
#ifndef INCLUDE_GAME_TETRIS_BOARD_H_
#define INCLUDE_GAME_TETRIS_BOARD_H_


#include <stdbool.h>



/**
 * @brief The Tetris Board.
 *
 * Handles input from external controllers and validates.
 */
typedef struct _TetrisBoard TetrisBoard;



/**
 * @brief Initialises the TetrisBoard struct
 *
 * TetrisBoard struct is used for holding tetris pieces.
 * TetrisBoard is of size: (x_blocks by y_blocks).
 *
 * @param x_blocks The width of the board in 'block' pieces.x
 * @param y_blocks the height of the board in 'block' pieces.
 * @return An TetrisController used for handling the 3DS application.
 */
extern TetrisBoard *tetris_board_init(int x_blocks, int y_blocks);

/**
 * @brief Frees the TetrisBoard struct
 *
 * Frees the TetrisBoard struct.
 * This should always be called after the TetrisBoard struct is no longer in use
 *
 * @param self The TetrisBoard struct to reference
 */
extern void tetris_board_free(TetrisBoard *self);




#endif
