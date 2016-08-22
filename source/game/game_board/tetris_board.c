#include <malloc.h>
#include <stdbool.h>
#include <sf2d.h>
#include <stdbool.h>

#include "../include/game/game_board/tetris_board.h"
#include "../include/game/block/tetris_block.h"

//ZZZ TODO Move to a utility class.
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })



struct _TetrisBoard
{
	//ZZZ TODO Create an ID enum system

	int block_width;
	int block_height;

	TetrisBlock ***block_array; //ZZZ TODO Is this really a triple pointer situation?
};
typedef struct _TetrisBoard TetrisBoard;


static void beScary()
{
	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
	sf2d_draw_rectangle(0, 0, 400, 320, RGBA8(0xFF, 0x00, 0x00, 0xCC));
		sf2d_end_frame();
		sf2d_swapbuffers();

}

static void bePleasant()
{
	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		sf2d_draw_rectangle(0, 0, 400, 320, RGBA8(0x00, 0xFF, 0x00, 0xCC));


		sf2d_end_frame();
		sf2d_swapbuffers();
}

int i = 0;
//ZZZ TODO Delete. Just to make sure things are going where we are going.
static void bePretty(int i)
{
	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
	sf2d_draw_rectangle_rotate(190, 160, 70, 60, RGBA8(0xFF, 0xFF, 0xFF, 0xFF), 3.0* i);
		sf2d_draw_rectangle(30, 100, 2, 2, RGBA8(0xFF, 0x00, 0xFF, 0xFF));
		sf2d_draw_rectangle(160-15 + cosf(i)*50.0f, 120-15 + sinf(i)*50.0f, 30, 30, RGBA8(0x00, 0xFF, 0xFF, 0xFF));

		sf2d_end_frame();
		sf2d_swapbuffers();

}

TetrisBoard *tetris_board_init(int block_width, int block_height)
{
	TetrisBoard *self = malloc(sizeof *self);
	if (!self || block_width <= 0 || block_height <= 0)
	{
		beScary();
		return NULL;
	}

	{
		self->block_width = block_width;
		self->block_height = block_height;

		self->block_array = malloc(block_width * sizeof(void *));
		for (int w=0; w < block_width; w++)
		{
			self->block_array[w] = malloc(block_height * tetris_block_sizeof());
			for (int h=0; h < block_height; h++)
			{
				//bePretty(h); //ZZZ TODO Kill me
				self->block_array[w][h] = tetris_block_init(h % 2); //ZZZ TODO use an enum ID here.
			}
		}
	}

	/*
	//ZZZ TODO Kill me
	for (int x=0; x < 100; x++)
	{
		beScary();
	} */


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



void tetris_board_render(TetrisBoard *self, int x, int y, int pixel_width, int pixel_height)
{

	/*
	for (int y=0; y < 150; y++)
	{
		bePleasant();
	} */

	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);

	int block_length = min((pixel_width / self->block_width), (pixel_height / self->block_height));
	block_length = block_length <= 0 ? 1 : block_length; //Blocks are always at least 1px

	int total_height = block_length * self->block_height;
	int total_width = block_length * self->block_width;
	int start_y = y - total_width;
	int start_x = x - total_height;

	int render_width = start_x;
	for (int w=0; w < self->block_width; w++)
	{
		int render_height = start_y;
		for (int h=0; h < self->block_height; h++)
		{
			if (h % 2 == 0)
			{
				sf2d_draw_rectangle(render_width, render_height, block_length, block_length, RGBA8(0xBB, 0xBB, 0x00, 0xCC)); //ZZZ TODO Colours
			}
			else
			{
				sf2d_draw_rectangle(render_width, render_height, block_length, block_length, RGBA8(0x00, 0xBB, 0xBB, 0xCC)); //ZZZ TODO Colours
			}
			render_height = render_height + (h * block_length);
			//tetris_block_render(self->block_array[w][h], render_width, render_height, block_length);

			//sf2d_draw_rectangle_rotate(block_length, block_length, block_length, block_length, RGBA8(0xFF, 0xFF, 0xFF, 0xFF), 3.0* w);
			//sf2d_draw_rectangle(160-15 + cosf(w)*50.0f, 120-15 + sinf(i)*50.0f, 30, 30, RGBA8(0x00, 0xFF, 0xFF, 0xFF));
		}
		render_width = render_width + (w * block_length);
	}

	sf2d_end_frame();
	sf2d_swapbuffers();

	/*
	//ZZZ TODO kill me
	for (int y=0; y < 300; y++)
	{
		beScary();
	} */

}









