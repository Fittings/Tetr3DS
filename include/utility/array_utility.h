#ifndef INCLUDE_UTILITY_ARRAY_H_
#define INCLUDE_UTILITY_ARRAY_H_

#include <3ds.h>

extern void ***array2d_array_rotate_right_angle(void ***array, u32 width, u32 height, u8 rotations);

extern void ***array2d_create_empty(u32 width, u32 height);

extern void ***array_2d_copy(void ***array, u32 width, u32 height);



#endif
