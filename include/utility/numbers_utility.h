/**
 * @file numbers_utility.h
 * @author Cameron Milsom
 * @brief Utility functions relating to numbers
 *
 * Utility class with functions that are useful for numbers.
 */
#ifndef INCLUDE_UTILITY_NUMBERS_UTILITY_H_
#define INCLUDE_UTILITY_NUMBERS_UTILITY_H_

/** Calculates the max of two numbers */
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

/** Calculates the min of two numbers */
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })


//ZZZ TODO Delete this.
extern void bePretty(int i)
{
	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
	sf2d_draw_rectangle_rotate(190, 160, 70, 60, RGBA8(0xFF, 0xFF, 0xFF, 0xFF), 3.0* i);
		sf2d_draw_rectangle(30, 100, 2, 2, RGBA8(0xFF, 0x00, 0xFF, 0xFF));
		sf2d_draw_rectangle(160-15 + cosf(i)*50.0f, 120-15 + sinf(i)*50.0f, 30, 30, RGBA8(0x00, 0xFF, 0xFF, 0xFF));

		sf2d_end_frame();
		sf2d_swapbuffers();

}


#endif
