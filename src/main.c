#include "fdf.h"

static void	gt_screen_size(const char *file, int **tab, t_screen *screen_size)
{
	int	nb_line;
	int	nb_col;
	int	max;
	int	min;
	int	j;
	int	i;

	nb_line = count_nb_line(file);
	nb_col = count_nb_col(file);
	max = 0;
	min = 0;
	i = 0;
	while (i < nb_line)
	{
		j = 0;
		while (j < nb_col)
		{
			max = (tab[i][j] > max) ? tab[i][j] : max;
			min = (tab[i][j] < min) ? tab[i][j] : min;
			j++;
		}
		i++;
	}
	screen_size->x = X_MAX + nb_col * 10 + (max - min) * 4;
	screen_size->y = Y_MAX + nb_line * 5 + (max - min) * 2;
	ft_putnbr(nb_col);
	ft_putchar('\t');
	ft_putnbr(nb_line);
	ft_putchar('\t');
	ft_putnbr(max - min);
}

static void	print_tab(int **tab, const char *file)
{
	int	nb_line;
	int	nb_col;
	int	i;
	int	j;

	i = 0;
	nb_line = count_nb_line(file);
	nb_col = count_nb_col(file);
	while (i < nb_line)
	{
		j = 0;
		while (j < nb_col)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(int ac, char **av)
{
	t_win		win;
	int		**tab;
	t_screen	s_size;

	if (ac != 2)
	{
		ft_putendl("usage : fdf [file]");
		exit(1);
	}
	if (!(tab = parse(av[1])))
	{
		ft_putendl("error parse");
		return (1);
	}
	print_tab(tab, av[1]);
	gt_screen_size(av[1], tab, &s_size);
	if (!(win.mlx_ptr = mlx_init()))
	{
		ft_putstr("error init");
		return (2);
	}
	if (!(win.win_ptr = mlx_new_window(win.mlx_ptr, s_size.x, s_size.y, "yolo")))
	{
		ft_putstr("error new window");
		return (3);
	}
	win.tab = tab;
	win.s_x = s_size.x;
	win.s_y = s_size.y;
	win.nb_line = count_nb_line(av[1]);
	win.nb_col = count_nb_col(av[1]);
	mlx_expose_hook(win.win_ptr, draw, &win);
	mlx_key_hook(win.win_ptr, keyboard, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
