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
#include "../include/game/block/piece/tetris_piece.h"



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
 * @param width The width of the board in 'block' pieces.x
 * @param height the height of the board in 'block' pieces.
 * @return An TetrisBoard used for handling the 3DS application.
 */
extern TetrisBoard *tetris_board_init(int width, int height);

/**
 * @brief Frees the TetrisBoard struct
 *
 * Frees the TetrisBoard struct.
 * This should always be called after the TetrisBoard struct is no longer in use
 *
 * @param self The TetrisBoard struct to reference
 */
extern void tetris_board_free(TetrisBoard *self);


/**
 * @brief Renders the TetrisBoard
 *
 * Renders the TetrisBoard on the given input screen. At the location given.
 *
 * @param self The TetrisBoard struct to reference
 * @param x x coordinate of the top left corner of the board
 * @param y y coordinate of the top left corner of the board
 * @param width The width from the x co-ordinate. (Rightwards)
 * @param height The height from the y co-ordinate. (Downwards)
 */
extern void tetris_board_draw(TetrisBoard *self, int x, int y, int width, int height);




#endif
