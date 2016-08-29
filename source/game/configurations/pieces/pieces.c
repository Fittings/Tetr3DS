#include "../include/game/configurations/pieces/pieces.h"
#include "../include/types/colours.h"
#include "../include/game/block/tetris_block.h"
#include <malloc.h>





TetrisPiece *create_O()
{
	//Standard Tetris Piece is inside a 4x4
	u8 width = 4;
	u8 height = 4;

	TetrisBlock ***block_array;
	block_array = malloc(width * sizeof(void *));
	for (int w=0; w < width; w++)
	{
		block_array[w] = malloc(height * sizeof(void *));
		for (int h=0; h < height; h++)
		{
			if ( (w == 1 && h == 1) || (w == 2 && h == 1) || (w == 1 && h == 2) || (w == 2 && h == 2) )
			{
				block_array[w][h] = tetris_block_init(BLOCK_TYPE_USER, LIGHT_ORANGE);
			}
			else
			{
				block_array[w][h] = tetris_block_init(BLOCK_TYPE_EMPTY, LIGHT_GREY);
			}

		}
	}

	Point *centre_point = point_init(2, 1);
	return tetris_piece_init(block_array, centre_point, width, height);
}

TetrisPiece *create_I()
{
	//Standard Tetris Piece is inside a 4x4
	u8 width = 4;
	u8 height = 4;

	TetrisBlock ***block_array;
	block_array = malloc(width * sizeof(void *));
	for (int w=0; w < width; w++)
	{
		block_array[w] = malloc(height * sizeof(void *));
		for (int h=0; h < height; h++)
		{
			if ( (w == 0 && h == 1) || (w == 1 && h == 1) || (w == 2 && h == 1) || (w == 3 && h == 1) )
			{
				block_array[w][h] = tetris_block_init(BLOCK_TYPE_USER, LIGHT_BLUE);
			}
			else
			{
				block_array[w][h] = tetris_block_init(BLOCK_TYPE_EMPTY, LIGHT_GREY);
			}

		}
	}

	Point *centre_point = point_init(2, 1);
	return tetris_piece_init(block_array, centre_point, width, height);
}

TetrisPiece *create_Z()
{
	//Standard Tetris Piece is inside a 4x4
	u8 width = 4;
	u8 height = 4;

	TetrisBlock ***block_array;
	block_array = malloc(width * sizeof(void *));
	for (int w=0; w < width; w++)
	{
		block_array[w] = malloc(height * sizeof(void *));
		for (int h=0; h < height; h++)
		{
			if ( (w == 1 && h == 1) || (w == 2 && h == 1) || (w == 2 && h == 2) || (w == 3 && h == 2) )
			{
				block_array[w][h] = tetris_block_init(BLOCK_TYPE_USER, DARK_RED);
			}
			else
			{
				block_array[w][h] = tetris_block_init(BLOCK_TYPE_EMPTY, LIGHT_GREY);
			}

		}
	}

	Point *centre_point = point_init(2, 1);
	return tetris_piece_init(block_array, centre_point, width, height);
}

TetrisPiece *create_S()
{
	//Standard Tetris Piece is inside a 4x4
	u8 width = 4;
	u8 height = 4;

	TetrisBlock ***block_array;
	block_array = malloc(width * sizeof(void *));
	for (int w=0; w < width; w++)
	{
		block_array[w] = malloc(height * sizeof(void *));
		for (int h=0; h < height; h++)
		{
			if ( (w == 2 && h == 1) || (w == 3 && h == 1) || (w == 1 && h == 2) || (w == 2 && h == 2) )
			{
				block_array[w][h] = tetris_block_init(BLOCK_TYPE_USER, LIGHT_GREEN);
			}
			else
			{
				block_array[w][h] = tetris_block_init(BLOCK_TYPE_EMPTY, LIGHT_GREY);
			}

		}
	}

	Point *centre_point = point_init(2, 1);
	return tetris_piece_init(block_array, centre_point, width, height);
}

TetrisPiece *create_L()
{
	//Standard Tetris Piece is inside a 4x4
	u8 width = 4;
	u8 height = 4;

	TetrisBlock ***block_array;
	block_array = malloc(width * sizeof(void *));
	for (int w=0; w < width; w++)
	{
		block_array[w] = malloc(height * sizeof(void *));
		for (int h=0; h < height; h++)
		{
			if ( (w == 1 && h == 1) || (w == 2 && h == 1) || (w == 3 && h == 1) || (w == 1 && h == 2) )
			{
				block_array[w][h] = tetris_block_init(BLOCK_TYPE_USER, DARK_BLUE);
			}
			else
			{
				block_array[w][h] = tetris_block_init(BLOCK_TYPE_EMPTY, LIGHT_GREY);
			}

		}
	}

	Point *centre_point = point_init(2, 1);
	return tetris_piece_init(block_array, centre_point, width, height);
}

TetrisPiece *create_J()
{
	//Standard Tetris Piece is inside a 4x4
	u8 width = 4;
	u8 height = 4;

	TetrisBlock ***block_array;
	block_array = malloc(width * sizeof(void *));
	for (int w=0; w < width; w++)
	{
		block_array[w] = malloc(height * sizeof(void *));
		for (int h=0; h < height; h++)
		{
			if ( (w == 1 && h == 1) || (w == 2 && h == 1) || (w == 3 && h == 1) || (w == 3 && h == 2) )
			{
				block_array[w][h] = tetris_block_init(BLOCK_TYPE_USER, DARK_ORANGE);
			}
			else
			{
				block_array[w][h] = tetris_block_init(BLOCK_TYPE_EMPTY, LIGHT_GREY);
			}
		}
	}

	Point *centre_point = point_init(2, 1);
	return tetris_piece_init(block_array, centre_point, width, height);
}

TetrisPiece *create_T()
{
	//Standard Tetris Piece is inside a 4x4
	u8 width = 4;
	u8 height = 4;

	TetrisBlock ***block_array;
	block_array = malloc(width * sizeof(void *));
	for (int w=0; w < width; w++)
	{
		block_array[w] = malloc(height * sizeof(void *));
		for (int h=0; h < height; h++)
		{
			if ( (w == 1 && h == 1) || (w == 2 && h == 1) || (w == 3 && h == 1) || (w == 2 && h == 2) )
			{
				block_array[w][h] = tetris_block_init(BLOCK_TYPE_USER, LIGHT_RED);
			}
			else
			{
				block_array[w][h] = tetris_block_init(BLOCK_TYPE_EMPTY, LIGHT_GREY);
			}
		}
	}

	Point *centre_point = point_init(2, 1);
	return tetris_piece_init(block_array, centre_point, width, height);
}
