/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 16:59:25 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/04 20:05:19 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_put_pixel(t_win *win, int i, int j)
{
	unsigned int	place;
	int		*data_i;

	data_i = (int*)win->data;
	place = j * win->nb_line - (win->nb_col - i);
	if (place >= X_MAX * Y_MAX)
		return;
	data_i[place] = BLUE;
}

void		ft_draw(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (i < win->nb_line)
	{
		j = 0;
		while (j < win->nb_col)
		{
			ft_put_pixel(win, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img, 0, 0);
	ft_putendl("image");
}

int		ft_loop_hook(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img);
	if (!(win->img = mlx_new_image(win->mlx_ptr, X_MAX, Y_MAX)))
	{
		ft_putendl("error new image");
		return (3);
	}
	if (!(win->data = mlx_get_data_addr\
		(win->img, &(win->bpp), &(win->width), &(win->endian))))
	{
		ft_putendl("error get data image");
		return (4);	
	}
	ft_draw(win);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 5, 5, 0xFBFBFB, "fever");
	return (0);
}

int		ft_mouse(int button, int x, int y, t_win *win)
{
	ft_putnbr(button);
	ft_putchar('\n');
	ft_putnbr(x);
	ft_putchar('\t');
	ft_putnbr(y);
	ft_putchar('\n');
	ft_loop_hook(win);
	return (0);
}

int		ft_expose(t_win *win)
{
	ft_draw(win);	
	mlx_string_put(win->mlx_ptr, win->win_ptr, 5, 5, WHITE, "fever");
	return (0);
}

int		ft_key(int keycode, t_win *win)
{
	(void)win;
	if (keycode == 53)
		exit(0);
	ft_loop_hook(win);
	return (0);
}

int		main(void)
{
	t_win	win;

	win.endian = 1;
	win.bpp = 4;
	win.width = X_MAX;
	win.nb_col = X_MAX;
	win.nb_line = Y_MAX;
	if (!(win.mlx_ptr = mlx_init()))
	{
		ft_putendl("error init");
		return (1);
	}
	if (!(win.win_ptr = mlx_new_window(win.mlx_ptr, X_MAX, Y_MAX, "yolo")))
	{
		ft_putendl("error new window");
		return (2);
	}
	if (!(win.img = mlx_new_image(win.mlx_ptr, X_MAX, Y_MAX)))
	{
		ft_putendl("error new image");
		return (3);
	}
	if (!(win.data = mlx_get_data_addr\
		(win.img, &(win.bpp), &(win.width), &(win.endian))))
	{
		ft_putendl("error get data image");
		return (4);	
	}
	mlx_mouse_hook(win.win_ptr, ft_mouse, &win);
	mlx_key_hook(win.win_ptr, ft_key, &win);
	mlx_expose_hook(win.win_ptr, ft_expose, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
