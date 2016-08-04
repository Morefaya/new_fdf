#include "fdf.h"

void	draw_trandmark(t_win *win, t_origin *my_o)
{
	draw_line(win, my_o->o, my_o->i);
	draw_line(win, my_o->o, my_o->j);
	draw_line(win, my_o->o, my_o->k);
}
