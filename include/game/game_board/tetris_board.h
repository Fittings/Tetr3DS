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


/**
 * @brief Sets the current piece on the board.
 *
 * Sets the current piece on the board, if there isn't already a TetrisPiece.
 * This is the piece that is controller by the user.
 *
 * @param self The TetrisBoard struct to reference
 * @param piece The TetrisPiece to place on the board.
 */
extern bool tetris_board_set_current_piece(TetrisBoard *self, TetrisPiece *piece);


/**
 * @brief Gets the current piece on the board.
 *
 * Returns a TetrisPiece that represents the current piece on the board.
 * This piece is in control by the user.
 *
 * @param self The TetrisBoard struct to reference
 * @return The current TetrisPiece on the board.
 */
extern TetrisPiece *tetris_board_get_current_piece(TetrisBoard *self);


/**
 * @brief Sets the current piece into the board and removes the current piece
 *
 * The current piece becomes a set of blocks in the board.
 * The current piece is reset back to NULL.
 *
 * @param self The TetrisBoard struct to reference.
 */
extern void tetris_board_concrete_current_piece(TetrisBoard *self);

/**
 * @brief Moves the current piece on the board by the parameters.
 *
 * Moves the current piece by the parameters.
 * Returns a bool if Succeeded or Failed
 *
 * @param self The TetrisBoard struct to reference.
 * @param blocks_down The amount of blocks on the board to move the piece down.
 * @param blocks_right The amount of blocks on the board to move the piece right.
 * @return A bool representing if the piece was successfully moved.
 */
extern bool tetris_board_move_current_piece(TetrisBoard *self, u16 blocks_down, u16 blocks_right);


#endif
