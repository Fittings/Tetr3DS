#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include <stdbool.h>

#include "../include/game/game_board/tetris_board.h"
#include "../include/game/block/tetris_block.h"







struct _TetrisBoard
{
	//ZZZ TODO Create an ID enum system

	int width;
	int height;

	TetrisBlock ***block_array; //ZZZ TODO Is this really a triple pointer situation?
};
typedef struct _TetrisBoard TetrisBoard;




TetrisBoard *tetris_board_init(int width, int height)
{
	TetrisBoard *self = malloc(sizeof *self);
	if (!self || width <= 0 || height <= 0)
	{
		return NULL;
	}

	{
		self->width = width;
		self->height = height;

		self->block_array = malloc(width * sizeof(void *));
		for (int w=0; w < width; w++)
		{
			self->block_array[w] = malloc(height * tetris_block_sizeof());
			for (int h=0; h < height; h++)
			{
				self->block_array[w][h] = tetris_block_init(1); //ZZZ TODO use an enum ID here.
			}
		}
	}


	return self;
}


static void free_block_array(TetrisBoard *self)
{
	for (int w=0; w < self->width; w++)
	{
		for (int h=0; h < self->height; h++)
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
	if (x < self->width && y < self->height)
	{

	}

	return false;
}

int i = 0;
//ZZZ TODO Delete. Just to make sure things are going where we are going.
static void bePretty(int i)
{
	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		sf2d_draw_rectangle_rotate(190, 160, 70, 60, RGBA8(0xFF, 0xFF, 0xFF, 0xFF), 3.0* i);
		sf2d_draw_rectangle(30, 100, 40, 60, RGBA8(0xFF, 0x00, 0xFF, 0xFF));
		sf2d_draw_rectangle(160-15 + cosf(i)*50.0f, 120-15 + sinf(i)*50.0f, 30, 30, RGBA8(0x00, 0xFF, 0xFF, 0xFF));
	sf2d_end_frame();

	sf2d_swapbuffers();
}

void tetris_board_render(TetrisBoard *self, int x, int y)
{
	i = i + 2;
	bePretty(i);
}









