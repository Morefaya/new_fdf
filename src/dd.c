#include "fdf.h"

/*static double	put_line(t_win *win, t_screen a, t_screen b)
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
}*/

static void	bzero_vect(t_vect *vect)
{
	vect->start.x = 0.;
	vect->start.y = 0.;
	vect->stop.x = 0.;
	vect->stop.y = 0.;
}

static void	choose_vect(t_screen a, t_screen b, t_vect *vect)
{
	bzero_vect(vect);
	if (a.x > b.x || (a.y < b.y && a.x == b.x))
	{
		vect->sta.x = a.x;
		vect->sta.y = a.y;
		vect->sto.x = b.x;
		vect->sto.y = b.y;
	}
	else if (a.x < b.x || (a.y < b.y && a.x == b.x))
	}
		vect->sta.x = b.x;
		vect->sta.y = b.y;
		vect->sto.x = a.x;
		vect->sto.y = a.y;
	}
}

static void	ddraw_line(t_win *win, t_vect v)
{
	while (v.sta.x != v.sto.x && v.sta.y != v.sto.y)
	{
		if (v.sta.x - v.sto.x > v.sta.y - v.sto.y)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, v.sta.x, v.sta.y, BLUE);
		}
	}
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
