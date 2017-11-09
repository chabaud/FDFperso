/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:11:08 by schabaud          #+#    #+#             */
/*   Updated: 2016/09/16 14:53:36 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			p_points(void *mlx, void *win, t_object **object, t_pos pos)
{
	int		i;
	int		j;
	t_all	all;

	j = -1;
	all.mlx = mlx;
	all.win = win;
	all.pos = pos;
	while (object[++j])
	{
		i = -1;
		while (object[j][++i].e && object[j][i + 1].e)
			line_tracer(all, object[j][i], object[j][i + 1]);
	}
	j = 0;
	i = -1;
	while (object[j][++i].e)
	{
		j = 0;
		while (object[j] && object[j + 1])
		{
			line_tracer(all, object[j][i], object[j + 1][i]);
			++j;
		}
	}
}

static t_rot	rotate_rx(int x, int y, int z, double a)
{
	t_rot		ro;

	ro.x = x;
	ro.y = (y * cos(a)) - (z * sin(a));
	ro.z = (y * sin(a)) + (z * cos(a));
	return (ro);
}

static t_rot	rotate_ry(int x, int y, int z, double b)
{
	t_rot		ro;

	ro.x = (x * cos(b)) + (z * sin(b));
	ro.y = y;
	ro.z = -(x * sin(b)) + (z * cos(b));
	return (ro);
}

static t_rot	rotate_rz(int x, int y, int z, double c)
{
	t_rot		ro;

	ro.x = (x * cos(c)) + (y * sin(c));
	ro.y = -(x * sin(c)) + (y * cos(c));
	ro.z = z;
	return (ro);
}

t_rot			rotate(t_rot ro, double a, double b, double c)
{
	ro = rotate_rx(ro.x, ro.y, ro.z, a);
	ro = rotate_ry(ro.x, ro.y, ro.z, b);
	ro = rotate_rz(ro.x, ro.y, ro.z, c);
	return (ro);
}
