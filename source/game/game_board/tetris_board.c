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
	TetrisPiece *current_piece;
	Point *piece_location; //Location of the centre of the piece.

	TetrisBlock ***block_array;
	int block_width;
	int block_height;


};





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
				self->block_array[w][h] = tetris_block_init(BLOCK_TYPE_EMPTY, LIGHT_GREY);
			}
		}

		//ZZZ TODO Delete

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


bool tetris_board_set_current_piece(TetrisBoard *self, TetrisPiece *piece)
{
	if (self->current_piece == NULL)
	{
		self->current_piece = piece;
		self->piece_location = point_init( (self->block_width/2), 1 ); //Set the piece to centre and top of the board
		return true;
	}

	return false;
}


TetrisPiece *tetris_board_get_current_piece(TetrisBoard *self)
{
	return self->current_piece;
}



void tetris_board_concrete_current_piece(TetrisBoard *self)
{
	if (self->current_piece == NULL) return;



	s16 x_piece_offset = point_get_x(self->piece_location) - point_get_x(tetris_piece_get_point(self->current_piece));
	s16 y_piece_offset = point_get_y(self->piece_location) - point_get_y(tetris_piece_get_point(self->current_piece));

	u16 p_width = tetris_piece_get_width(self->current_piece);
	u16 p_height = tetris_piece_get_height(self->current_piece);

	TetrisBlock ***tetris_array = tetris_piece_get_array(self->current_piece);

	for (int x=0; x < p_width; x++)
	{
		int board_x = x + x_piece_offset;

		for (int y=0; y < p_height; y++)
		{
			int board_y = y + y_piece_offset;

			sf2d_draw_rectangle((board_x)*12, (board_y)*12, 12, 12, RGBA8(0xFF, 0x00, 0x00, 0xFF));

			if (board_x >= 0 && board_x < self->block_width &&
					board_y >= 0 && board_y < self->block_height &&
					tetris_block_get_type(tetris_array[x][y]) != BLOCK_TYPE_EMPTY)
			{
				tetris_block_free(self->block_array[board_x][board_y]);
				self->block_array[board_x][board_y] = tetris_array[x][y];
			}
			else
			{
				tetris_block_free(tetris_array[x][y]);
			}

		}
	}

	self->current_piece = NULL;
}


//Checks if there is a block at the current location.
static bool is_position_free(TetrisBoard *self, u16 x, u16 y)
{
	if (x < 0) return false;
	if (x >= self->block_width) return false;
	if (y >= self->block_height) return false;
	if (y < 0) return true;

	return tetris_block_get_type(self->block_array[x][y]) == BLOCK_TYPE_EMPTY;
}


//Checks if the current piece is in a valid position on the board.
static bool is_current_piece_valid(TetrisBoard *self)
{
	TetrisBlock ***tetris_array = tetris_piece_get_array(self->current_piece);

	u16 width = tetris_piece_get_width(self->current_piece);
	u16 height = tetris_piece_get_height(self->current_piece);

	s16 x_piece_offset = point_get_x(self->piece_location) - point_get_x(tetris_piece_get_point(self->current_piece));
	s16 y_piece_offset = point_get_y(self->piece_location) - point_get_y(tetris_piece_get_point(self->current_piece));


	for (int x=0; x < width; x++)
	{
		for (int y=0; y < height; y++)
		{
			if ( tetris_block_get_type(tetris_array[x][y]) != BLOCK_TYPE_EMPTY &&
				 !is_position_free(self, x + x_piece_offset, y + y_piece_offset) )
			{
				return false;
			}
		}
	}
	return true;
}


bool tetris_board_move_current_piece(TetrisBoard *self, u16 blocks_right, u16 blocks_down)
{
	if (self->current_piece == NULL) return false;

	Point *old_point = self->piece_location;
	u16 old_x = point_get_x(old_point);
	u16 old_y = point_get_y(old_point);

	self->piece_location = point_init(old_x + blocks_right, old_y + blocks_down);


	if (is_current_piece_valid(self))
	{
		return true;
	}
	else
	{
		self->piece_location = point_init(old_x, old_y);
		return false;
	}
}





extern void draw_current_piece(TetrisBoard *self, int start_x_px, int start_y_px, int block_length_px)
{
	if (self->current_piece != NULL)
	{
		tetris_piece_draw(self->current_piece, start_x_px + (point_get_x(self->piece_location) * block_length_px), start_y_px + (point_get_y(self->piece_location) * block_length_px), block_length_px);
	}
}

extern void draw_tetris_board(TetrisBoard *self, int start_x_px, int start_y_px, int block_length_px)
{
	for (int w=0; w < self->block_width; w++)
	{
		for (int h=0; h < self->block_height; h++)
		{
			int block_x = start_x_px + (w * block_length_px);
			int block_y = start_y_px + (h * block_length_px);
			tetris_block_draw(self->block_array[w][h], block_x, block_y, block_length_px);
		}
	}
}


void tetris_board_draw(TetrisBoard *self, int x, int y, int pixel_width, int pixel_height)
{
	int block_length = min((pixel_width / self->block_width), (pixel_height / self->block_height));
	block_length = block_length <= 2 ? 2 : block_length; //Enforce blocks are always 2px


	int total_width = block_length * self->block_width;
	int start_x = (total_width > pixel_width) ? pixel_width - total_width : x + ((pixel_width - total_width)/2);


	int total_height = block_length * self->block_height;
	int start_y = (total_height > pixel_height) ? pixel_height - total_height : y + ((pixel_height - total_height)/2);

	draw_tetris_board(self, start_x, start_y, block_length);
	draw_current_piece(self, start_x, start_y, block_length);
}
