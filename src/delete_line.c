#include "fdf.h"

static double	del_line(t_win *win, t_screen a, t_screen b)
{
	t_pos	i;
	double	d;
	double	e;

	d = (a.y - b.y) / (a.x - b.x);
	e = a.y - d * a.x;
	i.x = (a.x < b.x) ? a.x : b.x;
	while (i.x < ((a.x < b.x) ? b.x : a.x))
	{
		i.y = d * i.x + e;
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, i.x, i.y, BLACK);
		i.x++;
	}
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, b.x, b.y, BLACK);
	return (d);
}

static double	del_line_x(t_win *win, t_screen a, t_screen b)
{
	t_pos	i;

	i.x = a.x;
	i.y = (a.y <= b.y) ? a.y : b.y;
	while (i.y < ((a.y < b.y) ? b.y : a.y))
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, i.x, i.y, BLACK);
		i.y++;
	}
	return (0.);
}

void		delete_line(t_win *win, t_screen a, t_screen b)
{
	if (a.x != b.x)
		del_line(win, a, b);
	else
		del_line_x(win, a, b);
}
