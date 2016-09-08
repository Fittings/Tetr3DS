#include "../include/utility/array_utility.h"




void ***rotate_2d_array(void ***old_array, int old_width, int old_height)
{
	void ***new_array = malloc(old_height * sizeof(void *));

	for (int i=0; i < old_height; i++)
	{
		new_array[i] = malloc(old_width * sizeof(void *));

		for (int j=0; j < old_width; j++)
		{
			new_array[i][j] = old_array[j][i];
		}
	}

	return new_array;
}

