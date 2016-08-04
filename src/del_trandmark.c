#include "fdf.h"

void	del_trandmark(t_win *win, t_origin *my_o)
{
	delete_line(win, my_o->o, my_o->i);
	delete_line(win, my_o->o, my_o->j);
	delete_line(win, my_o->o, my_o->k);
}
