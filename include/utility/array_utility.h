#ifndef INCLUDE_UTILITY_ARRAY_H_
#define INCLUDE_UTILITY_ARRAY_H_

#include <3ds.h>

/**
 * @brief Rotates the 2d array by the amount of rotations.
 *
 * Rotates the 2d array by 90 degrees by the amount of rotations specified.
 * Returns a new array, the original array is un-changed.
 *
 * @param array The non-rotated 2d array.
 * @param width The width of the 2d array.
 * @param height The height of the 2d array.
 * @param rotations The amount of 90 degree rotations to do.
 */
extern void ***array2d_array_rotate_right_angle(void ***array, u32 width, u32 height, u8 rotations);


/**
 * @brief Creates a 2d array of void pointers.
 *
 * Creates a 2d array of width x height of void pointers.
 *
 * @param width The width of the 2d array.
 * @param height The height of the 2d array.
 * @return An empty 2d array of size width x height
 */
extern void ***array2d_create_empty(u32 width, u32 height);

/**
 * @brief Shallow copies a 2d array.
 *
 * Creates a shallow copy of an array of width x height.
 * All pointers will point to the same data as the old array.
 *
 * @param width The width of the 2d array.
 * @param height The height of the 2d array.
 * @return An copied 2d array of size width x height
 */
extern void ***array_2d_copy(void ***array, u32 width, u32 height);



#endif
