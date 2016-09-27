#include "../include/game/game_board/tetris_board.h"

#include <malloc.h>
#include <sf2d.h> //ZZZ TODO Remove this
#include "../include/utility/numbers_utility.h"


#define BOARD_COLOUR BLACK
//ZZZ TODO Move this to the board view class,


struct _TetrisBoard
{
	TetrisBlock ***block_array;
	u16 block_array_width;
	u16 block_array_height;
};


//Private Methods

static void free_block_array(TetrisBoard *self)
{
	for (int w=0; w < self->block_array_width; w++)
	{
		for (int h=0; h < self->block_array_height; h++)
		{
			tetris_block_free(self->block_array[w][h]); //Frees the internal TetrisBlock
		}
		free(self->block_array[w]); //Frees the sub-array
	}
	free(self->block_array); //Frees the outside array
}


//Checks if there is a block at the current location.
static bool is_position_free(TetrisBoard *self, u16 x, u16 y)
{
	if (x < 0) return false;
	if (x >= self->block_array_width) return false;
	if (y >= self->block_array_height) return false;
	if (y < 0) return true;

	return tetris_block_get_type(self->block_array[x][y]) == BLOCK_TYPE_EMPTY;
}


//Checks if the current piece is in a valid position on the board.
bool tetris_board_is_piece_location_valid(TetrisBoard *self, TetrisPiece *piece, Point *piece_centre_location)
{
	TetrisBlock ***tetris_array = tetris_piece_get_array(piece);

	u16 width = tetris_piece_get_width(piece);
	u16 height = tetris_piece_get_height(piece);

	s16 x_piece_offset = point_get_x(piece_centre_location) - point_get_x(tetris_piece_get_point(piece));
	s16 y_piece_offset = point_get_y(piece_centre_location) - point_get_y(tetris_piece_get_point(piece));


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


static bool is_line_complete(TetrisBoard *self, int line_height)
{
	for (int w=0; w < self->block_array_width; w++)
	{
		if (tetris_block_get_type(self->block_array[w][line_height]) == BLOCK_TYPE_EMPTY)
		{
			return false;
		}
	}

	return true;
}

static void set_row_to_empty(TetrisBoard *self, int row)
{
	for (int w=0; w < self->block_array_width; w++)
	{
		self->block_array[w][row] = tetris_block_init(BLOCK_TYPE_EMPTY, BOARD_COLOUR);
	}
}

//Moves the upper part of the board down into the row_dest
static void move_board_down_to(TetrisBoard *self, int row_dest)
{
	if (row_dest >= self->block_array_height) return;

	for (int h = row_dest-1; h >= 0; h--)
	{
		for (int w=0; w < self->block_array_width; w++)
		{
			self->block_array[w][h+1] = self->block_array[w][h];
		}
	}

	set_row_to_empty(self, 0);
}



//Public Visibility

TetrisBoard *tetris_board_init(int block_array_width, int block_array_height)
{
	TetrisBoard *self = malloc(sizeof *self);
	if (!self || block_array_width <= 0 || block_array_height <= 0)
	{
		return NULL;
	}

	{
		self->block_array_width = block_array_width;
		self->block_array_height = block_array_height;

		self->block_array = malloc(block_array_width * sizeof(void *));
		for (int w=0; w < block_array_width; w++)
		{
			self->block_array[w] = malloc(block_array_height * sizeof(void *));
			for (int h=0; h < block_array_height; h++)
			{
				self->block_array[w][h] = tetris_block_init(BLOCK_TYPE_EMPTY, BOARD_COLOUR);
			}
		}
	}

	return self;
}

void tetris_board_free(TetrisBoard *self)
{
	if (self)
	{
		free_block_array(self);
		free(self);
	}
}

u16 tetris_board_get_width(TetrisBoard *self)
{
	return self->block_array_width;
}

u16 tetris_board_get_height(TetrisBoard *self)
{
	return self->block_array_height;
}

TetrisBlock *tetris_board_get_block(TetrisBoard *self, u16 x, u16 y)
{
	return self->block_array[x][y];
}


bool tetris_board_put(TetrisBoard *self, TetrisPiece *piece, u8 x, u8 y)
{
	if (x < self->block_array_width && y < self->block_array_height)
	{

	}

	return false;
}


void tetris_board_concrete_tetris_piece(TetrisBoard *self, TetrisPiece *current_piece, Point *piece_centre_location)
{

	s16 x_piece_offset = point_get_x(piece_centre_location) - point_get_x(tetris_piece_get_point(current_piece));
	s16 y_piece_offset = point_get_y(piece_centre_location) - point_get_y(tetris_piece_get_point(current_piece));

	u16 p_width = tetris_piece_get_width(current_piece);
	u16 p_height = tetris_piece_get_height(current_piece);

	TetrisBlock ***tetris_array = tetris_piece_get_array(current_piece);

	for (int x=0; x < p_width; x++)
	{
		int board_x = x + x_piece_offset;

		for (int y=0; y < p_height; y++)
		{
			int board_y = y + y_piece_offset;

			if (board_x >= 0 && board_x < self->block_array_width &&
					board_y >= 0 && board_y < self->block_array_height &&
					tetris_block_get_type(tetris_array[x][y]) != BLOCK_TYPE_EMPTY)
			{
				//tetris_block_free(self->block_array[board_x][board_y]);
				self->block_array[board_x][board_y] = tetris_array[x][y];
				tetris_array[x][y] = NULL; //Note: This is done so we can't accidentally free the block.
			}
		}
	}
}






void tetris_board_remove_full_lines(TetrisBoard *self)
{
	for (int h=0; h < self->block_array_height; h++)
	{
		if (is_line_complete(self, h))
		{
			move_board_down_to(self, h);
		}
	}
}







//ZZZ TODO Move draw methods into a seperate view class.



void tetris_board_draw(TetrisBoard *self, int start_x_px, int start_y_px, int block_length_px)
{
	for (int w=0; w < self->block_array_width; w++)
	{
		for (int h=0; h < self->block_array_height; h++)
		{
			int block_x = start_x_px + (w * block_length_px);
			int block_y = start_y_px + (h * block_length_px);
			tetris_block_draw(self->block_array[w][h], block_x, block_y, block_length_px);
		}
	}
}



