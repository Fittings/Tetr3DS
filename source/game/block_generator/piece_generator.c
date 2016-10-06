#include "../include/game/block_generator/piece_generator.h"

//Implementation Specific Imports
#include <malloc.h>
#include <sys/queue.h>
#include "../include/utility/queue.h"





struct _PieceGenerator
{
	PieceSet *piece_set;

	Queue *piece_queue;
};





PieceGenerator *piece_generator_init(s8 size, PieceSetType set_type)
{
	PieceGenerator *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->piece_set = piece_set_init(set_type);

		self->piece_queue = queue_init(size);
		for (s8 i=0; i < size; i++)
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

void piece_generator_draw(PieceGenerator *self, Region *max_region, int block_size)
{
	s16 y_px = region_get_top_left_y(max_region);

	TetrisPiece **tetris_piece_list = (TetrisPiece **) queue_get_item_list(self->piece_queue);
	for (s8 i=0; i < queue_get_current_size(self->piece_queue); i++)
	{
		TetrisPiece *tetris_piece = tetris_piece_list[i];
		if (tetris_piece != NULL)
		{
			s16 x_px = point_get_x(tetris_piece_get_point(tetris_piece)) * block_size;
			tetris_piece_draw(tetris_piece, x_px, y_px, block_size, 0xFF);


			y_px += (block_size * tetris_piece_get_height(tetris_piece));

		}

	}
}



