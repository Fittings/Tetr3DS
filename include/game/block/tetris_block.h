/**
 * @file tetris_block.h
 * @author Cameron Milsom
 * @brief A singular tetris block
 *
 * Represents a singular tetris block.
 * Multiple blocks make a singular tetris piece.
 */
#ifndef INCLUDE_GAME_TETRIS_BLOCK_H_
#define INCLUDE_GAME_TETRIS_BLOCK_H_

#include "../include/types/colours.h"
#include "../include/game/block/block_type.h"


/**
 * @brief The Tetris Block.
 *
 * A singular tetris block.
 */
typedef struct _TetrisBlock TetrisBlock;



/**
 * @brief Initialises the TetrisBlock struct
 *
 * Creates a TetrisBlock struct. Tetris blocks are used for creating tetris pieces.
 *
 * @param block_type The type of block
 * @param colour The colour of the block @ref colours.h
 * @return A single TetrisBlock
 */
extern TetrisBlock *tetris_block_init(BlockType block_type, Colour colour);

/**
 * @brief Creates a deep copy of a TetrisBlock struct.
 *
 * Returns a deep copy of a TetrisBlock struct.
 *
 * @param self The TetrisBlock struct to reference.
 * @return A deep copy of the TetrisBlock.
 */
extern TetrisBlock *tetris_block_deep_copy(TetrisBlock *self);

/**
 * @brief Frees the TetrisBlock struct
 *
 * Frees the TetrisBlock struct.
 * This should always be called after the TetrisBlock struct is no longer in use
 *
 * @param self The TetrisBlock struct to reference.
 */
extern void tetris_block_free(TetrisBlock *self);

/**
 * @brief Returns the size of a TetrisBlock struct
 *
 * Returns the size of the TetrisBlock struct.
 * This can change depending on the implementation of this header.
 *
 * @return The size of th TetrisBlock struct.
 */
extern int tetris_block_sizeof();

/**
 * @brief Returns the type of block
 *
 * @param self The TetrisBlock struct to reference.
 */
extern BlockType tetris_block_get_type(TetrisBlock *self);

extern Colour tetris_block_get_colour(TetrisBlock *self);

/**
 * @brief Draws the block.
 *
 * @param self The TetrisBlock struct to reference.
 * @param x The x co-ordinate of the top left of the box. (Where 0,0 is top left of the screen)
 * @param y The y co-ordinate of the top left of the box. (Where 0,0 is top left of the screen)
 * @param length The width and height of the block.
 */
extern void tetris_block_draw(TetrisBlock *self, u16 x, u16 y, u16 length);



#endif
