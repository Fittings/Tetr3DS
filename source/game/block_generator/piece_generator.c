#include "../include/game/block_generator/piece_generator.h"

//Implementation Specific Imports
#include <malloc.h>
#include <stdbool.h>
#include <sys/queue.h>
#include "../include/utility/queue.h"





struct _PieceGenerator
{
	PieceSet *piece_set;

	Queue *piece_queue;
};





PieceGenerator *piece_generator_init(u8 size, PieceSetType set_type)
{
	PieceGenerator *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->piece_set = piece_set_init(set_type);

		self->piece_queue = queue_init(size);
		for (u8 i=0; i < size; i++)
		{
			queue_add(self->piece_queue, piece_set_get_rand_tetris_piece(self->piece_set));
		}
	}

	return self;
}

void piece_generator_free(PieceGenerator *self)
{
	if (self)
	{
		free(self);
	}
}


TetrisPiece *piece_generator_get_next(PieceGenerator *self)
{
	TetrisPiece *piece = (TetrisPiece *) queue_pop(self->piece_queue);

	queue_add(self->piece_queue, piece_set_get_rand_tetris_piece(self->piece_set));

	return piece;
}

TetrisPiece **piece_generator_get_list(PieceGenerator *self)
{
	int queue_size = queue_get_current_size(self->piece_queue);

	TetrisPiece **piece_array = malloc(queue_size * sizeof(TetrisPiece *));

	for (int i=0; i < queue_size; i++)
	{
		piece_array[i] = piece_set_get_rand_tetris_piece(self->piece_set);
	}

	return piece_array;
}



