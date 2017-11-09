/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 14:38:01 by schabaud          #+#    #+#             */
/*   Updated: 2016/09/16 14:55:33 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_color_hauteur(t_object **object, int i, int k)
{
	char	*tmp;
	char	*color;

	if (object[k][i].z >= 0 && object[k][i].z <= 2)
		return (0x004E96C7);
	else if (object[k][i].z >= 3 && object[k][i].z <= 6)
		return (0x006BB83E);
	else if (object[k][i].z >= 7 && object[k][i].z <= 15)
		return (0x00967E53);
	else if (object[k][i].z >= 16 && object[k][i].z <= 40)
		return (0x006B5733);
	else if (object[k][i].z >= 41 && object[k][i].z <= 70)
		return (0x00362B18);
	else if (object[k][i].z >= 71)
		return (0x00FFFFFF);
	else if (object[k][i].z <= -15)
		return (0x00041366);
	else if (object[k][i].z <= -1)
		return (0x001028B3);
	else if (object[k][i].z <= 0)
		return (0x004E96C7);
	else
		return (0x00FFFFFF);
	return (0);
}

static int	update_map(void *mlx, void *win, t_object **object, t_pos pos)
{
	mlx_clear_window(mlx, win);
	p_points(mlx, win, object, pos);
	return (0);
}

void		reset(t_all *all)
{
	all->pos.x = 1280;
	all->pos.y = 740;
	all->pos.refx = 0;
	all->pos.refy = 0;
	all->pos.refz = 0;
	all->pos.a = 0;
	all->pos.a = 0;
	all->pos.b = 0;
	all->pos.c = 0;
	all->pos.zoom = 10;
	all->pos.zoom_z = 1;
}

static int	mouve_map_ex(int k, t_all *all)
{
	if (k == 0)
		all->pos.x -= 10;
	else if (k == 1)
		all->pos.y += 10;
	else if (k == 2)
		all->pos.x += 10;
	else if (k == 87)
		reset(all);
	else if (k == 53)
		exit(0);
	else if (k == 15)
		all->pos.refx -= 1;
	else if (k == 17)
		all->pos.refx += 1;
	else if (k == 3)
		all->pos.refy -= 1;
	else if (k == 5)
		all->pos.refy += 1;
	else if (k == 8)
		all->pos.refz -= 1;
	else if (k == 9)
		all->pos.refz += 1;
	else
		return (0);
	return (update_map(all->mlx, all->win, all->object, all->pos));
}

int			mouve_map(int k, t_all *all)
{
	if (k == 69)
		all->pos.zoom++;
	else if (k == 78)
		all->pos.zoom--;
	else if (k == 126)
		all->pos.a += 0.05;
	else if (k == 125)
		all->pos.a -= 0.05;
	else if (k == 12)
		all->pos.c += 0.05;
	else if (k == 14)
		all->pos.c -= 0.05;
	else if (k == 124)
		all->pos.b += 0.05;
	else if (k == 123)
		all->pos.b -= 0.05;
	else if (k == 34)
		all->pos.zoom_z++;
	else if (k == 32)
		all->pos.zoom_z--;
	else if (k == 13)
		all->pos.y -= 10;
	else
		return (mouve_map_ex(k, all));
	return (update_map(all->mlx, all->win, all->object, all->pos));
}
