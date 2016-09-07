/**
 * @file piece_set.h
 * @author Cameron Milsom
 * @brief A set of pieces.
 *
 * Represents a Set of TetrisPieces
 */
#ifndef INCLUDE_PIECE_SET_H_
#define INCLUDE_PIECE_SET_H_

#include "../include/game/block/piece/tetris_piece.h"

/**
 * @brief The different designed piece sets.
 */
typedef enum
{
	TETRIS_SET_STANDARD
} PieceSetType;

/**
 * @brief A set of pieces.
 *
 * A unique set of TetrisPiece.
 */
typedef struct _PieceSet PieceSet;

/**
 * @brief Initializes a PieceSet struct.
 *
 * Creates a PieceSet, used for creating pieces with a PieceGenerator.
 *
 * @param set_type The type of piece set. Determines the shapes.
 * @return The initialised PieceSet struct.
 */
extern PieceSet *piece_set_init(PieceSetType set_type);

/**
 * @brief Frees a PieceSet struct.
 *
 * @param self The PieceSet struct to free.
 */
extern void piece_set_free(PieceSet *self);

/**
 * @brief Returns a TetrisPiece
 *
 * Gets the TetrisPiece at the piece_number index.
 *
 * @param self The PieceSet struct to reference.
 * @param piece_number The piece at the index. piece_number loops around if greater than number of pieces.
 */
extern TetrisPiece *piece_set_get_tetris_piece(PieceSet *self, u8 piece_number);

/**
 * @brief Returns a random TetrisPiece from the PieceSet.
 *
 * Returns a random TetrisPiece from the PieceSet.
 *
 * @param self The TetrisPiece struct to reference.
 * @return A random TetrisPiece from the set.
 */
extern TetrisPiece *piece_set_get_rand_tetris_piece(PieceSet *self);



#endif
