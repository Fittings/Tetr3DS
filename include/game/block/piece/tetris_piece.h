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
#include "../include/game/block/point.h"





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
 * @param centre_block The centre block of the block array.
 * @param width The width of the 2d array
 * @param height The height of the 2d array
 * @return A single TetrisPiece
 */
extern TetrisPiece *tetris_piece_init(TetrisBlock ***piece_array, Point *centre_block, s16 width, s16 height);

/**
 * @brief Frees the TetrisPiece struct.
 *
 * Frees the TetrisPiece struct.
 * This will also free the underlying blocks representing the TetrisPiece.
 * Call @ref tetris_piece_shallow_free to not free the blocks
 *
 * @param self The TetrisPiece struct to reference
 */
extern void tetris_piece_free(TetrisPiece *self);

/**
 * @brief Frees the TetrisBlock struct
 *
 * Frees the TetrisBlock struct.
 * This should always be called after the TetrisBlock struct is no longer in use
 *
 * Important Note:
 * This intentionally doesn't free the block array.
 * TetrisBlocks are typically used even if the current peice isn't used.
 *
 *
 * @param self The TetrisBoard struct to reference.
 */
extern void tetris_piece_shallow_free(TetrisPiece *self);

/**
 * @brief Creates a deep copy of a TetrisPiece struct.
 *
 * Creates a deep copy of a TetrisPiece struct.
 *
 * @param self The TetrisPiece struct to reference.
 * @return A deep copy of the TetrisPiece
 */
extern TetrisPiece *tetris_piece_deep_copy(TetrisPiece *self);

/**
 * @brief Rotates a Tetris Piece clockwise 90 degrees.
 *
 * Takes a TetrisPiece and returns the TetrisPiece that is rotated 90 degrees clockwise.
 *
 * @param self The TetrisPiece struct to reference.
 * @param rotations The amount of times to rotate.
 */
extern TetrisPiece tetris_block_rotate_90_clockwise(TetrisPiece *self, s8 rotations);


/**
 * @brief Draws the TetrisPiece.
 *
 * Draws the TetrisPiece.
 *
 * @param self The TetrisPiece struct to reference.
 * @param pixel_x The x pixel co-ordinate for the top left of the centre block.
 * @param pixel_y The y pixel co-ordinate for the top left of the centre block.
 * @param block_size The width/height of the TetrisBlock to draw
 * @param opacity The opacity of the TetrisPiece to draw.
 */
extern void tetris_piece_draw(TetrisPiece *self, s16 pixel_x, s16 pixel_y, s16 block_size, s8 opacity);


/**
 * @brief Returns the focal point of the TetrisPiece
 *
 * Returns the focal point of the TetrisPiece.
 * The focal point is used as a centre of rotation.
 *
 * @param self The TetrisPiece struct to reference.
 * @return The Point struct that represents the TetrisPiece focal point
 */
extern Point *tetris_piece_get_point(TetrisPiece *self);


/**
 * @brief Returns the 2d Block array representing the TetrisPiece.
 *
 * Returns the Block array that represents the TetrisPiece.
 * The Block array consists of blocks that are physical, and BLOCK_TYPE_EMPTY that are not used.
 *
 * @param self The TetrisPiece struct to reference.
 * @return The 2d TetrisBlock array representing the TetrisPiece
 */
extern TetrisBlock ***tetris_piece_get_array(TetrisPiece *self);


/**
 * @brief Returns the width of the 2d TetrisBlock array.
 *
 * Returns the width of the 2d Block array representing the TetrisPiece
 *
 * @param self The TetrisPiece struct to reference.
 * @return The width of the 2d TetrisBlock array.
 */
extern s16 tetris_piece_get_width(TetrisPiece *self);


/**
 * @brief Returns the height of the 2d TetrisBlock array.
 *
 * Returns the height of the 2d Block array representing the TetrisPiece
 *
 * @param self The TetrisPiece struct to reference.
 * @return The height of the 2d TetrisBlock array.
 */
extern s16 tetris_piece_get_height(TetrisPiece *self);

/**
 * @brief Rotates the TetrisPiece
 *
 * Rotates the TetrisPiece by clockwise by the amount of rotates given.
 *
 * @param self The TetrisPiece struct to reference
 * @param clockwise_90_rotation_count The amount of rotations.
 */
extern void tetris_piece_rotate(TetrisPiece *self, s8 clockwise_90_rotation_count);



#endif
