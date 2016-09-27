#include "../include/general/region/region.h"

#include <malloc.h>

struct _Region
{
	Point *top_left_corner;

	u16 width;
	u16 height;
};


Region *region_init(Point *top_left_corner, u16 width, u16 height)
{
	Region *self = malloc(sizeof *self);
	if (!self) return NULL;
	{
		self->top_left_corner = top_left_corner;

		self->width = width;
		self->height = height;
	}

	return self;
}

void region_free(Region *self)
{
	if (self)
	{
		point_free(self->top_left_corner);
		free(self);
	}
}

Point *region_get_top_left_point(Region *self)
{
	return self->top_left_corner;
}

u16 region_get_top_left_x(Region *self)
{
	return point_get_x(self->top_left_corner);
}

u16 region_get_top_left_y(Region *self)
{
	return point_get_y(self->top_left_corner);
}

u16 region_get_width(Region *self)
{
	return self->width;
}

u16 region_get_height(Region *self)
{
	return self->height;
}

void region_set_width(Region *self, u32 width)
{
	self->width = width;
}

void region_set_height(Region *self, u32 height)
{
	self->height = height;
}

void region_set_top_left_corner(Region *self, Point *top_left_corner)
{
	point_free(self->top_left_corner);
	self->top_left_corner = top_left_corner;
}

void region_set_top_left_x(Region *self, u16 x)
{
	Point *new_top_left_corner = point_init(x, point_get_y(self->top_left_corner));

	region_set_top_left_corner(self, new_top_left_corner);
}

void region_set_top_left_y(Region *self, u16 y)
{
	Point *new_top_left_corner = point_init(point_get_x(self->top_left_corner), y);

	region_set_top_left_corner(self, new_top_left_corner);
}
