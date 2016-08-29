#include "../include/game/configurations/piece_set.h"
#include "../include/game/configurations/pieces/pieces.h"
#include <malloc.h>



struct _PieceSet
{
	TetrisPiece **piece_set;
	u8 set_size;
};
typedef struct _PieceSet PieceSet;




static void standard_set_init(PieceSet *self)
{
	self->set_size = 7;

	self->piece_set = malloc(self->set_size * sizeof(void *));

	self->piece_set[0] = create_O();
	self->piece_set[1] = create_I();
	self->piece_set[2] = create_S();
	self->piece_set[3] = create_Z();
	self->piece_set[4] = create_L();
	self->piece_set[5] = create_J();
	self->piece_set[6] = create_T();

}

PieceSet *piece_set_init(PieceSetType set_type) //ZZZ TODO Define a constant
{
	PieceSet *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		switch (set_type)
		{
		case TETRIS_SET_STANDARD:
			standard_set_init(self);
			break;
		}
	}

	return self;
}


void piece_set_free(PieceSet *self)
{
	if (self)
	{
		for (int i=0; i < self->set_size; i++)
		{
			tetris_piece_free(self->piece_set[i]);
		}

		free(self);
	}
}
