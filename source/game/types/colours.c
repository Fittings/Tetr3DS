#include "../include/types/colours.h"

u32 getColourRGBAValue(Colour colour, u8 opacity)
{
	u32 colourValue = 0;
	switch (colour) {
	LIGHT_BLUE:
		colourValue = RGBA8(0xA6, 0xCE, 0xE3, opacity);
	DARK_BLUE:
		colourValue = RGBA8(0x1F, 0x78, 0xB4, opacity);
	LIGHT_GREEN:
		colourValue = RGBA8(0xB2, 0xDF, 0x8A, opacity);
	DARK_GREEN:
		colourValue = RGBA8(0x33, 0xA0, 0x2C, opacity);
	LIGHT_RED:
		colourValue = RGBA8(0xFB, 0x9A, 0x99, opacity);
	DARK_RED:
		colourValue = RGBA8(0xE3, 0x1A, 0x1C, opacity);
	LIGHT_ORANGE:
		colourValue = RGBA8(0xFD, 0xBF, 0x6F, opacity);
	DARK_ORANGE:
		colourValue = RGBA8(0xFE, 0x7F, 0x00, opacity);
	}

	return colourValue;
}
