#include "../include/game/configurations/piece_set.h"
#include "../include/game/configurations/pieces/pieces.h"
#include "../include/game/block/piece/tetris_piece.h"

#include <stdlib.h>
#include <malloc.h>



struct _PieceSet
{
	PieceSetType set_type;
	s8 set_size;
};
typedef struct _PieceSet PieceSet;



PieceSet *piece_set_init(PieceSetType set_type) //ZZZ TODO Define a constant
{
	PieceSet *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->set_type = set_type;

		switch (set_type)
		{
		case TETRIS_SET_STANDARD:
			self->set_size = 7;
			break;
		}
	}

	return self;
}


void piece_set_free(PieceSet *self)
{
	if (self)
	{
		free(self);
	}
}


static TetrisPiece *get_standard_tetris_piece(s8 piece_number)
{
	switch (piece_number)
	{
	case 0:
		return create_O();
	case 1:
		return create_I();
	case 2:
		return create_S();
	case 3:
		return create_Z();
	case 4:
		return create_L();
	case 5:
		return create_J();
	case 6:
		return create_T();
	default:
		return NULL;
	}
}


TetrisPiece *piece_set_get_tetris_piece(PieceSet *self, s8 piece_number)
{
	piece_number = piece_number % (self->set_size);

	switch (self->set_type)
	{
	case TETRIS_SET_STANDARD:
		return get_standard_tetris_piece(piece_number);

	default:
		return get_standard_tetris_piece(piece_number);
	}
}


TetrisPiece *piece_set_get_rand_tetris_piece(PieceSet *self)
{
	s8 piece_number = rand() % (self->set_size);
	return piece_set_get_tetris_piece(self, piece_number);

}
