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


extern TetrisPiece *piece_generator_get_next(PieceGenerator *self);




#endif
