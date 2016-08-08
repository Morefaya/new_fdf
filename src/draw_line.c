#include "fdf.h"

typedef struct	s_calc
{
	int			dx;
	int			dy;
	int			div_xy;
	int			rest_xy;
	int			coef;
}				t_calc;

static void	put_line(t_win *win, t_screen a, t_screen b)
{
	t_calc	cc;

	(void)win;
	cc.dx = b.x - a.x;
	cc.dy = b.y - a.y;
	cc.div_xy = cc.dy / cc.dx;
	cc.rest_xy = cc.dy % cc.dx;
	cc.coef = cc.div_xy;
	if (ft_abs(cc.dx) / 2 > cc.rest_xy)
		cc.coef = (cc.dx < 0) ? -1 * cc.coef : cc.coef;
	/*ft_putnbr(cc.dx);
	ft_putchar('\n');
	ft_putnbr(cc.dy);
	ft_putchar('\n');
	ft_putnbr(cc.div_xy);
	ft_putchar('\n');
	ft_putnbr(cc.rest_xy);
	ft_putchar('\n');*/
	ft_putnbr(cc.coef);
	ft_putchar('\n');
}

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
				put_pixel(win, i.x, aux, BLUE);
				aux++;
			}
		else
			while (aux > i.y)
			{
				put_pixel(win, i.x, aux, BLUE);
				aux--;
			}
			//put_pixel(win, i.x, i.y, GREEN);
		i.x++;
	}
	put_pixel(win, a.x, a.y, RED);
	put_pixel(win, b.x, b.y, RED);
	return (d);
}

static double	put_line_x(t_win *win, t_screen a, t_screen b)
{
	t_pos	i;

	i.x = a.x;
	i.y = (a.y <= b.y) ? a.y : b.y;
	while (i.y < ((a.y < b.y) ? b.y : a.y))
	{
		put_pixel(win, i.x, i.y, BLUE);
		i.y++;
	}
	put_pixel(win, a.x, a.y, RED);
	put_pixel(win, b.x, b.y, RED);
	return (0.);
}*/

void		draw_line(t_win *win, t_screen a, t_screen b)
{
	if (a.x != b.x)
		put_line(win, a, b);
	/*else
		put_line_x(win, a, b);
	(void)a;
	(void)b;
	unsigned long	place = X_MAX;
	unsigned long	i = 0;
	while (i < place)
	{
		put_pixel(win, i, i, RED);
		i++;
	}*/
}
