#include "../include/types/colours.h"

#include <sf2d.h>

u32 getColourRGBAValue(Colour colour, u8 opacity)
{
	u32 colourValue = 0;

	switch (colour)
	{
	case INVISIBLE: colourValue =  RGBA8(0x00, 0x00, 0x00, 0x00); break;

	case WHITE: colourValue =  RGBA8(0xFF, 0xFF, 0xFF, 0xFF); break;

	case BLACK: colourValue = RGBA8(0x25, 0x25, 0x25, 0xFF); break;

	case LIGHT_GREY: colourValue = RGBA8(0xD3, 0xD3, 0xD3, opacity); break;

	case DARK_BLUE: colourValue = RGBA8(0x1F, 0x78, 0xB4, opacity); break;

	case LIGHT_BLUE: colourValue = RGBA8(0xA6, 0xCE, 0xE3, 0xFF); break;

	case LIGHT_GREEN: colourValue = RGBA8(0xB2, 0xDF, 0x8A, opacity); break;

	case DARK_GREEN: colourValue = RGBA8(0x33, 0xA0, 0x2C, opacity); break;

	case LIGHT_RED: colourValue = RGBA8(0xFB, 0x9A, 0x99, opacity); break;

	case DARK_RED: colourValue = RGBA8(0xE3, 0x1A, 0x1C, opacity); break;

	case LIGHT_ORANGE: colourValue = RGBA8(0xFD, 0xBF, 0x6F, opacity); break;

	case DARK_ORANGE: colourValue = RGBA8(0xFE, 0x7F, 0x00, opacity); break;
	}

	return colourValue;
}
