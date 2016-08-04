#include "fdf.h"

void	black_screen(t_win *win)
{
	t_screen	i;

	i.x = 0;
	i.y = 0;
	while (i.y < Y_MAX)
	{
		i.x = 0;
		while (i.x < X_MAX)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, i.x, i.y, BLACK);
			i.x++;
		}
		i.y++;
	}
}
