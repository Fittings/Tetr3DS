/**
 * @file piece_generator.h
 * @author Cameron Milsom
 * @brief Keeps a constant list of pieces.
 *
 * Generates TetrisPieces for a tetris game.
 * Pieces can be withdrawn and the piece generator
 * will generate a new piece to maintain size.
 */
#ifndef INCLUDE__GAME_PIECE_GENERATOR_H_
#define INCLUDE__GAME_PIECE_GENERATOR_H_


#include "../include/game/configurations/piece_set.h"
#include "../include/game/block/piece/tetris_piece.h"
#include "../general/region/region.h"



/**
 * @brief Piece Generator used for piece generation.
 *
 * Used for generating pieces.
 */
typedef struct _PieceGenerator PieceGenerator;



/**
 * @brief Initialises the PieceGenerator struct
 *
 * Initializes a piece generator.
 *
 * @param size The size of the piece generator. There will always be 'size' amounts of pieces.
 * @param set_type The set of pieces used for the piece generator. All pieces will be from this set.
 * @return Returns the PieceGenerator for TetrisPiece generation.
 */
extern PieceGenerator *piece_generator_init(u8 size, PieceSetType set_type);


/**
 * @brief Frees the PieceGenerator struct.
 *
 * Frees the PieceGenerator struct.
 *
 * @param self The PieceGenerator struct to reference.
 */
extern void piece_generator_free(PieceGenerator *self);


/**
 * @brief Returns the next piece in the queue.
 *
 * Returns the next piece in the queue.
 * Adds another piece to replace it at the bottom of the queue.
 *
 * @param self The PieceGenerator struct to reference.
 * @return The TetrisPiece at the top of the PieceGenerator queue.
 */
extern TetrisPiece *piece_generator_get_next(PieceGenerator *self);

/**
 * @brief Draws the Piece Generator in a given region.
 *
 * Draws a piece generator in a given region.
 *
 * @param self The PieceGenerator struct to reference.
 * @param max_region The maximum region that the generator will be rendered in.
 * @param block_size The maximum block size the piece generator will render with.
 */
extern void piece_generator_draw(PieceGenerator *self, Region *max_region, int block_size);


#endif
