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




#endif
