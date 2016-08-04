#include "fdf.h"

void	get_pixel(t_pos a, t_origin *origin, t_screen *b)
{
	b->x = origin->o.x + UNIT_L * (a.x - ANGLE_R * a.z);
	b->y = origin->o.y + UNIT_L * (ANGLE_R * a.z - a.y);
}
