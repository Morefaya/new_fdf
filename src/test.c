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

int		ft_mouse(int button, int x, int y, t_win *win)
{
	(void)win;
	ft_putnbr(button);
	ft_putchar('\n');
	ft_putnbr(x);
	ft_putchar('\t');
	ft_putnbr(y);
	ft_putchar('\n');
	return (0);
}

int		ft_expose(t_win *win)
{
	(void)win;
	mlx_string_put(win->mlx_ptr, win->win_ptr, 5, 5, 0xFBFBFB, "fever");
	return (0);
}

int		ft_key(int keycode, t_win *win)
{
	(void)win;
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(void)
{
	t_win	win;
	void	*img;
	char	*data;
	int		endian = 1;
	int		bpp = 4;
	int		width = X_MAX;

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
	if (!(img = mlx_new_image(win.mlx_ptr, X_MAX, Y_MAX)))
	{
		ft_putendl("error new image");
		return (3);
	}
	if (!(data = mlx_get_data_addr(img, &bpp, &width, &endian)))
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
