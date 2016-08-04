#include "fdf.h"

int		count_nb_line(const char *file)
{
	int	nb_line;
	char	*line;
	int	fd;

	nb_line	= 0;
	line = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putendl(strerror(errno));
		return (0);
	}
	while (get_next_line(fd, &line))
	{
		nb_line++;
		free(line);
	}
	free(line);
	close(fd);
	return (nb_line);
}

static int	nb_colcmp(int fd, char **line)
{
	int	nb_col;
	int	tmp;
	char	**tab;

	nb_col = 0;
	while (get_next_line(fd, line))
	{
		tmp = 0;
		if (!(tab = ft_strsplit(*line, ' ')))
			return (-1);
		while (tab[tmp])
		{
			free(tab[tmp]);
			tmp++;
		}
		if ((tmp > nb_col && !nb_col) || (tmp < nb_col && nb_col != 0))
			nb_col = tmp;
		free(*line);
		free(tab);
	}
	ft_putnbr(nb_col);
	return (nb_col);
}

int		count_nb_col(const char *file)
{
	int	fd;
	char	*line;
	int	nb_col;

	line = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putendl(strerror(errno));
		return (0);
	}
	nb_col = nb_colcmp(fd, &line);
	close(fd);
	return (nb_col);
}
