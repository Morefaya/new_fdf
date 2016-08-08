#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>

# define X_MAX 1200
# define Y_MAX 600

# define ANGLE_R 0.6
# define UNIT_L 10

# define ESC 53

# define BLACK 0x0
# define WHITE 0xFFFFFF
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define RED 0xFF0000
# define YELLOW 0xFFFF00

typedef struct		s_pos
{
	double		x;
	double		y;
	double		z;
}			t_pos;

typedef struct		s_screen
{
	double		x;
	double		y;
}			t_screen;

typedef struct		s_origin
{
	t_screen	o;
	t_screen	i;
	t_screen	j;
	t_screen	k;
}			t_origin;

typedef struct		s_vect
{
	t_screen	sta;
	t_screen	sto;
}			t_vect;

typedef struct		s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*data;
	int		bpp;
	int		width;
	int		endian;
	double		s_x;
	double		s_y;
	int		**tab;
	int		nb_line;
	int		nb_col;
}			t_win;

int			keyboard(int key, t_win *win);
void			draw_trandmark(t_win *win, t_origin *origin);
void			draw_line(t_win *win, t_screen a, t_screen b);
int			draw(t_win *win);
void			get_pixel(t_pos a, t_origin *origin, t_screen *b);
void			black_screen(t_win *win);
void			delete_line(t_win *win, t_screen a, t_screen b);
void			del_trandmark(t_win *win, t_origin *my_o);
int			count_nb_line(const char *file);
int			count_nb_col(const char *file);
int			**parse(const char *file);

#endif
