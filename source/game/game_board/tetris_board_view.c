#include "../include/game/game_board/tetris_board_view.h"

#include <malloc.h>
#include "../include/utility/numbers_utility.h"
#include <sf2d.h>
#include "../include/game/game_board/tetris_board_piece.h"


struct _TetrisBoardView
{
	Region *bounded_region;

	Colour board_colour;
};





TetrisBoardView *tetris_board_view_init(Region *max_region, Colour board_colour)
{
	TetrisBoardView *self = malloc(sizeof *self);
	if (!self) return NULL;
	{
		self->bounded_region = max_region;
	}
	return self;
}




void tetris_board_view_free(TetrisBoardView *self)
{
	if (self)
	{
		region_free(self->bounded_region);
		free(self);
	}
}


/*
 * Calculates the block size based on the views max region.
 */
static u16 calculate_block_size(TetrisBoardView *self, TetrisBoard *board)
{
	u16 max_width_px = region_get_width(self->bounded_region);
	u16 max_height_px = region_get_height(self->bounded_region);


	//Calculate Block Size
	u16 block_length = min((max_width_px / tetris_board_get_width(board)), (max_height_px / tetris_board_get_height(board)));
	block_length = block_length <= 2 ? 2 : block_length; //Enforce blocks are always 2px, so they are always distinguisable.

	return block_length;
}

/*
 * The board automatically re-adjusts the render region based on the max region and the block size.
 * This calculates the actual board region with the correct x,y and width/height
 */
static Point *calculate_board_render_start_point(TetrisBoardView *self, TetrisBoard *board, u16 block_size)
{
	u16 max_width_px = region_get_width(self->bounded_region);
	u16 max_height_px = region_get_height(self->bounded_region);
	u16 max_top_left_x_px = region_get_top_left_x(self->bounded_region);
	u16 max_top_left_y_px = region_get_top_left_y(self->bounded_region);

	int actual_width = block_size * tetris_board_get_width(board);
	int start_x = (actual_width > max_width_px) ? max_width_px - actual_width : max_top_left_x_px + ((max_width_px - actual_width)/2);

	int actual_height = block_size * tetris_board_get_height(board);
	int start_y = (actual_height > max_height_px) ? max_height_px - actual_height : max_top_left_y_px + ((max_height_px - actual_height)/2);

	return region_init(point_init(start_x, start_y), actual_width, actual_height);
}





/*
 * Re-calculates the Region based on the board size.
 * Centres the board inside of the max_region and returns this new region.
 */
void tetris_board_view_draw(TetrisBoardView *self, TetrisBoard *board, TetrisBoardPiece *board_piece)
{
	u16 block_size = calculate_block_size(self, board);
	Point *top_left_corner = calculate_board_render_start_point(self, board, block_size);

	tetris_board_draw(board, point_get_x(top_left_corner), point_get_y(top_left_corner), block_size);

	if (board_piece != NULL)
	{
		tetris_board_piece_draw(board_piece, point_get_x(top_left_corner), point_get_y(top_left_corner), block_size);
	}
}
