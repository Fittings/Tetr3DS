#include "../include/utility/array_utility.h"

//Implementation Specific Imports
#include <malloc.h>


static void ***array2d_array_transpose(void ***array, u32 width, u32 height)
{
	void ***new_array = array2d_create_empty(height, width);

	for (int w=0; w < width; w++)
	{
		for (int h=0; h < height; h++)
		{
			new_array[h][w] = array[w][h];
		}
	}

	return new_array;
}


static void array2d_verticle_in_place_reflect(void ***array, u32 width, u32 height)
{
	void *temp;
	for (int h=0; h < height/2; h++)
	{
		for (int w=0; w < width; w++)
		{
			temp = array[w][h];
			array[w][h] = array[w][height - (h+1)];
			array[w][height - (h+1)] = temp;
		}
	}
}

static void array2d_horizontal_in_place_reflect(void ***array, u32 width, u32 height)
{
	void *temp;
	for (int w=0; w < width/2; w++)
	{
		for (int h=0; h < height; h++)
		{
			temp = array[w][h];
			array[w][h] = array[width - (w+1)][h];
			array[width - (w+1)][h] = temp;
		}
	}
}


static void ***array2d_array_rotate90(void ***array, u32 width, u32 height)
{
	void ***new_array = array2d_array_transpose(array, width, height);
	array2d_horizontal_in_place_reflect(new_array, width, height);

	return new_array;
}

static void ***array2d_array_rotate180(void ***array, u32 width, u32 height)
{
	void ***new_array = array_2d_copy(array, width, height);

	array2d_horizontal_in_place_reflect(new_array, width, height);
	array2d_verticle_in_place_reflect(new_array, width, height);

	return new_array;
}

static void ***array2d_array_rotate270(void ***array, u32 width, u32 height)
{
	void *** new_array = array2d_array_transpose(array, width, height);
	array2d_verticle_in_place_reflect(new_array, width, height);

	return new_array;
}



void ***array2d_array_rotate_right_angle(void ***array, u32 width, u32 height, u8 rotations)
{
	switch (rotations % 4)
	{
	case 3:
		return array2d_array_rotate270(array, width, height);
	case 2:
		return array2d_array_rotate180(array, width, height);
	case 1:
		return array2d_array_rotate90(array, width, height);
	case 0:
	default:
		return array_2d_copy(array, width, height);
	}
}


void ***array2d_create_empty(u32 width, u32 height)
{
	void ***array = malloc(width * sizeof(void*));

	for (int w=0; w < width; w++)
	{
		array[w] = malloc(height * sizeof(void*));

		for (int h=0; h < height; h++)
		{
			array[w][h] = malloc(sizeof(void*));
		}
	}

	return array;
}

void ***array_2d_copy(void ***array, u32 width, u32 height)
{
	void ***new_array = malloc(width * sizeof(void*));

	for (int w=0; w < width; w++)
	{
		new_array[w] = malloc(height * sizeof(void*));

		for (int h=0; h < height; h++)
		{
			new_array[w][h] = array[w][h];
		}
	}

	return new_array;
}

