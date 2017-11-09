/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 15:24:56 by schabaud          #+#    #+#             */
/*   Updated: 2016/09/16 14:53:49 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void		display_screen(void *mlx, void *win, t_object **object)
{
	t_all		all;

	all.mlx = mlx;
	all.win = win;
	all.object = object;
	reset(&all);
	p_points(mlx, win, object, all.pos);
	mlx_hook(win, 2, 1L << 01, mouve_map, &all);
	mlx_loop(mlx);
}

static void		c_fdf(char *file)
{
	void		*mlx;
	t_object	**object;
	void		*win;

	object = NULL;
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "*>>>FDF<<<*");
	object = get_object(file);
	display_screen(mlx, win, object);
	free(mlx);
	free(win);
}

int				main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("No File\n");
	else if (argc == 2)
		if (open(argv[1], O_RDONLY) == -1)
			ft_putstr("Try another File\n");
		else
			c_fdf(argv[1]);
	else
		ft_putstr("Only one file\n");
	return (0);
}
