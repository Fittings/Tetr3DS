/**
 * @file tetris_piece.h
 * @author Cameron Milsom
 * @brief A tetris piece.
 *
 * Represents a single tetris piece.
 */
#ifndef INCLUDE_GAME_TETRIS_PIECE_H_
#define INCLUDE_GAME_TETRIS_PIECE_H_

#include "../include/game/block/tetris_block.h"




/**
 * @brief The Tetris Piece.
 *
 * A singular Tetris piece.
 */
typedef struct _TetrisPiece TetrisPiece;



/**
 * @brief Initialises the TetrisPiece struct
 *
 * Creates a TetrisPiece struct.
 *
 * @param piece_array The 2d array of tetris blocks that create a TetrisPiece
 * @param width The width of the 2d array
 * @param height The height of the 2d array
 * @return A single TetrisPiece
 */
extern TetrisPiece *tetris_piece_init(TetrisBlock ***piece_array, u8 width, u8 height);

/**
 * @brief Frees the TetrisBlock struct
 *
 * Frees the TetrisBlock struct.
 * This should always be called after the TetrisBlock struct is no longer in use
 *
 * @param self The TetrisBoard struct to reference
 */
extern void tetris_piece_free(TetrisPiece *self);



/**
 * @brief Rotates a Tetris Piece clockwise 90 degrees.
 *
 *	Takes a TetrisPiece and returns the TetrisPiece that is rotated 90 degrees clockwise.
 *
 *	@param self The TetrisPiece struct.
 *	@param rotations The amount of times to rotate.
 */
extern TetrisPiece tetris_block_rotate_90_clockwise(TetrisPiece *self, u8 rotations);




#endif