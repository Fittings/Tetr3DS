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


extern PieceSet *piece_set_init(PieceSetType set_type);
extern void piece_set_free(PieceSet *self);
extern TetrisPiece *piece_set_get_tetris_piece(PieceSet *self, u8 piece_number);
extern TetrisPiece *piece_set_get_rand_tetris_piece(PieceSet *self);



#endif
