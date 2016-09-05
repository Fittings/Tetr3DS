#include "../include/game/block_generator/piece_generator.h"

//Implementation Specific Imports
#include <malloc.h>
#include <stdbool.h>
#include <sys/queue.h>


/*
 *
 *


struct _PieceGenerator
{
	PieceSet *piece_set;

	u8 size;
	TetrisPiece **piece_array;

};



static PieceQueue *generate_piece_array(u8 size, PieceSet *piece_set)
{

	for (int i=0; i < size; i++)
	{
		piece_array[i] = piece_set_get_rand_tetris_piece(piece_set);
	}

	return piece_array;
}

PieceGenerator *piece_generator_init(u8 size, PieceSetType set_type)
{
	PieceGenerator *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->piece_set = piece_set_init(set_type);
		self->size = size;
		self->piece_array = generate_piece_array(size, self->piece_set);
	}

	return self;
}


TetrisPiece *piece_generator_get_next(PieceGenerator self)
{

}
*/
