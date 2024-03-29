#ifndef COLOURS_H_
#define COLOURS_H_

#include <3ds.h>

typedef enum
{
	INVISIBLE,
	WHITE,
	BLACK,
	LIGHT_GREY,
	LIGHT_BLUE,
	DARK_BLUE,
	LIGHT_GREEN,
	DARK_GREEN,
	LIGHT_RED,
	DARK_RED,
	LIGHT_ORANGE,
	DARK_ORANGE
} Colour;


/**
 * @brief Returns the u32 RGBA value for a colour
 *
 * @param colour The colour you want an RGBA value for.
 * @param opacity The opacity of the colour.
 */
extern u32 getColourRGBAValue(Colour colour, s8 opacity);

#endif
