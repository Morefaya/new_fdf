#include "fdf.h"

static double	put_line(t_win *win, t_screen a, t_screen b)
{
	t_pos	i;
	double	d;
	double	e;
	double	aux;

	
	d = (a.y - b.y) / (a.x - b.x);
	e = a.y - d * a.x;
	i.x = (a.x < b.x) ? a.x : b.x;
	aux = d * i.x + e;
	while (i.x < ((a.x < b.x) ? b.x : a.x))
	{
		i.y = d * i.x + e;
		if (aux < i.y)
			while (aux < i.y)
			{
				mlx_pixel_put(win->mlx_ptr, win->win_ptr, i.x, aux, BLUE);
				aux++;
			}
		else
			while (aux > i.y)
			{
				mlx_pixel_put(win->mlx_ptr, win->win_ptr, i.x, aux, BLUE);
				aux--;
			}
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, i.x, i.y, BLUE);
		i.x++;
	}
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, a.x, a.y, BLUE);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, b.x, b.y, BLUE);
	return (d);
}

static double	put_line_x(t_win *win, t_screen a, t_screen b)
{
	t_pos	i;

	i.x = a.x;
	i.y = (a.y <= b.y) ? a.y : b.y;
	while (i.y < ((a.y < b.y) ? b.y : a.y))
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, i.x, i.y, BLUE);
		i.y++;
	}
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, a.x, a.y, RED);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, b.x, b.y, GREEN);
	return (0.);
}

void		draw_line(t_win *win, t_screen a, t_screen b)
{
	if (a.x != b.x)
		put_line(win, a, b);
	else
		put_line_x(win, a, b);
}
