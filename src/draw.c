#include "fdf.h"
#include <stdlib.h>

/*static void	trans_o(t_origin *my_o, t_screen next_pos)
{
	my_o->o.x = next_pos.x;
	my_o->o.y = next_pos.y;
	my_o->i.x = my_o->o.x + UNIT_L;
	my_o->i.y = my_o->o.y;
	my_o->j.x = my_o->o.x;
	my_o->j.y = my_o->o.y - UNIT_L;
	my_o->k.x = my_o->o.x - UNIT_L * ANGLE_R;
	my_o->k.y = my_o->o.y + UNIT_L * ANGLE_R;
}*/

static t_origin	*gt_origin(t_win * win)
{
	t_origin	*my_o;

	if (!(my_o = (t_origin*)malloc(sizeof(*my_o))))
	{
		ft_putstr("error malloc origin");
		exit(1);
	}
	my_o->o.x = win->s_x / 3;
	my_o->o.y = win->s_y / 3;
	my_o->i.x = my_o->o.x + UNIT_L;
	my_o->i.y = my_o->o.y;
	my_o->j.x = my_o->o.x;
	my_o->j.y = my_o->o.y - UNIT_L;
	my_o->k.x = my_o->o.x - UNIT_L * ANGLE_R;
	my_o->k.y = my_o->o.y + UNIT_L * ANGLE_R;
	return (my_o);
}

/*static void	draw_point(t_win *win, t_origin *my_o)
{
	int		i;
	int		j;
	t_pos		cod;
	t_screen	p;

	i = 0;
	while (i < win->nb_line)
	{
		j = 0;
		while (j < win->nb_col)
		{
			cod.x = j;
			cod.z = i;
			cod.y = win->tab[i][j];
			get_pixel(cod, my_o, &p);
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, p.x, p.y, YELLOW);
			j++;
		}
		i++;
	}
}*/

static void	next_fdf(t_win *win, t_pos pos, t_origin *my_o)
{	
	t_screen	o;
	t_screen	left;
	t_screen	down;

	get_pixel(pos, my_o, &o);
	pos.x++;
	pos.y = win->tab[(int)pos.z][(int)pos.x];
	get_pixel(pos, my_o, &left);
	draw_line(win, o, left);
	pos.x--;
	pos.z++;
	pos.y = win->tab[(int)pos.z][(int)pos.x];
	get_pixel(pos, my_o, &down);
	draw_line(win, o, down);
}

static void	draw_fdf(t_win *win, t_origin *my_o)
{
	int		i;
	int		j;
	t_pos		pos;

	i = 0;
	while (i < win->nb_line - 1)
	{
		j = 0;
		while (j < win->nb_col - 1)
		{
			pos.x = j;
			pos.z = i;
			pos.y = win->tab[i][j];
			next_fdf(win, pos, my_o);
			j++;
		}
		i++;
	}
}

int	draw(t_win *win)
{
	t_origin	*my_o;

	my_o = gt_origin(win);
//	draw_point(win, my_o);
	draw_fdf(win, my_o);
	free(my_o);
	return (0);
}
