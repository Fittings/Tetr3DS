#include <malloc.h>
#include "../include/game/block/point.h"



struct _Point
{
	u16 x;
	u16 y;

};
typedef struct _Point Point;







Point *point_init(u16 x, u16 y)
{
	Point *self = malloc(sizeof *self);
	if (!self)
	{
		return NULL;
	}

	{
		self->x = x;
		self->y = y;
	}

	return self;
}


void point_free(Point *self)
{
	if (self)
	{
		free(self);
	}
}


u16 point_get_x(Point *self)
{
	return self->x;
}


u16 point_get_y(Point *self)
{
	return self->y;
}
