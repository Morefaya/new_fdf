#include "fdf.h"

int      keyboard(int key, t_win *win)
{
	if (key == 53)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		exit(0);
	}
	else
		ft_putnbr(key);
		ft_putchar('\n');
	return (0);
}
