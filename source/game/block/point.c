#include <malloc.h>
#include "../include/game/block/point.h"



struct _Point
{
	s16 x;
	s16 y;

};
typedef struct _Point Point;







Point *point_init(s16 x, s16 y)
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


s16 point_get_x(Point *self)
{
	return self->x;
}


s16 point_get_y(Point *self)
{
	return self->y;
}
