#ifndef INCLUDE_GAME_REGION_H_
#define INCLUDE_GAME_REGION_H_

#include <3ds.h>
#include "../include/game/block/point.h"

typedef struct _Region Region;


extern Region *region_init(Point *top_left_corner, s16 width, s16 height);
extern void region_free(Region *self);


extern Point *region_get_top_left_point(Region *self);
extern s16 region_get_top_left_x(Region *self);
extern s16 region_get_top_left_y(Region *self);

extern s16 region_get_width(Region *self);
extern s16 region_get_height(Region *self);


extern void region_set_width(Region *self, u32 width);
extern void region_set_height(Region *self, u32 height);

extern void region_set_top_left_corner(Region *self, Point *top_left_corner);
extern void region_set_top_left_x(Region *self, s16 x);
extern void region_set_top_left_y(Region *self, s16 y);


#endif
