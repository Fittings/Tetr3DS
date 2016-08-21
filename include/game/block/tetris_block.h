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
 * @param creator_id The id of the block creator. (Usually the standard block creator)
 * @return A single TetrisBlock
 */
extern TetrisBlock *tetris_block_init(u32 creator_id); //ZZZ TODO implement colours

/**
 * @brief Frees the TetrisBlock struct
 *
 * Frees the TetrisBlock struct.
 * This should always be called after the TetrisBlock struct is no longer in use
 *
 * @param self The TetrisBlock struct to reference
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
 * @brief Returns the creator_id of the block
 *
 * @param self The TetrisBlock struct to reference
 */
extern u32 tetris_block_get_creator_id(TetrisBlock *self);




#endif
