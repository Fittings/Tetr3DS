#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include <stdbool.h>

#include "../include/game/game_board/tetris_board.h"
#include "../include/game/block/tetris_block.h"
#include "../include/game/block/piece/tetris_piece.h"
#include "../include/utility/numbers_utility.h"

struct _TetrisBoard
{
	//ZZZ TODO Create an ID Enum

	TetrisPiece *current_piece;
	Point *piece_location; //Location of the centre of the piece.

	TetrisBlock ***block_array;
	int block_width;
	int block_height;
};
typedef struct _TetrisBoard TetrisBoard;





TetrisBoard *tetris_board_init(int block_width, int block_height)
{
	TetrisBoard *self = malloc(sizeof *self);
	if (!self || block_width <= 0 || block_height <= 0)
	{
		return NULL;
	}

	{
		self->current_piece = NULL;

		self->block_width = block_width;
		self->block_height = block_height;

		self->block_array = malloc(block_width * sizeof(void *));
		for (int w=0; w < block_width; w++)
		{
			self->block_array[w] = malloc(block_height * sizeof(void *));
			for (int h=0; h < block_height; h++)
			{
				self->block_array[w][h] = tetris_block_init(BLOCK_TYPE_BACKGROUND, LIGHT_GREY);
			}
		}
	}

	return self;
}


static void free_block_array(TetrisBoard *self)
{
	for (int w=0; w < self->block_width; w++)
	{
		for (int h=0; h < self->block_height; h++)
		{
			tetris_block_free(self->block_array[w][h]); //Frees the internal TetrisBlock
		}
		free(self->block_array[w]); //Frees the sub-array
	}
	free(self->block_array); //Frees the outside array
}


void tetris_board_free(TetrisBoard *self)
{
	if (self)
	{
		free_block_array(self);
		free(self);
	}
}


bool tetris_board_put(TetrisBoard *self, TetrisPiece *piece, u8 x, u8 y)
{
	if (x < self->block_width && y < self->block_height)
	{

	}

	return false;
}



void tetris_board_draw(TetrisBoard *self, int x, int y, int pixel_width, int pixel_height)
{
	int block_length = min((pixel_width / self->block_width), (pixel_height / self->block_height));
	block_length = block_length <= 2 ? 2 : block_length; //Enforce blocks are always 2px


	int total_width = block_length * self->block_width;
	int start_x = (total_width > pixel_width) ? pixel_width - total_width : x + ((pixel_width - total_width)/2);


	int total_height = block_length * self->block_height;
	int start_y = (total_height > pixel_height) ? pixel_height - total_height : y + ((pixel_height - total_height)/2);

	for (int w=0; w < self->block_width; w++)
	{
		for (int h=0; h < self->block_height; h++)
		{
			int block_x = start_x + (w * block_length);
			int block_y = start_y + (h * block_length);
			tetris_block_draw(self->block_array[w][h], block_x, block_y, block_length);
		}
	}

	if (self->current_piece != NULL)
	{
		tetris_piece_draw(self->current_piece, start_x + (point_get_x(self->piece_location) * block_length), start_y + (point_get_y(self->piece_location) * block_length), block_length);
	}

}

bool tetris_board_set_current_piece(TetrisBoard *self, TetrisPiece *piece)
{
	if (self->current_piece != NULL)
	{
		self->current_piece = piece;
		self->piece_location = point_init( (self->block_width/2), 0 ); //Set the piece to centre and top of the board

		return true;
	}

	return false;
}

TetrisPiece *tetris_board_get_current_piece(TetrisBoard *self)
{
	return self->current_piece;
}









