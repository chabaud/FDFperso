/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 15:30:11 by schabaud          #+#    #+#             */
/*   Updated: 2016/09/16 14:54:12 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 2560
# define HEIGHT 1440
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "mlx.h"
# include "libft.h"

typedef struct		s_object
{
	int				e;
	int				x;
	int				y;
	int				z;
	int				color;
}					t_object;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				refx;
	int				refy;
	int				refz;
	double			a;
	double			b;
	double			c;
	double			zoom;
	double			zoom_z;
}					t_pos;

typedef struct		s_all
{
	void			*mlx;
	void			*win;
	int				on;
	int				color;
	struct s_object	**object;
	struct s_pos	pos;
}					t_all;

typedef struct		s_p
{
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	int				x;
	int				y;
}					t_p;

typedef struct		s_rot
{
	double			x;
	double			y;
	double			z;
}					t_rot;

int					get_color_hauteur(t_object **object, int i, int k);
static void			c_fdf(char *file);
static void			display_screen(void *mlx, void *win, t_object **object);
void				p_points(void *mlx, void *win,
								t_object **object, t_pos pos);
void				line_tracer(t_all all, t_object pointa, t_object pointb);
static void			line_y(t_all all, t_p p, int color);
static void			line_x(t_all all, t_p p, int color);
t_rot				rotate(t_rot ro, double a, double b, double c);
static t_rot		rotate_rz(int x, int y, int z, double c);
static t_rot		rotate_rx(int x, int y, int z, double a);
t_object			**get_object(char *file);
static int			get_nbr_line(char *file);
static void			get_elem(char *line, t_object **object, int k);
static int			get_elem_ex(char **tmp);
static int			get_color(char *str, t_object **object, int a, int k);
int					mouve_map(int k, t_all *all);
static int			mouve_map_ex(int k, t_all *all);
void				reset(t_all *all);
static int			update_map(void *mlx, void *win,
								t_object **object, t_pos pos);
t_object			*new_line_obj(int k);

#endif
