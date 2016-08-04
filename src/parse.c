#include "fdf.h"

static int	**make_tab(int nb_col, int nb_line)
{
	int	**tab;
	int	i;

	i = 0;
	if (!(tab = (int**)malloc(sizeof(*tab) * nb_line)))
		return (NULL);
	while (i < nb_line)
	{
		if (!(tab[i] = (int*)malloc(sizeof(**tab) * nb_col)))
		{
			i--;
			while (i >= 0)
			{
				free(tab[i]);
				i--;
			}
			return (NULL);
		}
		i++;
	}
	return (tab);
}

static void	get_column(int *tab, char *line, int nb_col)
{
	int	i;
	char	**col;

	i = 0;
	if (!(col = ft_strsplit(line, ' ')))
		return;
	while (i < nb_col)
	{
		tab[i] = ft_getnbr(col[i]);
		i++;
	}
	i = 0;
	while (i < nb_col)
	{
		free(col[i]);
		i++;
	}
	free(col);
}

static void	get_data(const char *file, int **tab, int nb_col, int nb_line)
{
	int	j;
	char	*line;
	int	fd;

	j = 0;
	line = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		return;
	while (j < nb_line)
	{
		get_next_line(fd, &line);
		get_column(tab[j], line, nb_col);
		free(line);
		j++;
	}
	close(fd);
}

int	**parse(const char *file)
{
	int	**tab;
	int	nb_col;
	int	nb_line;

	if (!(nb_col = count_nb_col(file))
		|| !(nb_line = count_nb_line(file)))
		return (NULL);
	if (!(tab = make_tab(nb_col, nb_line)))
		return (NULL);
	get_data(file, tab, nb_col, nb_line);
	return (tab);
}
